##Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

#Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

#The judge will test your solution with the following code:

##int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

#int k = removeDuplicates(nums); // Calls your implementation

#assert k == expectedNums.length;
#for (int i = 0; i < k; i++) {
#    assert nums[i] == expectedNums[i];
#}
#If all assertions pass, then your solution will be accepted.

#GIVEN:
#- Integer array 'nums' sorted in non-decreasing order
#- May contain duplicates
#- Must modify in-place (no extra array)

#OUTPUT:
#- Integer 'k' representing the number of unique elements
#- Modified array with first k elements being unique values in original order
#- Elements after index k don't matter

#Example 1:

#Input: nums = [1,1,2]
#Output: 2, nums = [1,2,_]
#Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
#It does not matter what you leave beyond the returned k (hence they are underscores).
#Example 2:

#Input: nums = [0,0,1,1,1,2,2,3,3,4]
#Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
#Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
#It does not matter what you leave beyond the returned k (hence they are underscores).


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Handle edge case
        if not nums:
            return 0
        
        # First element is always unique, start k at 1
        k = 1
        
        # Iterate through array starting from second element
        for i in range(1, len(nums)):
            # If current element is different from previous
            if nums[i] != nums[i-1]:
                # Place it at position k and increment k
                nums[k] = nums[i]
                k += 1
        
        return k