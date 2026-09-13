/**
 * 19_stl_priority_queue.cpp
 * Topic: std::priority_queue (Binary Heap)
 * Purpose: Max-heap and Min-heap implementations for Top-K problems, Dijkstra, and greedy scheduling.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::priority_queue` is a container adapter that provides constant-time lookup of the
// largest (by default) element, at the expense of logarithmic insertion and extraction.
// Under the hood, it is implemented as a binary max-heap over `std::vector`.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Finding the K-th Largest or K-th Smallest element efficiently without full sorting.
// - Dijkstra's Shortest Path Algorithm (using Min-Heap).
// - Prim's Minimum Spanning Tree Algorithm.
// - Merging K Sorted Lists / Arrays.
// - Huffman coding and greedy scheduling.

// ==============================
// 3. DECLARATION (MAX HEAP VS MIN HEAP)
// ==============================
// 1. MAX HEAP (Default):
//    The largest element stays at the top.
//    priority_queue<int> max_pq;
//
// 2. MIN HEAP:
//    The smallest element stays at the top.
//    Takes 3 template arguments: <Type, Container, Comparator>
//    priority_queue<int, vector<int>, greater<int>> min_pq;
//
// 3. MIN HEAP FOR PAIRS (e.g., Dijkstra: {distance, node}):
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - pq.push(val): inserts element into heap -> O(log N)
// - pq.emplace(args): constructs in-place -> O(log N)
// - pq.pop(): removes top element -> O(log N)
// - pq.top(): reference to top (max or min) element -> O(1)
// - pq.size() / pq.empty(): -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// priority_queue<int> max_heap;
// max_heap.push(10);
// max_heap.push(50);
// int highest = max_heap.top(); // 50
// max_heap.pop();

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Push: O(log N)
// - Pop: O(log N)
// - Top: O(1)
// - Building a heap from N elements: O(N) (via constructor: pq(v.begin(), v.end()))
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Kth Largest Element in an Array (maintain min-heap of size K -> O(N log K)).
// - Merge K Sorted Lists.
// - Find Median from Data Stream (Two Heaps pattern: max-heap for lower half, min-heap for upper half).
// - Dijkstra's Algorithm for Shortest Path.

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Calling `pq.top()` or `pq.pop()` on an empty priority_queue -> CRASH!
// - Forgetting that priority_queue uses `.top()`, NOT `.front()`.
// - Confusing `greater<int>` (which creates a MIN-heap) with `less<int>` (which creates a MAX-heap).
//   Intuition: `greater<T>` means smaller items have higher priority.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 19: std::priority_queue (Heaps) ===" << '\n';

    // --- 1. Max Heap Demonstration ---
    priority_queue<int> max_heap;
    vector<int> data = {15, 10, 50, 30, 25};
    for (int x : data) max_heap.push(x);

    cout << "Max Heap extraction (descending order): ";
    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << '\n';

    // --- 2. Min Heap Demonstration ---
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int x : data) min_heap.push(x);

    cout << "Min Heap extraction (ascending order): ";
    while (!min_heap.empty()) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << '\n';

    // --- 3. K-th Largest Element using Min-Heap of size K ---
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> top_k_heap;
    for (int x : data) {
        top_k_heap.push(x);
        if ((int)top_k_heap.size() > k) {
            top_k_heap.pop();
        }
    }
    cout << "The " << k << "rd largest element in data is: " << top_k_heap.top() << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Default `priority_queue<int>` is a MAX-HEAP (largest element on top).
// 2. To get a MIN-HEAP: `priority_queue<int, vector<int>, greater<int>> min_pq;`.
// 3. Inspect the top with `pq.top()` (O(1)), push and pop take O(log N).
// 4. For "K-th largest", use a min-heap of size K.
// 5. Always ensure `!pq.empty()` before calling `pq.top()` or `pq.pop()`.

