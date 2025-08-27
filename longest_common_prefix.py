##Write a function to find the longest common prefix string amongst an array of strings.
#If there is no common prefix, return an empty string "".

#GIVEN:
#- Array of strings 'strs'
#- Each string consists of only lowercase English letters (if non-empty)
#- 1 <= strs.length <= 200
#- 0 <= strs[i].length <= 200

#OUTPUT:
#- String representing the longest common prefix
#- Empty string "" if no common prefix exists

#Example 1:
#Input: strs = ["flower","flow","flight"]
#Output: "fl"
#Explanation: The longest common prefix is "fl" which appears at the start of all strings.

#Example 2:
#Input: strs = ["dog","racecar","car"]
#Output: ""
#Explanation: There is no common prefix among the input strings.

# APPROACH:
# Compare characters at each position across all strings.
# Stop when we find a mismatch or reach the end of any string.

#PSEUDOCODE:
#1. Handle edge case: if array is empty, return ""
#2. Initialize result string
#3. For each character position from 0 to length of first string:
#   - Get the character at current position from first string
#   - Check if all other strings have the same character at this position
#   - If any string is too short or has different character, return current result
#   - Otherwise, add character to result
#4. Return result

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        # Handle edge case
        if not strs:
            return ""
        
        # Start with empty result
        result = ""
        
        # Check each character position up to the length of first string
        for i in range(len(strs[0])):
            # Get character from first string at position i
            char = strs[0][i]
            
            # Check if all other strings have the same character at position i
            for j in range(1, len(strs)):
                # If current string is too short or has different character
                if i >= len(strs[j]) or strs[j][i] != char:
                    return result
            
            # All strings have the same character at position i
            result += char
        
        return result