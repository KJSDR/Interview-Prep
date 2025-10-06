// ============================================================================
// 622. Design Circular Queue
// Medium
// ============================================================================
//
// Implementation notes:
// - Fixed-size ring buffer using a vector<int> of capacity k.
// - Track:
//     head : index of the current front
//     size : number of elements currently stored
//     cap  : capacity (k)
// - Tail position for insertion = (head + size) % cap
// - Front element index = head
// - Rear element index = (head + size - 1 + cap) % cap
//
// All operations are O(1).
//
// ============================================================================
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> buf;
    int head = 0;
    int sz = 0;
    int cap = 0;

public:
    MyCircularQueue(int k) : buf(k, 0), head(0), sz(0), cap(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        int tail = (head + sz) % cap;
        buf[tail] = value;
        ++sz;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % cap;
        --sz;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buf[head];
    }

    int Rear() {
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
