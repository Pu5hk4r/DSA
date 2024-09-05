/*
Rahul's father has left a farm organized as NxN grid each square in the grid either has or does not have a mango
tree he has to divide the farm with his 3 sister as follow:-
he will draw one horizontal line and one vertical line to divide the fields into 4 rectangles
his friends will choose  3 of the 4 smaller fileds and he gets the last one. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to create the prefix sum matrix
vector<vector<int>> createPrefixSumMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefixSum[i][j] = matrix[i - 1][j - 1] 
                            + prefixSum[i - 1][j] 
                            + prefixSum[i][j - 1] 
                            - prefixSum[i - 1][j - 1];
        }
    }
    
    return prefixSum;
}


// Function to calculate the number of trees in a sub-rectangle
int getSubRectangleSum(const vector<vector<int>>& prefixSum, int x1, int y1, int x2, int y2) {
    return prefixSum[x2][y2] - prefixSum[x1 - 1][y2] - prefixSum[x2][y1 - 1] + prefixSum[x1 - 1][y1 - 1];
}

int maxMangoTreesRahulCanGet(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> prefixSum = createPrefixSumMatrix(matrix);
    int maxTrees = 0;
    
    // Iterate over all possible positions for the horizontal and vertical lines
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            // Calculate number of trees in each of the 4 fields
            int field1 = getSubRectangleSum(prefixSum, 1, 1, i, j);
            int field2 = getSubRectangleSum(prefixSum, 1, j + 1, i, n);
            int field3 = getSubRectangleSum(prefixSum, i + 1, 1, n, j);
            int field4 = getSubRectangleSum(prefixSum, i + 1, j + 1, n, n);
            
            // Sort the fields and determine the maximum trees Rahul can get
            vector<int> fields = {field1, field2, field3, field4};
            sort(fields.begin(), fields.end());
            maxTrees = max(maxTrees, fields[0]);
        }
    }
    
    return maxTrees;
}

int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {0,1,0,0,0,0},
        {0,1,1,0,0,1},
        {1,0,0,1,1,0},
        {0,1,0,0,0,0}
    };
    
    int result = maxMangoTreesRahulCanGet(matrix);
    cout << "Maximum number of trees Rahul can get: " << result << endl;
    
    return 0;
}