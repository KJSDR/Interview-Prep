// Problem Statement:
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.

// Time Complexity: O(n)
// Space Complexity: O(1)
//
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        for (int x : nums) {
            if (x != 0) {
                nums[pos++] = x;
            }
        }
        while (pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
    // other method single pass swap
    void moveZeroes(vector<int>& nums) {
        int i = 0;                     
        for (int j = 0; j < (int)nums.size(); ++j) {
            if (nums[j] != 0) {
                if (i != j) swap(nums[i], nums[j]);
                ++i;
            }
        }
    }
};
