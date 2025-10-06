// ============================================================================
// 641. Design Circular Deque
// Medium
// ============================================================================
//
// Implementation: Fixed-size ring buffer
// - Use vector<int> of capacity k.
// - Track head (index of front), size (current count), cap (k).
// - Front index = head
// - Rear index  = (head + size - 1) % cap
// - Insert at front: head = (head - 1 + cap) % cap; write; size++
// - Insert at last:  tail = (head + size) % cap;  write; size++
//
// All ops are O(1).
// ============================================================================
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> buf;
    int head = 0;
    int sz = 0;
    int cap = 0;

public:
    MyCircularDeque(int k) : buf(k, 0), head(0), sz(0), cap(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + cap) % cap;
        buf[head] = value;
        ++sz;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        int tail = (head + sz) % cap;
        buf[tail] = value;
        ++sz;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        --sz;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        --sz; // effectively drops the last element
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buf[head];
    }

    int getRear() {
        if (isEmpty()) return -1;
        int tailIdx = (head + sz - 1) % cap;
        return buf[tailIdx];
    }

    bool isEmpty() {
        return sz == 0;
    }

    bool isFull() {
        return sz == cap;
    }
};
