// Problem Statement:
// Reverse the bits of a given 32-bit signed integer.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  n = 43261596
// Output: 964176192
//
// Explanation:
// 43261596  -> 00000010100101000001111010011100
// 964176192 -> 00111001011110000010100101000000
//
// Example 2:
// Input:  n = 2147483644
// Output: 1073741822
//
// Explanation:
// 2147483644 -> 01111111111111111111111111111100
// 1073741822 -> 00111111111111111111111111111110
// -----------------------------------------------------------------------------
//
// Constraints:
// 0 <= n <= 2^31 - 2
// n is even.
//
// Follow-up:
// If this function is called many times, optimize using:
// - Precomputed lookup table for reversing 8-bit chunks.
// - Or bit manipulation tricks.
//
// ============================================================================
//
// Approach: Bit Manipulation
// - Initialize result = 0.
// - Iterate over 32 bits of n:
//     - Shift result left by 1.
//     - Add the lowest bit of n (n & 1) to result.
//     - Shift n right by 1.
// - After 32 iterations, result is the reversed bit sequence.
//
// Time Complexity: O(32) = O(1)
// Space Complexity: O(1)
//
// ============================================================================

using namespace std;

class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;   
            result |= (n & 1);   
            n >>= 1;        
        }
        return (int)result;
    }
};
