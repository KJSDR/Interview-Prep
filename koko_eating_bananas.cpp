//875. Koko Eating Bananas
//Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
//If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.

//GIVEN:
//- Array piles where piles[i] represents bananas in the ith pile
//- Integer h representing hours until guards return
//- 1 <= piles.length <= 10^4
//- piles.length <= h <= 10^9
//- 1 <= piles[i] <= 10^9
//- Koko eats k bananas per hour from one pile
//- If pile has < k bananas, she eats all and stops for that hour

//OUTPUT:
//- Minimum integer k such that Koko can eat all bananas within h hours

//Example 1:
//Input: piles = [3,6,7,11], h = 8
//Output: 4
//Explanation: With k=4, times needed: [1,2,2,3] = 8 hours total

//Example 2:
//Input: piles = [30,11,23,4,20], h = 5
//Output: 30
//Explanation: With k=30, times needed: [1,1,1,1,1] = 5 hours total

//Example 3:
//Input: piles = [30,11,23,4,20], h = 6
//Output: 23
//Explanation: With k=23, times needed: [2,1,1,1,1] = 6 hours total


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }
            
            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};