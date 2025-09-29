// ============================================================================
// 201. Bitwise AND of Numbers Range
// Medium
// ============================================================================
//
// Problem Statement:
// Given two integers left and right representing a range [left, right],
// return the bitwise AND of all numbers in that inclusive range.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  left = 5, right = 7
// Output: 4
// Explanation: 5 = 101, 6 = 110, 7 = 111
// Bitwise AND = 100 = 4
//
// Example 2:
// Input:  left = 0, right = 0
// Output: 0
//
// Example 3:
// Input:  left = 1, right = 2147483647
// Output: 0
// -----------------------------------------------------------------------------
//
// Constraints:
// 0 <= left <= right <= 2^31 - 1
//
// ============================================================================
//
// Approach: Common Prefix of Binary Representation
// -----------------------------------------------------------------------------
// - The AND of all numbers in [left, right] is just the common prefix bits of
//   left and right. Once a bit differs, everything after it becomes 0.
// - Shift left and right rightwards until they are equal, counting shifts.
// - Then shift back left by the count to reconstruct the prefix.
//
// Example:
//   left = 5 (101), right = 7 (111)
//   Shift until equal:
//     (101, 111) -> (10, 11) -> (1, 1), shifts = 2
//   Result = 1 << 2 = 100 = 4
//
// Time Complexity: O(1) for 32-bit integers (at most 32 shifts)
// Space Complexity: O(1)
//
// ============================================================================

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
