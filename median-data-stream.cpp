// ============================================================================
// 295. Find Median from Data Stream
// Hard
// ============================================================================
//
// Problem Statement:
// Design a data structure that supports adding integers from a stream and
// returning the median of all elements so far.
//
// Median:
// - If count is odd: middle element of the sorted order
// - If count is even: average of the two middle elements
//
// -----------------------------------------------------------------------------
// Examples:
//
// Example 1:
// Input:
// ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
// [[],[1],[2],[],[3],[]]
// Output: [null,null,null,1.5,null,2.0]
//
// -----------------------------------------------------------------------------
// Constraints:
// -10^5 <= num <= 10^5
// There will be at least one element before calling findMedian().
// At most 5 * 10^4 total calls.
//
// ============================================================================
//
// Approach: Two Heaps (Max-Heap + Min-Heap)
// -----------------------------------------------------------------------------
// Maintain two heaps:
//   • maxHeap (lower half) stores the smaller half of numbers (top = largest of lower half)
//   • minHeap (upper half) stores the larger half of numbers (top = smallest of upper half)
//
// Invariants:
//   1) size(maxHeap) == size(minHeap)  OR  size(maxHeap) == size(minHeap) + 1
//      (we keep maxHeap either equal in size or one element larger)
//   2) All elements in maxHeap <= all elements in minHeap
//
// addNum(x):
//   • Push x into the appropriate heap (start with maxHeap).
//   • Move top from maxHeap to minHeap if order is violated (maxHeap.top() > minHeap.top()).
//   • Rebalance sizes so that invariant (1) holds.
//
// findMedian():
//   • If sizes equal: median = (maxHeap.top() + minHeap.top()) / 2.0
//   • Else: median = maxHeap.top()
//
// Time Complexity:
//   • addNum: O(log n) due to heap insert/rebalance
//   • findMedian: O(1)
// Space: O(n)
//
// ============================================================================

#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class MedianFinder {
private:
    
    priority_queue<int> maxHeap;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top(); minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a);
        }

        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            
            return static_cast<double>(maxHeap.top());
        }
    }
};
