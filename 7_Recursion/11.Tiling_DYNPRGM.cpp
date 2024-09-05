/*
Tiling Problem!
You are given N tiles of size 1 x M, There is a floor of size N x M which you have to 
cover with tiles. Find the number of ways the floor can be completely covered if you
can place the tiles in both horizontal and vertical manner.

Input Format:

In the function, two integers N and M are passed.


Output Format:

Return a single integer denoting the number of ways.

Sample Input:

4 3

Sample Output:

3

*/
//time complexity O(n)
#include <iostream>
#include <vector>
using namespace std;

int countWaysToTile(int N, int M) {
    // Base case: If N is less than M, there's only one way to tile the floor.
    if (N < M) {
        return 1;
    }
    
    // Create a DP array to store the number of ways for each value of N
    vector<int> dp(N + 1, 0);

    // Base cases
    dp[0] = 1; // There's one way to tile a 0xM floor (do nothing)
    for (int i = 1; i < M; i++) {
        dp[i] = 1; // There's only one way to tile a floor of size NxM where N < M
    }
    
    dp[M] = 2; // For N = M, either place all tiles horizontally or all vertically

    // Fill the DP array for the rest of the cases
    for (int i = M + 1; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - M];
    }

    return dp[N];
}

int main() {
    int N, M;
    cout << "Enter N and M: ";
    cin >> N >> M;

    cout << "Number of ways to tile the floor: " << countWaysToTile(N, M) << endl;

    return 0;
}
