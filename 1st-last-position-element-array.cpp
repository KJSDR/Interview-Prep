// ============================================================================
// 34. Find First and Last Position of Element in Sorted Array
// Medium
// ============================================================================
//
// Problem:
// Given a sorted array nums, return the first and last index of target.
// If target is absent, return [-1, -1]. Must be O(log n).
//
// Approach: Two Binary Searches (no helpers, single solution)
// - First search: find the first index >= target (lower bound).
// - If nums[first] != target, return [-1, -1].
// - Second search (from first to end): find the first index > target (upper bound).
// - Answer = [first, upper_bound - 1].
//
// Time: O(log n)   Space: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};

        // lower_bound: first index i with nums[i] >= target
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) high = mid;
            else                     low = mid + 1;
        }
        int first = low;
        if (first == n || nums[first] != target) return {-1, -1};

        // upper_bound: first index i with nums[i] > target
        low = first; high = n; // we can start from 'first' to save steps
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) high = mid;
            else                    low = mid + 1;
        }
        int last = low - 1;

        return {first, last};
    }
};
