/*Defense Kingdom
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.



Your task is to find the penalty of the give position.

Input Format

In the function an width and height of the kingdom and a vector of pairs representing positions of towers is passed.

Output Format

Return an integer representing the number of cells in the largest rectangle that is not defended by the towers.



Sample Input

15 8 
{(3, 8), (11, 2), (8, 6)}


Sample Output

12*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<ll> x, y;
    x.push_back(0); // Add boundary at the start
    y.push_back(0); // Add boundary at the start
    
    // Extract x and y coordinates from position and add to respective vectors
    for (auto &p : position) {
        x.push_back(p.first);
        y.push_back(p.second);
    }

    // Add the boundary coordinates
    x.push_back(W + 1); // Add boundary at the end
    y.push_back(H + 1); // Add boundary at the end

    // Sort the coordinates
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    ll maxx = 0, maxy = 0;

    // Find the maximum gap in the x-coordinates
    for (ll i = 1; i < x.size(); i++) 
        maxx = max(maxx, x[i] - x[i - 1] - 1);

    // Find the maximum gap in the y-coordinates
    for (ll i = 1; i < y.size(); i++) 
        maxy = max(maxy, y[i] - y[i - 1] - 1);

    // Return the product of the largest gaps
    return (maxx * maxy);
}

int main() {
    int W = 15, H = 8;
    vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};
    cout << defkin(W, H, position) << endl; // Expected output: 12
    return 0;
}

