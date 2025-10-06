// Problem:
// Given a sorted array (ascending) that was rotated 1..n times and may contain
// duplicates, return the minimum element. Minimize operations.
//
// Examples:
// [1,3,5]       -> 1
// [2,2,2,0,1]   -> 0
//
// -----------------------------------------------------------------------------
// Approach: Binary Search with Duplicates
// - Maintain low, high pointers.
// - While low < high:
//     * mid = (low + high) / 2
//     * If nums[mid] > nums[high], the minimum is in the right half: low = mid + 1
//     * Else if nums[mid] < nums[high], the minimum is at mid or in left half: high = mid
//     * Else (nums[mid] == nums[high]): cannot decide side -> shrink high--
// - Return nums[low].
//
// Complexity:
// - Average O(log n), but worst-case O(n) when there are many duplicates.
// - Space O(1).
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = (int)nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum must be to the right of mid
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Minimum is at mid or to the left
                high = mid;
            } else {
                // nums[mid] == nums[high], ambiguity due to duplicates
                // Safely shrink the search space
                --high;
            }
        }
        return nums[low];
    }
};
