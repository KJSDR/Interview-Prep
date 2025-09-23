// Problem Statement:
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:  x = 2.00000, n = 10
// Output: 1024.00000
//
// Example 2:
// Input:  x = 2.10000, n = 3
// Output: 9.26100
//
// Example 3:
// Input:  x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2^-2 = 1 / (2^2) = 1/4 = 0.25
// -----------------------------------------------------------------------------
//
// Constraints:
// -100.0 < x < 100.0
// -2^31 <= n <= 2^31 - 1
// n is an integer.
// Either x is not zero or n > 0.
// -10^4 <= x^n <= 10^4
//
// ============================================================================
//
// Approach: Fast Exponentiation (Binary Exponentiation)
// - Instead of multiplying x by itself n times (O(n)), we can reduce work
//   by repeatedly squaring (O(log n)).
// - Key idea: 
//     x^n = (x^(n/2))^2   if n is even
//     x^n = x * (x^(n-1)) if n is odd
// - Handle negative powers by computing 1 / x^|n|.
//
// Edge Cases:
// - n == 0 -> return 1 (anything to power 0 is 1).
// - n < 0  -> invert result: 1 / myPow(x, -n).
//
// Time Complexity: O(log n)
// Space Complexity: O(1) (iterative solution)
//
// ============================================================================

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= x; 
            }
            x *= x;     
            exp /= 2;         
        }

        return result;
    }
};
