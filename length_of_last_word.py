##Given a string s consisting of words and spaces, return the length of the last word in the string.
#A word is a maximal substring consisting of non-space characters only.

#GIVEN:
#- String s consisting of words and spaces
#- 1 <= s.length <= 10^4
#- s consists of only English letters and spaces ' '
#- There will be at least one word in s

#OUTPUT:
#- Integer representing the length of the last word

#Example 1:
#Input: s = "Hello World"
#Output: 5
#Explanation: The last word is "World" with length 5.

#Example 2:
#Input: s = "   fly me   to   the moon  "
#Output: 4
#Explanation: The last word is "moon" with length 4.

#Example 3:
#Input: s = "luffy is still joyboy"
#Output: 6
#Explanation: The last word is "joyboy" with length 6.

# APPROACH:
# Traverse the string from right to left, skip trailing spaces,
# then count characters until we hit a space or reach the beginning.



#PSEUDOCODE:
#1. Start from the end of the string
#2. Skip any trailing spaces by moving left
#3. Count non-space characters from current position moving left
#4. Return the count when we hit a space or reach the beginning

class Solution(object):
    def lengthOfLastWord(self, s): O(1)
        """
        :type s: str
        :rtype: int
        """
        # Start from end and skip trailing spaces
        i = len(s) - 1 O(1)
        while i >= 0 and s[i] == ' ': O(n)
            i -= 1 O(1)
        
        # Countlength of the last word
        length = 0 O(1)
        while i >= 0 and s[i] != ' ': O(m)
            length += 1 O O(1)
            i -= 1 O(1)
        
        return length O(1)

        O(n+m)
