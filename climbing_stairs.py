##You are climbing a staircase. It takes n steps to reach the top.
#Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#GIVEN:
#- Integer n representing the number of steps to reach the top
#- 1 <= n <= 45
#- Can climb either 1 or 2 steps at a time

#OUTPUT:
#- Integer representing the number of distinct ways to climb to the top

#Example 1:
#Input: n = 2
#Output: 2
#Explanation: There are two ways to climb to the top.
#1. 1 step + 1 step
#2. 2 steps

#Example 2:
#Input: n = 3
#Output: 3
#Explanation: There are three ways to climb to the top.
#1. 1 step + 1 step + 1 step
#2. 1 step + 2 steps
#3. 2 steps + 1 step

# APPROACH:
# This is a classic dynamic programming problem similar to Fibonacci sequence.
# To reach step n, we can either come from step (n-1) with 1 step, or from step (n-2) with 2 steps.
# So: ways(n) = ways(n-1) + ways(n-2)

#PSEUDOCODE:
#1. Handle base cases: n=1 returns 1, n=2 returns 2
#2. Use two variables to store previous two values (like Fibonacci)
#3. For each step from 3 to n:
#   - Calculate current ways = prev1 + prev2
#   - Update prev2 = prev1, prev1 = current
#4. Return the final result

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Base cases
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        # Initialize for first two steps
        prev2 = 1  # ways to reach step 1
        prev1 = 2  # ways to reach step 2
        
        # Calculate ways for steps 3 to n
        for i in range(3, n + 1):
            current = prev1 + prev2
            prev2 = prev1
            prev1 = current
        
        return prev1