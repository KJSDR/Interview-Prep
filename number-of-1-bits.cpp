// Problem Statement:
// Given a positive integer n, write a function that returns the number of set
// bits (1s) in its binary representation (also known as the Hamming weight).
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  n = 11
// Output: 3
// Explanation: 11 in binary is 1011, which has 3 set bits.
//
// Example 2:
// Input:  n = 128
// Output: 1
// Explanation: 128 in binary is 10000000, which has 1 set bit.
//
// Example 3:
// Input:  n = 2147483645
// Output: 30
// Explanation: 2147483645 in binary is
//              1111111111111111111111111111101, which has 30 set bits.
// -----------------------------------------------------------------------------
//
// Constraints:
// 1 <= n <= 2^31 - 1
//
// Follow-up:
// If the function is called many times, optimize it using:
// - Brian Kernighan’s algorithm (n & (n-1)) trick
// - Precomputed lookup tables for bytes
//
// ============================================================================
//
// Approach 1: Brian Kernighan’s Algorithm
// - Repeatedly flip the lowest set bit until n becomes 0.
// - Operation: n = n & (n - 1)
// - Each step removes one '1' bit.
//
// Time Complexity: O(k), where k is the number of set bits.
// Space Complexity: O(1)
//
// ============================================================================

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};
