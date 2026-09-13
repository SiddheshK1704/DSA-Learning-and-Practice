/**
 * 13_stl_array.cpp
 * Topic: std::array Container
 * Purpose: Safe, fixed-size sequence container that wraps raw C-style arrays.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// std::array is a container that encapsulates fixed size arrays.
// Unlike C-style raw arrays, it does not decay to T* automatically when passed to functions,
// knows its own size via `.size()`, supports standard iterators, and provides bounds checking via `.at()`.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - When the size of an array is known at compile-time and strictly fixed (e.g., direction vectors of size 4: dx, dy).
// - Zero memory overhead compared to raw arrays, but with the safety and ergonomics of STL.

// ==============================
// 3. DECLARATION
// ==============================
// Syntax:
// array<Type, Size> arr;
// array<int, 5> arr = {1, 2, 3, 4, 5};
// array<int, 4> dx = {-1, 0, 1, 0};

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - arr[i]: unchecked access -> O(1)
// - arr.at(i): bounds-checked access (throws out_of_range) -> O(1)
// - arr.front(): reference to first element -> O(1)
// - arr.back(): reference to last element -> O(1)
// - arr.size(): number of elements -> O(1)
// - arr.fill(val): sets all elements to val -> O(N)
// - arr.empty(): returns whether size is 0 -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// array<int, 3> a = {10, 20, 30};
// a.fill(0);
// int n = a.size();

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Access (arr[i], arr.at(i)): O(1)
// - Size / Empty / Front / Back: O(1)
// - Fill: O(N)
// - Space: O(N) on the stack (fixed at compile time)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Grid neighbor navigation arrays (dx, dy):
//   const array<int, 4> dr = {-1, 0, 1, 0};
//   const array<int, 4> dc = {0, 1, 0, -1};
// - Storing fixed coordinate tuples or memoization tables with small static bounds.

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Trying to initialize size with a runtime variable: `int n = 5; array<int, n> a;` -> COMPILE ERROR!
//   Size MUST be a compile-time constant or `constexpr`.
// - Confusing `std::array` with `std::vector` (array cannot grow or shrink; no `push_back`).

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 13: std::array in C++ ===" << '\n';

    // Declaration and initialization
    array<int, 5> arr = {10, 20, 30, 40, 50};

    cout << "Size: " << arr.size() << '\n';
    cout << "Front: " << arr.front() << ", Back: " << arr.back() << '\n';

    // Direction arrays for 2D Grid BFS/DFS
    const array<int, 4> dx = {-1, 0, 1, 0};
    const array<int, 4> dy = {0, 1, 0, -1};
    cout << "4-Direction deltas: ";
    for (int i = 0; i < 4; i++) {
        cout << "(" << dx[i] << ", " << dy[i] << ") ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::array<T, N>` requires compile-time constant size `N`.
// 2. Cannot grow or shrink (no `push_back` or `pop_back`).
// 3. Does not decay to a pointer when passed by reference.
// 4. Ideal for fixed constant arrays like 4-direction or 8-direction BFS deltas.

