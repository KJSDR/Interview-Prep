##Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

#Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
#- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
#- Return k.

#GIVEN:
#- Integer array 'nums'
#- Integer 'val' to remove
#- 0 <= nums.length <= 100
#- 0 <= nums[i] <= 50
#- 0 <= val <= 100
#- Must modify in-place (no extra array)
#- Order of remaining elements may be changed

#OUTPUT:
#- Integer 'k' representing the number of elements not equal to val
#- Modified array with first k elements being values != val
#- Elements after index k don't matter

#Example 1:
#Input: nums = [3,2,2,3], val = 3
#Output: 2, nums = [2,2,_,_]
#Explanation: Your function should return k = 2, with the first two elements of nums being 2.
#It does not matter what you leave beyond the returned k (hence they are underscores).

#Example 2:
#Input: nums = [0,1,2,2,3,0,4,2], val = 2
#Output: 5, nums = [0,1,4,0,3,_,_,_]
#Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
#Note that the five elements can be returned in any order.
#It does not matter what you leave beyond the returned k (hence they are underscores).

# APPROACH:
# Use two pointers technique. One pointer (k) tracks where to place the next valid element,
# another pointer iterates through the array. When we find an element != val, 
# we place it at position k and increment k.

#PSEUDOCODE:
#1. Initialize pointer k = 0 (tracks position for next valid element)
#2. For each element in the array:
#   - If current element != val:
#     - Place current element at position k
#     - Increment k
#3. Return k (number of elements not equal to val)

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        # Pointer to track where to place next valid element
        k = 0
        
        # Iterate through all elements
        for i in range(len(nums)):
            # If current element is not the value to remove
            if nums[i] != val:
                # Place it at position k and move k forward
                nums[k] = nums[i]
                k += 1
        
        # Return count of elements not equal to val
        return k