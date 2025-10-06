// Problem:
// Given a strictly increasing array that's been rotated 1..n times, return
// the minimum element. Must be O(log n).
//
// Examples:
// [3,4,5,1,2]          -> 1
// [4,5,6,7,0,1,2]      -> 0
// [11,13,15,17]        -> 11
//
// -----------------------------------------------------------------------------
// Approach: Binary Search on Sorted Half
// - If the array is not rotated (nums[0] < nums.back()), the first element is min.
// - Otherwise, use binary search with two pointers (low, high):
//     * Compare nums[mid] with nums[high]:
//         - If nums[mid] > nums[high], the min lies to the right (low = mid + 1).
//         - Else, the min is at mid or to the left (high = mid).
// - Loop until low == high; that's the index of the minimum.
//
// Time: O(log n) | Space: O(1)
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // If not rotated at all
        if (nums[low] < nums[high]) return nums[low];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in the right half
                low = mid + 1;
            } else {
                // Minimum is at mid or in the left half
                high = mid;
            }
        }
        return nums[low];
    }
};
