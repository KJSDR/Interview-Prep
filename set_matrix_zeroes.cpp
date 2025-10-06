// ============================================================================
// 73. Set Matrix Zeroes
// Medium
// ============================================================================
//
// Problem:
// Given an m x n matrix, if an element is 0, set its entire row and column to 0.
// Do it in-place (O(1) auxiliary space).
//
// -----------------------------------------------------------------------------
// Examples:
// [[1,1,1],[1,0,1],[1,1,1]] -> [[1,0,1],[0,0,0],[1,0,1]]
// [[0,1,2,0],[3,4,5,2],[1,3,1,5]] -> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
//
// -----------------------------------------------------------------------------
// Approach: Use First Row and First Column as Markers (O(1) extra space)
// 1) Scan the matrix to record which rows/cols should be zeroed.
//    - Instead of extra arrays, store markers in matrix[0][j] and matrix[i][0].
//    - Track two booleans: zeroFirstRow, zeroFirstCol.
// 2) Use the markers (excluding first row/col) to set inner cells to zero.
// 3) Zero the first row/col at the end if needed.
//
// Time: O(m*n)
// Space: O(1) auxiliary
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool zeroFirstRow = false, zeroFirstCol = false;

        // Check if first row needs to be zeroed
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) { zeroFirstRow = true; break; }
        }
        // Check if first column needs to be zeroed
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) { zeroFirstCol = true; break; }
        }

        // Use first row/col as markers for the rest of the matrix
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero cells based on markers (skip first row/col)
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero first row if needed
        if (zeroFirstRow) {
            for (int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        // Zero first column if needed
        if (zeroFirstCol) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
