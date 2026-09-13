/**
 * 25_iterators.cpp
 * Topic: Iterators & Range-Based For Loops in C++
 * Purpose: Traverse STL containers uniformly and understand modern C++ range loops for DSA.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IS AN ITERATOR?
// ==============================
// Explanation:
// An iterator is an object that acts like a generalized pointer. It points to an element inside
// a container and can be incremented (`++it`) to traverse to the next element.
// Standard Iterators:
// - `v.begin()`: points to the first element.
// - `v.end()`: points ONE PAST the last element (never dereference `v.end()`).
// - `*it`: dereferences the iterator to access the underlying element.

// ==============================
// 2. REVERSE ITERATORS (RBEGIN AND REND)
// ==============================
// Explanation:
// Used to iterate backwards:
// - `v.rbegin()`: points to the LAST element.
// - `v.rend()`: points ONE BEFORE the first element.
// Incrementing a reverse iterator (`++it`) moves BACKWARDS through the container!

// ==============================
// 3. AUTO KEYWORD & CONST_ITERATOR
// ==============================
// Explanation:
// Instead of writing `vector<int>::iterator it = v.begin();`, `auto` lets the compiler
// infer the type automatically: `auto it = v.begin();`.
// `const_iterator` prevents modifying the elements pointed to.

// ==============================
// 4. RANGE-BASED FOR LOOPS (MODERN C++)
// ==============================
// Explanation:
// Modern C++ introduces range-based for loops:
// 1. By Value: `for (auto x : v)` -> creates a copy of each element. Fine for ints/doubles.
// 2. By Reference: `for (auto& x : v)` -> modifies original elements directly.
// 3. By Const Reference: `for (const auto& x : v)` -> ZERO-COPY, read-only! Ideal for strings, pairs, vectors.
// 4. Structured Binding (C++17): `for (auto& [key, val] : map)` -> unpacks pairs/maps cleanly.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 25: Iterators and Range Loops ===" << '\n';

    vector<int> nums = {10, 20, 30, 40, 50};

    // --- 1. Forward Traversal with auto and iterators ---
    cout << "Iterator forward: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << '\n';

    // --- 2. Reverse Traversal with rbegin/rend ---
    cout << "Reverse iterator (rbegin -> rend): ";
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        cout << *it << " "; // Note ++it moves backwards!
    }
    cout << '\n';

    // --- 3. Range-Based For Loop by Value vs Reference ---
    cout << "Range-based for (read-only): ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << '\n';

    // Modifying elements in place using `auto&`
    for (auto& x : nums) {
        x *= 2;
    }
    cout << "After modifying via auto&: ";
    for (const auto& x : nums) {
        cout << x << " ";
    }
    cout << '\n';

    // --- 4. Iteration on Vector of Pairs ---
    vector<pair<string, int>> scores = {{"Alice", 95}, {"Bob", 88}};
    cout << "\nVector of pairs iteration:\n";
    for (const auto& p : scores) {
        cout << p.first << " -> " << p.second << '\n';
    }

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `v.begin()` is the first element; `v.end()` is past-the-end (do not dereference `v.end()`).
// 2. Reverse iterators: `++it` on `rbegin()` walks backwards to `rend()`.
// 3. Use `for (const auto& x : v)` for read-only access to avoid unnecessary copies.
// 4. Use `for (auto& x : v)` when modifying elements in place.
// 5. C++17 structured bindings `for (auto& [a, b] : container)` simplify pair and map traversals.
