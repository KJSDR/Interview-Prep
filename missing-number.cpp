// ============================================================================
// 268. Missing Number
// Easy
// ============================================================================
//
// Problem Statement:
// Given an array nums containing n distinct numbers in the range [0, n],
// return the only number missing from the array.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [3,0,1]
// Output: 2
//
// Example 2:
// Input:  nums = [0,1]
// Output: 2
//
// Example 3:
// Input:  nums = [9,6,4,2,3,5,7,0,1]
// Output: 8
// -----------------------------------------------------------------------------
//
// Constraints:
// n == nums.length
// 1 <= n <= 10^4
// 0 <= nums[i] <= n
// All nums[i] are unique.
//
// ============================================================================
//
// Approach 1: Gauss' Formula (Sum Formula)
// -----------------------------------------------------------------------------
// - Sum of range [0..n] is n*(n+1)/2
// - Subtract sum(nums) from this to get the missing number.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Approach 2: XOR Trick (Bit Manipulation)
// -----------------------------------------------------------------------------
// - XOR all numbers from 0..n and all numbers in nums.
// - Since duplicates cancel out (x ^ x = 0), only the missing number remains.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    // Approach 1: Sum formula
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int x : nums) actualSum += x;
        return expectedSum - actualSum;
    }

    // Approach 2: XOR trick (alternative)
    int missingNumberXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};
