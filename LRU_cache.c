// ============================================================================
// 146. LRU Cache
// Medium
// ============================================================================
//
// Problem Statement:
// Design a data structure that follows the constraints of a Least Recently Used
// (LRU) cache.
//
// Implement the LRUCache structure with:
//   - LRUCache(int capacity): Initialize with positive capacity.
//   - int get(int key): Return the value of the key if it exists, else -1.
//   - void put(int key, int value): Insert or update key-value pair.
//     If the cache exceeds capacity, evict the least recently used key.
//
// Both get and put operations must run in O(1) average time.
//
// -----------------------------------------------------------------------------
// Example:
//
// Input:
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
//
// Output:
// [null,null,null,1,null,-1,null,-1,3,4]
//
// Explanation:
// LRUCache* lRUCache = lRUCacheCreate(2);
// lRUCachePut(lRUCache, 1, 1); // cache = {1=1}
// lRUCachePut(lRUCache, 2, 2); // cache = {1=1, 2=2}
// lRUCacheGet(lRUCache, 1);    // returns 1
// lRUCachePut(lRUCache, 3, 3); // evicts key 2 → cache = {1=1, 3=3}
// lRUCacheGet(lRUCache, 2);    // returns -1 (not found)
// lRUCachePut(lRUCache, 4, 4); // evicts key 1 → cache = {4=4, 3=3}
// lRUCacheGet(lRUCache, 1);    // returns -1
// lRUCacheGet(lRUCache, 3);    // returns 3
// lRUCacheGet(lRUCache, 4);    // returns 4
//
// -----------------------------------------------------------------------------
// Constraints:
// 1 <= capacity <= 3000
// 0 <= key <= 10^4
// 0 <= value <= 10^5
// At most 2 * 10^5 calls will be made to get and put.
//
// ============================================================================
//
// Approach: Doubly Linked List + Hash Map (Direct Array Indexing)
// -----------------------------------------------------------------------------
// - Each node represents a (key, value) pair and participates in a doubly-linked
//   list ordered by recency: most recently used at head, least at tail.
// - The hash map (implemented as direct array of pointers for keys ≤ 10^4)
//   provides O(1) access to nodes.
// - When accessing or inserting a node, move it to the head (most recent).
// - When capacity exceeded, remove from tail (least recent).
//
// Time Complexity: O(1) average per operation
// Space Complexity: O(capacity)
//
// ============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEY 10005

// -----------------------------------------------------------------------------
// Doubly Linked List Node
// -----------------------------------------------------------------------------
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// -----------------------------------------------------------------------------
// LRU Cache Structure
// -----------------------------------------------------------------------------
typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node* map[MAX_KEY]; // hash map (direct addressing)
} LRUCache;

// -----------------------------------------------------------------------------
// Helper Functions
// -----------------------------------------------------------------------------
static Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// detach a node from its current position
static void removeNode(LRUCache* cache, Node* node) {
    if (!node) return;
    if (node->prev) node->prev->next = node->next;
    else cache->head = node->next;

    if (node->next) node->next->prev = node->prev;
    else cache->tail = node->prev;
}

// move a node to the head (most recent)
static void moveToHead(LRUCache* cache, Node* node) {
    if (cache->head == node) return;
    removeNode(cache, node);
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
    if (!cache->tail) cache->tail = node;
}

// remove tail node (least recently used)
static Node* removeTail(LRUCache* cache) {
    Node* tail = cache->tail;
    if (!tail) return NULL;
    removeNode(cache, tail);
    return tail;
}

// -----------------------------------------------------------------------------
// Public API
// -----------------------------------------------------------------------------
LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    for (int i = 0; i < MAX_KEY; i++) cache->map[i] = NULL;
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (key < 0 || key >= MAX_KEY || !obj->map[key]) return -1;
    Node* node = obj->map[key];
    moveToHead(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (key < 0 || key >= MAX_KEY) return;
    Node* node = obj->map[key];
    if (node) {
        node->value = value;
        moveToHead(obj, node);
        return;
    }
    Node* newNode = createNode(key, value);
    obj->map[key] = newNode;
    moveToHead(obj, newNode);
    obj->size++;

    if (obj->size > obj->capacity) {
        Node* tail = removeTail(obj);
        if (tail) {
            obj->map[tail->key] = NULL;
            free(tail);
        }
        obj->size--;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    free(obj);
}
