// ============================================================================
// 232. Implement Queue using Stacks
// Easy
// ============================================================================
//
// Problem:
// Implement a FIFO queue using two stacks with standard stack operations only.
//
// Methods:
//  - push(x): insert element to back
//  - pop(): remove element from front
//  - peek(): view front element
//  - empty(): check if queue is empty
//
// -----------------------------------------------------------------------------
// Approach: Two-Stack Simulation
// -----------------------------------------------------------------------------
// Use two stacks: s_in (input) and s_out (output)
// - push(x): push into s_in
// - pop(): if s_out empty, move all from s_in to s_out, then pop top of s_out
// - peek(): same as pop but only return top
// - empty(): true if both empty
//
// Time Complexity:
// - Amortized O(1) per operation (worst-case O(n) on transfer)
// Space Complexity: O(n)
//
// ============================================================================
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> s_in, s_out;

    void transfer() {
        while (!s_in.empty()) {
            s_out.push(s_in.top());
            s_in.pop();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        s_in.push(x);
    }

    int pop() {
        if (s_out.empty()) transfer();
        int front = s_out.top();
        s_out.pop();
        return front;
    }

    int peek() {
        if (s_out.empty()) transfer();
        return s_out.top();
    }

    bool empty() {
        return s_in.empty() && s_out.empty();
    }
};
