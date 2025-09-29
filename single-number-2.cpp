// ============================================================================
// 137. Single Number II
// Medium
// ============================================================================
//
// Problem Statement:
// Given an integer array nums where every element appears exactly three times
// except for one element which appears only once, return that single one.
//
// Requirements:
// - Linear runtime complexity
// - Constant extra space
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [2,2,3,2]
// Output: 3
//
// Example 2:
// Input:  nums = [0,1,0,1,0,1,99]
// Output: 99
// -----------------------------------------------------------------------------
//
// Constraints:
// 1 <= nums.length <= 3 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// Every element appears exactly three times except one which appears once.
//
// ============================================================================
//
// Approach 1: Bit Counting
// -----------------------------------------------------------------------------
// - For each of 32 bits, count how many numbers have that bit set.
// - If count % 3 != 0, it means the single element has that bit set.
// - Reconstruct the number from those bits.
//
// Time Complexity: O(32 * n) = O(n)
// Space Complexity: O(1)
//
// Approach 2: Bitmask Trick (Optimal, constant space)
// -----------------------------------------------------------------------------
// Maintain two bitmasks:
//   ones  -> bits that have appeared once so far
//   twos  -> bits that have appeared twice so far
//
// Update rules for each number x:
//   ones = (ones ^ x) & ~twos
//   twos = (twos ^ x) & ~ones
//
// Explanation:
// - First occurrence of a bit goes into ones.
// - Second occurrence moves it from ones to twos.
// - Third occurrence removes it from both.
// After processing all numbers, "ones" will hold the unique number.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;
    }
};
