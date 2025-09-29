// ============================================================================
// 136. Single Number
// Easy
// ============================================================================
//
// Problem Statement:
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.
//
// Requirements:
// - Must run in linear time.
// - Must use only constant extra space.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [2,2,1]
// Output: 1
//
// Example 2:
// Input:  nums = [4,1,2,1,2]
// Output: 4
//
// Example 3:
// Input:  nums = [1]
// Output: 1
// -----------------------------------------------------------------------------
//
// Constraints:
// 1 <= nums.length <= 3 * 10^4
// -3 * 10^4 <= nums[i] <= 3 * 10^4
// Every element appears exactly twice, except for one element appearing once.
//
// ============================================================================
//
// Approach: XOR Trick
// -----------------------------------------------------------------------------
// XOR properties:
// - x ^ x = 0
// - x ^ 0 = x
// - XOR is commutative and associative
//
// So, XOR-ing all numbers cancels out pairs, leaving the single number.
//
// Example: nums = [4,1,2,1,2]
//   4 ^ 1 ^ 2 ^ 1 ^ 2
// = (1 ^ 1) ^ (2 ^ 2) ^ 4
// = 0 ^ 0 ^ 4 = 4
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
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }
};
