##Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
#You may assume that each input would have exactly one solution, and you may not use the same element twice.
#You can return the answer in any order.

#GIVEN:
#- Array of integers 'nums'
#- Integer 'target'
#- 2 <= nums.length <= 10^4
#- -10^9 <= nums[i] <= 10^9
#- -10^9 <= target <= 10^9
#- Only one valid answer exists
#- Cannot use the same element twice

#OUTPUT:
#- List of two integers representing indices of numbers that add up to target
#- Can return indices in any order

#Example 1:
#Input: nums = [2,7,11,15], target = 9
#Output: [0,1]
#Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

#Example 2:
#Input: nums = [3,2,4], target = 6
#Output: [1,2]
#Explanation: Because nums[1] + nums[2] == 6, we return [1, 2].

#Example 3:
#Input: nums = [3,3], target = 6
#Output: [0,1]
#Explanation: Because nums[0] + nums[1] == 6, we return [0, 1].

# APPROACH:
# Use a hash map to store each number and its index as we iterate.
# For each number, check if its complement (target - current number) exists in the hash map.
# If found, return the indices. If not, add current number and index to hash map.

#PSEUDOCODE:
#1. Initialize empty hash map to store {value: index}
#2. For each number and its index in the array:
#   - Calculate complement = target - current number
#   - If complement exists in hash map:
#     - Return [hash_map[complement], current_index]
#   - Otherwise, store current number and index in hash map
#3. Return result (guaranteed to exist per problem constraints)

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Hash map to store {value: index}
        num_map = {}
        
        # Iterate through array with both value and index
        for i, num in enumerate(nums):
            # Calculate what number we need to reach target
            complement = target - num
            
            # Check if complement exists in our map
            if complement in num_map:
                # Found the pair! Return indices
                return [num_map[complement], i]
            
            # Store current number and its index for future lookups
            num_map[num] = i
        
        # This line should never be reached per problem constraints
        return []