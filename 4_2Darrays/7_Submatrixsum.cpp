#include <iostream>
#include <vector>

using namespace std;

// Function to compute the prefix sum matrix
vector<vector<int>> computePrefixSum(const vector<vector<int>>& mat) {
    int M = mat.size();
    int N = mat[0].size();
    vector<vector<int>> prefixSum(M, vector<int>(N, 0));

    // Fill the prefixSum matrix
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            prefixSum[i][j] = mat[i][j];
            if (i > 0) prefixSum[i][j] += prefixSum[i-1][j];
            if (j > 0) prefixSum[i][j] += prefixSum[i][j-1];
            if (i > 0 && j > 0) prefixSum[i][j] -= prefixSum[i-1][j-1];
        }
    }
    return prefixSum;
}

// Function to get the sum of a submatrix using the prefix sum matrix
int getSubmatrixSum(const vector<vector<int>>& prefixSum, int tli, int tlj, int rbi, int rbj) {
    int sum = prefixSum[rbi][rbj];
    if (tli > 0) sum -= prefixSum[tli-1][rbj];
    if (tlj > 0) sum -= prefixSum[rbi][tlj-1];
    if (tli > 0 && tlj > 0) sum += prefixSum[tli-1][tlj-1];
    return sum;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}
    };

    // Compute the prefix sum matrix
    vector<vector<int>> prefixSum = computePrefixSum(mat);

    // Example queries
    vector<vector<int>> queries = {
        {0, 0, 1, 1},
        {2, 2, 3, 4},
        {1, 2, 3, 3}
    };

    for (const vector<int>& query : queries) {
        int tli = query[0];
        int tlj = query[1];
        int rbi = query[2];
        int rbj = query[3];
        cout << "Query: (" << tli << ", " << tlj << ") to (" << rbi << ", " << rbj << ") -> ";
        cout << getSubmatrixSum(prefixSum, tli, tlj, rbi, rbj) << endl;
    }

    return 0;
}
