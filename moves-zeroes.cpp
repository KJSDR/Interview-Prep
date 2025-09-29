// ============================================================================
// 283. Move Zeroes
// Easy
// ============================================================================
//
// Problem Statement:
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements. Do it in-place without copying.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Example 2:
// Input:  nums = [0]
// Output: [0]
// -----------------------------------------------------------------------------
//
// Constraints:
// 1 <= nums.length <= 10^4
// -2^31 <= nums[i] <= 2^31 - 1
//
// ============================================================================
//
// Approach: Two Pointers
// -----------------------------------------------------------------------------
// 1) Maintain an index `insertPos` where the next non-zero element should go.
// 2) Traverse nums:
//      - If nums[i] != 0, write it to nums[insertPos], increment insertPos.
// 3) After traversal, fill remaining positions with 0.
// 
// This preserves order of non-zero elements while pushing all 0's to the end.
//
// Time Complexity: O(n)
// Space Complexity: O(1) (in-place)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (int x : nums) {
            if (x != 0) {
                nums[insertPos++] = x;
            }
        }
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }
};
