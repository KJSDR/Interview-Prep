// Problem:
// Given a possibly rotated strictly increasing array nums and a target,
// return the index of target or -1 if absent. Must be O(log n).
//
// Examples:
// [4,5,6,7,0,1,2], target=0 -> 4
// [4,5,6,7,0,1,2], target=3 -> -1
// [1], target=0 -> -1
//
// -----------------------------------------------------------------------------
// Approach: Modified Binary Search
// At any mid, at least one half [low..mid] or [mid..high] is sorted.
// - If left half is sorted (nums[low] <= nums[mid]):
//     * Check if target lies within [nums[low], nums[mid]] to move high = mid-1;
//       else search right half (low = mid+1).
// - Else right half is sorted:
//     * Check if target lies within [nums[mid], nums[high]] to move low = mid+1;
//       else search left half (high = mid-1).
//
// Time: O(log n)
// Space: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
