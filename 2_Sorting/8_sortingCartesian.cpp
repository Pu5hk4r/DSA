/*
Sorting Cartesian Points
Given co-ordinates of N points on X-Y axis, your task is to sort them in accordance to the x-coordinate. If the x-coordinates are same then compare y-coordinates.

Input Format

In the function an integer vector of pairs is passed.

Output Format

Return the vector in sorted order.



Sample Input

{ (3, 4), (2, 3), (3, 7), (1, 5), (3, 4) } 


Sample Output

{ (1, 5), (2, 3), (3, 4), (3, 4), (3, 7) } 


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the comparison function
bool comparePairs(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second; // If x-coordinates are the same, sort by y-coordinate
    }
    return p1.first < p2.first; // Otherwise, sort by x-coordinate
}

int main() {
    // Sample input
    vector<pair<int, int>> points = { {3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4} };

    // Sort using the comparison function
    sort(points.begin(), points.end(), comparePairs);

    // Output the sorted points
    for (const auto& point : points) {
        cout << "(" << point.first << ", " << point.second << ") ";
    }
    cout << endl;

    return 0;
}
