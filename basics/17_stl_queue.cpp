/**
 * 17_stl_queue.cpp
 * Topic: std::queue Container
 * Purpose: FIFO (First-In, First-Out) adapter used for Breadth-First Search (BFS) and order processing.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::queue` is a container adapter designed for FIFO (First-In, First-Out) storage.
// Elements are pushed into the back and extracted from the front.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Breadth-First Search (BFS) on trees and graphs.
// - Level-order tree traversal.
// - Shortest path in unweighted graphs.
// - Task scheduling and sliding window buffers.

// ==============================
// 3. DECLARATION
// ==============================
// queue<int> q;
// queue<pair<int, int>> coordinate_queue;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - q.push(val): inserts element at back -> O(1)
// - q.pop(): removes element from front (returns void!) -> O(1)
// - q.front(): reference to oldest element (front) -> O(1)
// - q.back(): reference to newest element (back) -> O(1)
// - q.empty(): checks if queue is empty -> O(1)
// - q.size(): number of elements -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// queue<int> q;
// q.push(1);
// q.push(2);
// int head = q.front();
// q.pop();

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Push: O(1)
// - Pop: O(1)
// - Front / Back: O(1)
// - Size / Empty: O(1)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Binary Tree Level Order Traversal (BFS)
// - Shortest Path in a Binary Matrix
// - Rotting Oranges (Multi-source BFS)
// - Implementing Stack using Queues

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Calling `q.front()` or `q.pop()` on an empty queue -> Segmentation fault / crash!
//   Always guard with `while (!q.empty())`.
// - Confusing `q.front()` (queue) with `st.top()` (stack). Queue uses `front()`, stack uses `top()`.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 17: std::queue Container ===" << '\n';

    // BFS simulation pattern
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue front: " << q.front() << ", Queue back: " << q.back() << '\n';

    cout << "Processing queue in FIFO order: ";
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::queue` operates strictly on FIFO (First-In, First-Out).
// 2. Elements enter via `push()` at the back and leave via `pop()` from the front.
// 3. Inspect the front element with `q.front()`; inspect the back with `q.back()`.
// 4. Always ensure `!q.empty()` before calling `front()` or `pop()`.
// 5. The primary vehicle for Breadth-First Search (BFS) in trees and graphs.

