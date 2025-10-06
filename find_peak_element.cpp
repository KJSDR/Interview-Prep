// Problem:
// A peak element is one that is strictly greater than its neighbors.
// Given an array nums, return any peak element's index.
// Assume nums[-1] = nums[n] = -∞.
// Must run in O(log n).
//
// Examples:
// [1,2,3,1]            -> 2  (nums[2] = 3 is a peak)
// [1,2,1,3,5,6,4]      -> 1 or 5 (both are valid peaks)
//
// -----------------------------------------------------------------------------
// Approach: Binary Search for Peak
// -----------------------------------------------------------------------------
// Observation:
// - If nums[mid] > nums[mid+1], then a peak exists in the left half (including mid).
// - Else, a peak exists in the right half (excluding mid).
// This works because one side is always ascending toward a peak.
//
// Algorithm:
// - Initialize low = 0, high = n-1
// - While low < high:
//     mid = (low + high) / 2
//     if nums[mid] > nums[mid+1], high = mid
//     else low = mid + 1
// - Return low (or high) as the index of a peak.
//
// Time: O(log n)
// Space: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = (int)nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;  // peak is in left half (including mid)
            } else {
                low = mid + 1;  // peak is in right half
            }
        }
        return low; // or high (both equal here)
    }
};
