// ============================================================================
// 338. Counting Bits
// Easy
// ============================================================================
//
// Problem Statement:
// Given an integer n, return an array ans of length n + 1 such that for each
// i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  n = 2
// Output: [0,1,1]
// Explanation:
//   0 --> 0  -> 0 ones
//   1 --> 1  -> 1 one
//   2 --> 10 -> 1 one
//
// Example 2:
// Input:  n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
//   0 --> 0    -> 0
//   1 --> 1    -> 1
//   2 --> 10   -> 1
//   3 --> 11   -> 2
//   4 --> 100  -> 1
//   5 --> 101  -> 2
// -----------------------------------------------------------------------------
//
// Constraints:
// 0 <= n <= 10^5
//
// ============================================================================
//
// Approach: Dynamic Programming with Bit Manipulation
// -----------------------------------------------------------------------------
// Observation:
//   The number of set bits in i can be derived from a smaller number:
//   - If i is even: ans[i] = ans[i/2] (since right shift drops a zero bit).
//   - If i is odd:  ans[i] = ans[i/2] + 1 (since odd numbers have last bit = 1).
//
// Formula: ans[i] = ans[i >> 1] + (i & 1)
//
// Time Complexity: O(n)
// Space Complexity: O(n) for output
//
// ============================================================================

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};

