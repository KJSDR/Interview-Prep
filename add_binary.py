##Given two binary strings a and b, return their sum as a binary string.

#GIVEN:
#- Two binary strings 'a' and 'b'
#- 1 <= a.length, b.length <= 10^4
#- Strings consist only of '0' or '1' characters
#- No leading zeros except for the zero itself

#OUTPUT:
#- String representing the binary sum of a and b

#Example 1:
#Input: a = "11", b = "1"
#Output: "100"
#Explanation: 11 (binary) + 1 (binary) = 100 (binary)

#Example 2:
#Input: a = "1010", b = "1011"
#Output: "10101"
#Explanation: 1010 (binary) + 1011 (binary) = 10101 (binary)

# APPROACH:
# Simulate binary addition from right to left, keeping track of carry.
# Use two pointers starting from the end of each string.

#PSEUDOCODE:
#1. Initialize pointers at the end of both strings
#2. Initialize carry = 0 and result list
#3. While there are digits to process or carry exists:
#   - Get current digits from both strings (0 if pointer is out of bounds)
#   - Calculate sum = digit_a + digit_b + carry
#   - Append (sum % 2) to result
#   - Update carry = sum // 2
#   - Move pointers left
#4. Reverse result and convert to string


class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        result = []
        carry = 0
        i, j = len(a) - 1, len(b) - 1
        
        # Process digits from right to left
        while i >= 0 or j >= 0 or carry:
            # Get current digits (0 if pointer is out of bounds)
            digit_a = int(a[i]) if i >= 0 else 0
            digit_b = int(b[j]) if j >= 0 else 0
            
            # Calculate sum and new carry
            total = digit_a + digit_b + carry
            result.append(str(total % 2))
            carry = total // 2
            
            # Move pointers
            i -= 1
            j -= 1
        
        # Result is built backwards, so reverse it
        return ''.join(reversed(result))