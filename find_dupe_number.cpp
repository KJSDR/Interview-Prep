// ============================================================================
// 287. Find the Duplicate Number
// Medium
// ============================================================================
//
// Problem:
// Given nums with n+1 integers in [1..n], find the single duplicated number.
// Requirements: Do not modify nums; use O(1) extra space; run in O(n) time.
//
// Examples:
// [1,3,4,2,2] -> 2
// [3,1,3,4,2] -> 3
// [3,3,3,3,3] -> 3
//
// -----------------------------------------------------------------------------
// Approach: Floyd's Tortoise and Hare (Cycle Detection)
// Treat indices as nodes and value as "next" pointer: i -> nums[i].
// Because values are in [1..n] with n+1 elements, a cycle exists.
// The entry point of the cycle is the duplicate.
//
// Phase 1: Move tortoise by 1 and hare by 2 until they meet.
// Phase 2: Reset tortoise to nums[0]; move both by 1 step; meet at duplicate.
//
// Time: O(n) | Space: O(1)
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];

        // Phase 1: find intersection
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Phase 2: find cycle entrance (duplicate)
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};
