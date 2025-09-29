// ============================================================================
// 371. Sum of Two Integers
// Medium
// ============================================================================
//
// Problem Statement:
// Given two integers a and b, return the sum of the two integers without using
// the operators + and -.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  a = 1, b = 2
// Output: 3
//
// Example 2:
// Input:  a = 2, b = 3
// Output: 5
// -----------------------------------------------------------------------------
//
// Constraints:
// -1000 <= a, b <= 1000
//
// ============================================================================
//
// Approach: Bit Manipulation (Full Adder Simulation)
// -----------------------------------------------------------------------------
// We can simulate addition using bitwise operators:
// - XOR (^) gives the partial sum without carry.
// - AND (&) + shift gives the carry.
// - Repeat until carry = 0.
//
// Example: a = 2, b = 3
//   2 = 010, 3 = 011
//   sum = 010 ^ 011 = 001 (1)
//   carry = (010 & 011) << 1 = 100 (4)
//   new a = 1, b = 4
//   sum = 001 ^ 100 = 101 (5)
//   carry = (001 & 100) << 1 = 0
//   Result = 5
//
// Time Complexity: O(1) for fixed-width integers (at most 32 iterations).
// Space Complexity: O(1).
//
// ============================================================================

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1; 
            a = a ^ b;
            b = carry;  
        }
        return a;
    }
};
