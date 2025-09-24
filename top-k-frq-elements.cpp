// Problem Statement:
// Given an integer array nums and an integer k, return the k most frequent
// elements. You may return the answer in any order.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
// Example 2:
// Input:  nums = [1], k = 1
// Output: [1]
//
// Example 3:
// Input:  nums = [1,2,1,2,1,2,3,1,3,2], k = 2
// Output: [1,2]
// -----------------------------------------------------------------------------
//
// Constraints:
// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
// 1 <= k <= (# of unique elements)
// The answer is guaranteed to be unique.
//
// ============================================================================
//
// Approach: Bucket Sort on Frequencies (O(n))
// 1) Count frequencies with a hash map: freq[val] -> count.
// 2) Create buckets where bucket[i] holds all numbers that appear exactly i times.
//    - There are at most n occurrences, so make (n + 1) buckets.
// 3) Iterate buckets from high frequency to low, collecting elements until we
//    gather k of them.
//
// Why Bucket Sort?
// - Avoids O(n log n) sorting of pairs by frequency.
// - Runs in O(n) time and O(n) space.
//
// Time Complexity: O(n) where n = nums.size()
// Space Complexity: O(n)
// ============================================================================

#include <vector>
#include <unordered_map>
using namespace std;


using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq.reserve(nums.size() * 2);
        for (int x : nums) {
            ++freq[x];
        }

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        buckets.reserve(n + 1);
        for (const auto& [val, count] : freq) {
            buckets[count].push_back(val);
        }

        vector<int> ans;
        ans.reserve(k);
        for (int f = n; f >= 1 && (int)ans.size() < k; --f) {
            for (int val : buckets[f]) {
                ans.push_back(val);
                if ((int)ans.size() == k) break;
            }
        }
        return ans;
    }
};
