/**
 * 18_stl_deque.cpp
 * Topic: std::deque Container (Double-Ended Queue)
 * Purpose: Sequence container supporting fast O(1) push and pop from BOTH ends.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::deque` (double-ended queue, pronounced "deck") is an indexed sequence container that allows
// fast O(1) insertion and deletion at both its beginning and its end.
// Unlike `std::vector`, elements are not stored in a single contiguous chunk, but across multiple fixed-size memory blocks.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Ideal when you need BOTH stack (LIFO) and queue (FIFO) behaviors simultaneously.
// - Essential for the Monotonic Deque technique in Sliding Window Maximum problems (O(N) time).
// - 0-1 BFS in graphs (pushing 0-weight edges to front, 1-weight edges to back).

// ==============================
// 3. DECLARATION
// ==============================
// deque<int> dq;
// deque<int> dq(n, 0);

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - dq.push_back(x): insert at back -> O(1)
// - dq.push_front(x): insert at front -> O(1)
// - dq.pop_back(): remove from back -> O(1)
// - dq.pop_front(): remove from front -> O(1)
// - dq.front(): access first element -> O(1)
// - dq.back(): access last element -> O(1)
// - dq[i]: indexed access -> O(1)
// - dq.size() / dq.empty(): size & emptiness -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// deque<int> dq;
// dq.push_front(10);
// dq.push_back(20);
// dq.pop_front();
// dq.pop_back();

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Push / Pop Front: O(1)
// - Push / Pop Back: O(1)
// - Random Access (dq[i]): O(1)
// - Insertion / Erase in middle: O(N)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Sliding Window Maximum (LeetCode 239 - Monotonic Queue).
// - 0-1 BFS for shortest path with edge weights 0 and 1.
// - Palindrome checking with two-ended pop.

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Forgetting that deque elements are not stored in a strictly contiguous block;
//   pointer arithmetic across elements is not guaranteed like `std::vector`.
// - Calling `pop_front()` or `pop_back()` on an empty deque.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 18: std::deque Container ===" << '\n';

    deque<int> dq;

    // Both-ends operations
    dq.push_back(20);
    dq.push_front(10);
    dq.push_back(30);
    dq.push_front(5);

    // Current deque: 5, 10, 20, 30
    cout << "Deque elements: ";
    for (int x : dq) cout << x << " ";
    cout << '\n';

    cout << "Front: " << dq.front() << ", Back: " << dq.back() << '\n';

    dq.pop_front(); // removes 5
    dq.pop_back();  // removes 30

    cout << "After popping front and back: ";
    for (int x : dq) cout << x << " ";
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::deque` supports O(1) insertions and removals at BOTH front and back.
// 2. Supports direct random access `dq[i]` in O(1) time.
// 3. The standard tool for 0-1 BFS and monotonic sliding window maximum algorithms.
// 4. Always ensure `!dq.empty()` before popping or accessing front/back.

