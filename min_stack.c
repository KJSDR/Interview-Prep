// ============================================================================
// 155. Min Stack
// Medium
// ============================================================================
//
// Problem Statement:
// Design a stack that supports the following operations in O(1) time:
//   - push(int val): Push element val onto the stack.
//   - pop(): Remove the element on top of the stack.
//   - top(): Get the top element.
//   - getMin(): Retrieve the minimum element in the stack.
//
// You must implement each operation with O(1) time complexity.
//
// -----------------------------------------------------------------------------
// Example:
//
// Input:
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
//
// Output:
// [null,null,null,null,-3,null,0,-2]
//
// Explanation:
// MinStack* minStack = minStackCreate();
// minStackPush(minStack, -2);
// minStackPush(minStack, 0);
// minStackPush(minStack, -3);
// minStackGetMin(minStack); // returns -3
// minStackPop(minStack);
// minStackTop(minStack);    // returns 0
// minStackGetMin(minStack); // returns -2
//
// -----------------------------------------------------------------------------
// Constraints:
// -2^31 <= val <= 2^31 - 1
// At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
// All operations pop, top, and getMin will be called on non-empty stacks.
//
// ============================================================================
//
// Approach: Dual-Stack Method
// -----------------------------------------------------------------------------
// Maintain two parallel stacks:
//   - mainStack : stores all pushed values
//   - minStack  : stores the minimum value so far for each level
//
// When pushing:
//   - Push val to mainStack
//   - Push min(val, currentMin) to minStack
//
// When popping:
//   - Pop from both stacks.
//
// The current minimum is always the top of minStack.
//
// Time Complexity: O(1) for all operations
// Space Complexity: O(n)
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 30000

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stackInit(Stack* s) {
    s->top = -1;
}

bool stackEmpty(Stack* s) {
    return s->top == -1;
}

void stackPush(Stack* s, int val) {
    if (s->top < MAX_SIZE - 1)
        s->data[++(s->top)] = val;
}

int stackPop(Stack* s) {
    if (stackEmpty(s)) return -1;
    return s->data[(s->top)--];
}

int stackTop(Stack* s) {
    if (stackEmpty(s)) return -1;
    return s->data[s->top];
}

// -----------------------------------------------------------------------------
// MinStack Implementation
// -----------------------------------------------------------------------------
typedef struct {
    Stack mainStack;
    Stack minStack;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    stackInit(&obj->mainStack);
    stackInit(&obj->minStack);
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    stackPush(&obj->mainStack, val);
    if (stackEmpty(&obj->minStack))
        stackPush(&obj->minStack, val);
    else {
        int currentMin = stackTop(&obj->minStack);
        stackPush(&obj->minStack, val < currentMin ? val : currentMin);
    }
}

void minStackPop(MinStack* obj) {
    stackPop(&obj->mainStack);
    stackPop(&obj->minStack);
}

int minStackTop(MinStack* obj) {
    return stackTop(&obj->mainStack);
}

int minStackGetMin(MinStack* obj) {
    return stackTop(&obj->minStack);
}

void minStackFree(MinStack* obj) {
    free(obj);
}
