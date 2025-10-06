// ============================================================================
// 81. Search in Rotated Sorted Array II
// Medium
// ============================================================================
//
// Problem:
// Given a non-decreasing (may contain duplicates) array that was rotated,
// return true if target exists, else false. Minimize operations.
//
// Examples:
// [2,5,6,0,0,1,2], target=0 -> true
// [2,5,6,0,0,1,2], target=3 -> false
//
// -----------------------------------------------------------------------------
// Approach: Modified Binary Search with Duplicates
// - While low <= high, compute mid.
// - If nums[mid] == target -> true.
// - Ambiguity due to duplicates:
//     If nums[low] == nums[mid] == nums[high], shrink both ends (low++, high--).
// - Otherwise, at least one side is strictly increasing:
//     * Left sorted (nums[low] <= nums[mid]):
//         - If target in [nums[low], nums[mid]), move high = mid - 1
//         - else low = mid + 1
//     * Right sorted:
//         - If target in (nums[mid], nums[high]] (inclusive on high side), low = mid + 1
//         - else high = mid - 1
//
// Complexity: O(log n) average; worst-case O(n) when many duplicates.
// Space: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;

            // Handle duplicates: cannot determine the sorted half
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ++low;
                --high;
                continue;
            }

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
        return false;
    }
};
