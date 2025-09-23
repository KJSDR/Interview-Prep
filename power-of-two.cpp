// Problem Statement:
// Given an integer n, return true if it is a power of two. Otherwise, return false.
//
// An integer n is a power of two if there exists an integer x such that n == 2^x.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  n = 1
// Output: true
// Explanation: 2^0 = 1
//
// Example 2:
// Input:  n = 16
// Output: true
// Explanation: 2^4 = 16
//
// Example 3:
// Input:  n = 3
// Output: false
// -----------------------------------------------------------------------------
//
// Constraints:
// -2^31 <= n <= 2^31 - 1
//
// Follow-up:
// Solve it without loops or recursion.
//
// ============================================================================
//
// Approach 1: Bit Manipulation
// - A power of two has exactly one '1' bit in its binary representation.
// - Check condition: n > 0 AND (n & (n - 1)) == 0.
//   Example: 
//     n = 16 (10000)
//     n-1 = 15 (01111)
//     n & (n-1) = 0 -> true
//
// Time Complexity: O(1)
// Space Complexity: O(1)
//
// ============================================================================

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
