/**
 * 06_loops.cpp
 * Topic: Loops & Iterations in C++
 * Purpose: Master traversal patterns, reverse loops, pointer movements, and avoid off-by-one errors.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. FOR LOOPS (FORWARD, REVERSE, CUSTOM STEP)
// ==============================
// Explanation:
// Used when the number of iterations is known in advance.
//
// Syntax:
// for (initialization; condition; update) { ... }
//
// Forward: for (int i = 0; i < n; i++)
// Reverse: for (int i = n - 1; i >= 0; i--)
// Step by 2: for (int i = 0; i < n; i += 2)
// Multiplicative (e.g. logarithmic power iterations): for (int i = 1; i <= n; i *= 2)
//
// Critical Off-by-One Pitfalls:
// - Reverse loop mistake: `for (int i = n; i > 0; i--)` misses index 0 and tries to access index n (out-of-bounds)!
// - Unsigned integer underflow trap in reverse:
//   `for (size_t i = n - 1; i >= 0; i--)` will loop INFINITELY because unsigned values cannot be negative;
//   when 0 decrements, it wraps around to 18,446,744,073,709,551,615!
//   ALWAYS use signed `int` for reverse index loops.

// ==============================
// 2. WHILE LOOPS (TWO POINTERS, LINKED LISTS, BINARY SEARCH)
// ==============================
// Explanation:
// Used when iteration continues until an unknown condition is met (e.g., `left <= right` in binary search,
// or `curr != nullptr` in linked lists).
//
// Syntax:
// while (condition) {
//     // update state
// }

// ==============================
// 3. DO-WHILE LOOPS
// ==============================
// Explanation:
// Guarantees that the loop body runs AT LEAST ONCE before evaluating the condition.
// Rarely needed in standard algorithmic problems, but good to know for menu-driven input.

// ==============================
// 4. BREAK AND CONTINUE
// ==============================
// Explanation:
// `break`: Immediately exits the innermost enclosing loop.
// `continue`: Skips the remainder of the current loop iteration and moves to the next loop step.

// ==============================
// 5. NESTED LOOPS & BOUNDARY REASONING
// ==============================
// Explanation:
// Used in matrix traversals, generating pairs, and nested comparisons.
// Unique pairs pattern:
// for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) { ... }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 06: Loops in C++ ===" << '\n';

    vector<int> nums = {10, 20, 30, 40, 50};
    int n = nums.size();

    // --- 1. Forward Traversal ---
    cout << "Forward traversal: ";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << '\n';

    // --- 2. Reverse Traversal (Notice signed int to avoid underflow) ---
    cout << "Reverse traversal: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << nums[i] << " ";
    }
    cout << '\n';

    // --- 3. Custom Increments (Geometric progression O(log N)) ---
    cout << "Powers of 2 up to 32: ";
    for (int i = 1; i <= 32; i *= 2) {
        cout << i << " ";
    }
    cout << '\n';

    // --- 4. While Loop: Two Pointers Pattern ---
    cout << "Two pointers inward scan: ";
    int left = 0, right = n - 1;
    while (left < right) {
        cout << "(" << nums[left] << ", " << nums[right] << ") ";
        left++;
        right--;
    }
    cout << '\n';

    // --- 5. Break & Continue Example ---
    cout << "Odd numbers skipping 30: ";
    for (int x : nums) {
        if (x == 30) continue; // skip 30
        if (x > 45) break;     // stop loop
        cout << x << " ";
    }
    cout << '\n';

    // --- 6. Nested Loop for Generating Unique Pairs ---
    cout << "Unique pairs (i < j): ";
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            cout << "[" << nums[i] << "," << nums[j] << "] ";
        }
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Forward loops start at `0` and terminate when `i < n`.
// 2. Reverse loops start at `n - 1` and terminate when `i >= 0`.
// 3. NEVER use `unsigned int` or `size_t` for reverse loops (`i >= 0` will cause infinite loop on underflow).
// 4. `while` loops are standard for two-pointer, binary search, and linked-list traversals.
// 5. `break` terminates the innermost loop; `continue` skips to the next iteration.

