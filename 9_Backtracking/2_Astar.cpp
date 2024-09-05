#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_set>

using namespace std;

// Structure for a point or cell in the grid
struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Structure for a cell in the grid for A* search
struct Cell {
    Point parent;
    double f, g, h;
    Cell() : parent(-1, -1), f(-1), g(-1), h(-1) {}
};

// Check if the given cell is within the grid boundaries
bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0) && (x < rows) && (y >= 0) && (y < cols);
}

// Check if the given cell is an obstacle or not
bool isUnBlocked(vector<vector<int>>& grid, int x, int y) {
    return grid[x][y] == 1;
}

// Check if the destination has been reached
bool isDestination(int x, int y, Point dest) {
    return x == dest.x && y == dest.y;
}

// Calculate the 'h' heuristic value (using Euclidean distance)
double calculateHValue(int x, int y, Point dest) {
    return sqrt((x - dest.x) * (x - dest.x) + (y - dest.y) * (y - dest.y));
}

// Trace the path from the source to the destination
void tracePath(vector<vector<Cell>>& cellDetails, Point dest) {
    cout << "The path is: ";
    int row = dest.x;
    int col = dest.y;

    vector<Point> path;

    while (!(cellDetails[row][col].parent.x == row && cellDetails[row][col].parent.y == col)) {
        path.push_back(Point(row, col));
        int temp_row = cellDetails[row][col].parent.x;
        int temp_col = cellDetails[row][col].parent.y;
        row = temp_row;
        col = temp_col;
    }

    path.push_back(Point(row, col));
    reverse(path.begin(), path.end());

    for (auto p : path) {
        cout << "(" << p.x << "," << p.y << ") ";
    }
    cout << endl;
}

// A* algorithm implementation
void aStarSearch(vector<vector<int>>& grid, Point src, Point dest) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (!isValid(src.x, src.y, rows, cols) || !isValid(dest.x, dest.y, rows, cols)) {
        cout << "Source or destination is invalid" << endl;
        return;
    }

    if (!isUnBlocked(grid, src.x, src.y) || !isUnBlocked(grid, dest.x, dest.y)) {
        cout << "Source or destination is blocked" << endl;
        return;
    }

    if (isDestination(src.x, src.y, dest)) {
        cout << "We are already at the destination" << endl;
        return;
    }

    vector<vector<bool>> closedList(rows, vector<bool>(cols, false));

    vector<vector<Cell>> cellDetails(rows, vector<Cell>(cols));

    int i = src.x, j = src.y;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent = {i, j};

    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> openList;
    openList.emplace(0.0, Point(i, j));

    bool foundDest = false;

    while (!openList.empty()) {
        auto p = openList.top();
        openList.pop();

        i = p.second.x;
        j = p.second.y;
        closedList[i][j] = true;

        // Explore the 8 neighbors of the current cell
        for (int add_x = -1; add_x <= 1; add_x++) {
            for (int add_y = -1; add_y <= 1; add_y++) {
                int new_x = i + add_x;
                int new_y = j + add_y;

                if (isValid(new_x, new_y, rows, cols)) {
                    if (isDestination(new_x, new_y, dest)) {
                        cellDetails[new_x][new_y].parent = {i, j};
                        cout << "Destination found!" << endl;
                        tracePath(cellDetails, dest);
                        foundDest = true;
                        return;
                    } else if (!closedList[new_x][new_y] && isUnBlocked(grid, new_x, new_y)) {
                        double gNew = cellDetails[i][j].g + 1.0;
                        double hNew = calculateHValue(new_x, new_y, dest);
                        double fNew = gNew + hNew;

                        if (cellDetails[new_x][new_y].f == -1 || cellDetails[new_x][new_y].f > fNew) {
                            openList.emplace(fNew, Point(new_x, new_y));
                            cellDetails[new_x][new_y].f = fNew;
                            cellDetails[new_x][new_y].g = gNew;
                            cellDetails[new_x][new_y].h = hNew;
                            cellDetails[new_x][new_y].parent = {i, j};
                        }
                    }
                }
            }
        }
    }

    if (!foundDest) {
        cout << "Failed to find the destination cell" << endl;
    }
}

int main() {
    // Grid representation (1 is an open cell, 0 is a blocked cell)
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Point src(0, 0);
    Point dest(9, 9);

    aStarSearch(grid, src, dest);

    return 0;
}
