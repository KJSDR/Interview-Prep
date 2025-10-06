// Problem:
// Return the smallest missing positive integer from an unsorted array.
// Must run in O(n) time and O(1) extra space.
//
// -----------------------------------------------------------------------------
// Examples:
// [1,2,0]          -> 3
// [3,4,-1,1]       -> 2
// [7,8,9,11,12]    -> 1
//
// -----------------------------------------------------------------------------
// Approach: In-Place Indexing (Cyclic Placement)
// -----------------------------------------------------------------------------
// Put each value v in the range [1..n] at index v-1 by swapping until either:
//   - v is out of range, or
//   - nums[v-1] == v (already in correct spot), or
//   - duplicates prevent progress.
// After this placement pass, the first index i where nums[i] != i+1 gives
// the answer i+1. If all positions are correct, answer is n+1.
//
// Why O(1) space?
// - We rearrange within the input array only.
// Why O(n) time?
// - Each element is moved at most once to its correct position.
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // place nums[i] to index nums[i]-1 while valid and not already placed
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // find first index where value != index+1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
