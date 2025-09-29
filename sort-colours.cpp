// ============================================================================
// 75. Sort Colors
// Medium
// ============================================================================
//
// Problem Statement:
// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent, with the colors
// in the order red (0), white (1), and blue (2).
//
// Requirements:
// - Do NOT use library sort.
// - Must be in-place, O(1) extra space.
// - Ideally one-pass.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
// Example 2:
// Input:  nums = [2,0,1]
// Output: [0,1,2]
// -----------------------------------------------------------------------------
//
// Constraints:
// n == nums.length
// 1 <= n <= 300
// nums[i] is 0, 1, or 2
//
// ============================================================================
//
// Approach 1: Counting Sort (Two-pass)
// - Count number of 0s, 1s, 2s, then overwrite array.
// - Simple but two passes.
//
// Approach 2: Dutch National Flag Algorithm (Optimal One-pass)
// -----------------------------------------------------------------------------
// Maintain three regions with pointers:
//   • low: boundary for 0s
//   • mid: current element to process
//   • high: boundary for 2s
//
// Algorithm:
// - Initialize low = 0, mid = 0, high = n-1
// - While mid <= high:
//     - If nums[mid] == 0: swap(nums[low], nums[mid]), low++, mid++
//     - If nums[mid] == 1: mid++
//     - If nums[mid] == 2: swap(nums[mid], nums[high]), high--
// - Done when mid > high.
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
