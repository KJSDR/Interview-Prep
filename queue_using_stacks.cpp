// ============================================================================
// 232. Implement Queue using Stacks
// Easy
// ============================================================================
//
// Problem Statement:
// Implement a first-in-first-out (FIFO) queue using only two stacks. The
// implemented queue should support all the functions of a normal queue:
//   - push(x): Push element x to the back of the queue
//   - pop(): Removes the element from the front of the queue and returns it
//   - peek(): Returns the element at the front of the queue
//   - empty(): Returns true if the queue is empty, false otherwise
//
// Notes:
// - Only standard stack operations are allowed: push to top, pop from top,
//   peek/top, size, and isEmpty.
// - You may simulate stacks using standard containers (like std::vector or
//   std::stack).
//
// -----------------------------------------------------------------------------
// Example:
//
// Input:
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
//
// Output:
// [null, null, null, 1, 1, false]
//
// Explanation:
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2]
// myQueue.peek();  // returns 1
// myQueue.pop();   // returns 1, queue becomes [2]
// myQueue.empty(); // returns false
//
// -----------------------------------------------------------------------------
// Constraints:
// 1 <= x <= 9
// At most 100 calls will be made to push, pop, peek, and empty.
// All the calls to pop and peek are valid.
//
// ============================================================================
//
// Approach: Two-Stack Simulation
// -----------------------------------------------------------------------------
// Maintain two stacks:
//   - inStack  : for enqueue (push)
//   - outStack : for dequeue (pop, peek)
//
// Push(x):
//   - Simply push x into inStack.
//
// Pop()/Peek():
//   - If outStack is empty, transfer all elements from inStack to outStack.
//     This reverses the order to achieve FIFO behavior.
//   - Then pop/peek from outStack.
//
// empty():
//   - Queue is empty if both stacks are empty.
//
// Example:
//   push(1), push(2)
//   inStack = [1, 2], outStack = []
//   pop(): transfer → inStack=[], outStack=[2,1]; return top(1)
//
// Time Complexity:
//   - push: O(1)
//   - pop/peek: Amortized O(1)
//   - empty: O(1)
//
// Space Complexity: O(n)
// ============================================================================

#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void transfer() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        if (outStack.empty()) transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
