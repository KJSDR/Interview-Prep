// ============================================================================
// 225. Implement Stack using Queues
// Easy
// ============================================================================
//
// Problem Statement:
// Implement a last-in-first-out (LIFO) stack using only two queues.
//
// Implement the MyStack structure with functions:
//   - myStackPush(MyStack*, int)
//   - myStackPop(MyStack*)
//   - myStackTop(MyStack*)
//   - myStackEmpty(MyStack*)
//   - myStackFree(MyStack*)
//
// Only standard queue operations are allowed: push to back, pop/peek from front,
// size, and isEmpty.
//
// -----------------------------------------------------------------------------
// Example:
// Input:
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
//
// Output:
// [null, null, null, 2, 2, false]
//
// -----------------------------------------------------------------------------
// Constraints:
// 1 <= x <= 9
// At most 100 calls will be made to push, pop, top, and empty.
// All calls to pop and top are valid.
//
// ============================================================================
//
// Approach: Two Queues
// -----------------------------------------------------------------------------
// Maintain two queues (q1, q2):
//   - push(x): enqueue x to q2, move all elements from q1 to q2, then swap.
//   - pop(): dequeue from q1.
//   - top(): return front of q1.
//   - empty(): check if q1 is empty.
//
// Time Complexity:
//   push: O(n)
//   pop, top, empty: O(1)
// Space Complexity: O(n)
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// -----------------------------------------------------------------------------
// Queue Implementation
// -----------------------------------------------------------------------------
struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
};

void queueInit(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool queueEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, int x) {
    if (q->size == MAX_SIZE) return;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = x;
    q->size++;
}

int dequeue(struct Queue* q) {
    if (queueEmpty(q)) return -1;
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int queueFront(struct Queue* q) {
    if (queueEmpty(q)) return -1;
    return q->data[q->front];
}

// -----------------------------------------------------------------------------
// Stack Using Two Queues
// -----------------------------------------------------------------------------
typedef struct {
    struct Queue q1;
    struct Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    queueInit(&obj->q1);
    queueInit(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);
    while (!queueEmpty(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }
    struct Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return queueFront(&obj->q1);
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
