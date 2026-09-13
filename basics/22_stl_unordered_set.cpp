/**
 * 22_stl_unordered_set.cpp
 * Topic: std::unordered_set Container (Hash Set)
 * Purpose: Hash-table backed unique collection providing O(1) average lookup and insertion.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::unordered_set` is an associative container that stores unique elements in no particular order.
// Under the hood, it is implemented as a Hash Table with chaining (buckets).
// Elements are hashed into buckets using `std::hash`.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Constant time O(1) average membership check (e.g. "Have we visited this number/state before?").
// - Cycle detection (in linked lists or state spaces).
// - Finding duplicates in an array in O(N) total time.

// ==============================
// 3. DECLARATION
// ==============================
// unordered_set<int> us;
// unordered_set<string> str_us;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - us.insert(x): inserts x if absent -> Average O(1), Worst O(N)
// - us.erase(x): removes x -> Average O(1), Worst O(N)
// - us.find(x): returns iterator to x or `us.end()` -> Average O(1), Worst O(N)
// - us.count(x): returns 1 if present, 0 if not -> Average O(1), Worst O(N)
// - us.size() / us.empty(): -> O(1)
// - us.rehash(n) / us.reserve(n): preallocates buckets to minimize re-hashing -> O(N)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// unordered_set<int> s;
// s.insert(15);
// if (s.find(15) != s.end()) { /* exists */ }
// s.erase(15);

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Insert: Average O(1), Worst Case O(N) (due to hash collisions)
// - Delete: Average O(1), Worst Case O(N)
// - Lookup: Average O(1), Worst Case O(N)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Two Sum problem (check if `target - num` exists in set).
// - Longest Consecutive Sequence (LeetCode 128 - O(N) solution).
// - Word Break / Dictionary lookup.
// - Intersection of Two Arrays.

// ==============================
// 8. COMMON MISTAKES & WORST-CASE CAVEAT
// ==============================
// - ORDER IS NOT PRESERVED: Elements appear in arbitrary bucket order. Never use if sorted output is required.
// - NO LOWER_BOUND / UPPER_BOUND: Binary search operations do NOT exist for unordered containers.
// - THE CODEFORCES HASH COLLISION CAVEAT:
//   In competitive programming (like Codeforces), malicious test cases designed with anti-hash keys
//   can force all insertions into a single bucket, degrading performance to O(N^2) (TLE).
//   In LeetCode/Tech interviews, `unordered_set` is safe and standard.
// - DOES NOT WORK OUT-OF-THE-BOX WITH PAIRS:
//   `unordered_set<pair<int, int>>` will NOT compile because C++ does not provide a default `std::hash` for `pair`.
//   (Use `std::set<pair<int, int>>` instead or define a custom hash).

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 22: std::unordered_set Container ===" << '\n';

    unordered_set<int> visited;
    visited.insert(10);
    visited.insert(20);
    visited.insert(30);

    // Fast O(1) membership check
    int query = 20;
    if (visited.count(query)) {
        cout << query << " has been visited!\n";
    }

    visited.erase(20);
    if (!visited.count(20)) {
        cout << "20 was successfully erased.\n";
    }

    cout << "Elements in unordered_set (arbitrary order): ";
    for (int x : visited) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::unordered_set` provides Average O(1) insert, erase, and lookup via Hash Table.
// 2. Elements are unique, but order is NOT preserved.
// 3. Does not have `lower_bound` or `upper_bound` methods.
// 4. `unordered_set<pair<int, int>>` does not compile natively (use `std::set` instead).
// 5. Ideal for quick visited set tracking in BFS/DFS and O(N) duplicate detection.

