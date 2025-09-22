// ============================================================================
// 69. Sqrt(x)
// Easy
// ============================================================================
//
// Problem Statement:
// Given a non-negative integer x, return the square root of x rounded down
// to the nearest integer. The returned integer should be non-negative as well.
//
// You must not use any built-in exponent function or operator.
// For example, do not use pow(x, 0.5) in C++.
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.
//
// Example 2:
// Input:  x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., rounded down is 2.
// -----------------------------------------------------------------------------
//
// Constraints:
// 0 <= x <= 2^31 - 1
//
// ============================================================================
//
// Approach:
// - We can use Binary Search to find the integer square root.
// - Start with left = 0, right = x.
// - Compute mid = (left + right) / 2, and check if mid*mid <= x.
// - If so, move left up (answer could be higher).
// - Otherwise, move right down.
// - Continue until left > right.
// - Keep track of the answer (largest mid with mid*mid <= x).
//
// Time Complexity: O(log x) because binary search halves the range each step.
// Space Complexity: O(1).
//
// ============================================================================

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // quick return for 0 and 1

        long left = 1, right = x / 2; // sqrt(x) <= x/2 for x > 1
        int ans = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sq = mid * mid;

            if (sq == x) {
                return (int)mid;
            } else if (sq < x) {
                ans = (int)mid;   // possible answer
                left = mid + 1;   // try for bigger sqrt
            } else {
                right = mid - 1;  // mid^2 too large
            }
        }

        return ans;
    }
};
