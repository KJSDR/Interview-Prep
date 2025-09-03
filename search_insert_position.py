##Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
#You must write an algorithm with O(log n) runtime complexity.

#GIVEN:
#- Sorted array of distinct integers 'nums'
#- Integer 'target' value to find or insert
#- 1 <= nums.length <= 10^4
#- -10^4 <= nums[i] <= 10^4
#- nums contains distinct values sorted in ascending order
#- -10^4 <= target <= 10^4
#- Must achieve O(log n) runtime complexity

#OUTPUT:
#- Integer representing the index where target is found or should be inserted
#- If target exists, return its index
#- If target doesn't exist, return the index where it would be inserted to maintain sorted order

#Example 1:
#Input: nums = [1,3,5,6], target = 5
#Output: 2
#Explanation: Target 5 is found at index 2.

#Example 2:
#Input: nums = [1,3,5,6], target = 2
#Output: 1
#Explanation: Target 2 is not found. It should be inserted at index 1 to maintain order: [1,2,3,5,6].

#Example 3:
#Input: nums = [1,3,5,6], target = 7
#Output: 4
#Explanation: Target 7 is not found. It should be inserted at index 4 to maintain order: [1,3,5,6,7].

# APPROACH:
# Use binary search since the array is sorted and we need O(log n) complexity.
# If target is found, return its index. If not found, the left pointer will be
# at the correct insertion position when the search terminates.

#PSEUDOCODE:
#1. Initialize left = 0, right = len(nums) - 1
#2. While left <= right:
#   - Calculate mid = (left + right) // 2
#   - If nums[mid] == target: return mid (found)
#   - If nums[mid] < target: search right half (left = mid + 1)
#   - If nums[mid] > target: search left half (right = mid - 1)
#3. Return left (insertion position when target not found)

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        
        # Binary search
        while left <= right:
            mid = (left + right) // 2
            
            # Target found
            if nums[mid] == target:
                return mid
            
            # Target is larger, search right half
            elif nums[mid] < target:
                left = mid + 1
            
            # Target is smaller, search left half
            else:
                right = mid - 1
        
        # Target not found, left is the correct insertion position
        return left