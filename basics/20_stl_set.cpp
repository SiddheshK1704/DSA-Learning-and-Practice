/**
 * 20_stl_set.cpp
 * Topic: std::set Container (Ordered Unique Set)
 * Purpose: Self-balancing BST (Red-Black Tree) storing unique elements in sorted order with O(log N) operations.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::set` is an associative container containing an ordered set of UNIQUE objects of type Key.
// Under the hood, it is implemented as a self-balancing Binary Search Tree (typically a Red-Black Tree).
// Elements are always maintained in strictly ascending sorted order.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Automatic elimination of duplicates while keeping items sorted.
// - Supports logarithmic queries for nearest smaller/larger elements via `lower_bound()` and `upper_bound()`.
// - Efficient dynamic order statistics and range queries.

// ==============================
// 3. DECLARATION
// ==============================
// set<int> s;                       // Ascending order (default)
// set<int, greater<int>> desc_s;    // Descending order

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - s.insert(x): inserts x; ignores if x already exists -> O(log N)
// - s.erase(x): removes value x -> O(log N)
// - s.erase(it): removes element at iterator `it` -> Amortized O(1)
// - s.find(x): returns iterator to x, or `s.end()` if not found -> O(log N)
// - s.count(x): returns 1 if present, 0 if not -> O(log N)
// - s.lower_bound(x): returns iterator to first element >= x -> O(log N)
// - s.upper_bound(x): returns iterator to first element > x -> O(log N)
// - s.size() / s.empty(): -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// set<int> s;
// s.insert(40);
// s.insert(10);
// if (s.find(10) != s.end()) { /* element exists */ }
// auto it = s.lower_bound(25); // finds first element >= 25

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Insert: O(log N)
// - Erase: O(log N)
// - Find / Count: O(log N)
// - Lower / Upper Bound: O(log N)
// - Space: O(N) with tree pointer overhead (~3 pointers + 1 color bit per node)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Finding dynamic predecessor / successor of an element.
// - Keeping track of running unique values in sorted order.
// - Sweep-line geometric algorithms (e.g., Skyline problem).

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Calling global `std::lower_bound(s.begin(), s.end(), val)` instead of the member method `s.lower_bound(val)`.
//   The global version runs in O(N) on sets because set iterators are bidirectional, NOT random-access!
//   ALWAYS call `s.lower_bound(val)` for O(log N)!
// - Trying to modify an element directly via iterator (`*it = 50;` -> COMPILE ERROR, elements in a set are `const`).

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 20: std::set (Ordered Unique) ===" << '\n';

    set<int> s;
    // Insert with duplicates
    s.insert(40);
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicate; ignored

    cout << "Set contents (automatically sorted and unique): ";
    for (int x : s) cout << x << " ";
    cout << '\n';

    // Searching
    int target = 20;
    if (s.find(target) != s.end()) {
        cout << target << " is present in the set.\n";
    }

    // Binary search queries using MEMBER functions
    auto lb = s.lower_bound(15); // first element >= 15
    if (lb != s.end()) {
        cout << "First element >= 15 is: " << *lb << '\n';
    }

    auto ub = s.upper_bound(20); // first element > 20
    if (ub != s.end()) {
        cout << "First element > 20 is: " << *ub << '\n';
    }

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::set` stores elements in sorted order and guarantees uniqueness.
// 2. Underlying structure is a Red-Black Tree (O(log N) for insert, delete, find).
// 3. ALWAYS use member methods: `s.lower_bound(x)` (O(log N)), NEVER `std::lower_bound(s.begin(), s.end(), x)` (O(N)).
// 4. Set elements are read-only (`const`); to update, erase and re-insert.

