/**
 * 21_stl_multiset.cpp
 * Topic: std::multiset Container (Ordered Multi-Set)
 * Purpose: Red-Black Tree allowing duplicate elements in sorted order; sliding window median/max problems.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::multiset` is an associative container that stores multiple elements with equivalent values
// in sorted order. Like `std::set`, it is backed by a balanced binary search tree (Red-Black Tree).

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - When you need sorted order AND need to keep track of duplicates.
// - Sliding window problems where elements enter and leave dynamically while needing min/max/median.
// - Maintaining dynamic collections where duplicates carry distinct significance.

// ==============================
// 3. DECLARATION
// ==============================
// multiset<int> ms;
// multiset<int, greater<int>> desc_ms;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - ms.insert(x): inserts value x (duplicates permitted) -> O(log N)
// - ms.count(x): returns count of occurrences of x -> O(count + log N)
// - ms.find(x): returns iterator to the FIRST instance of x -> O(log N)
// - ms.erase(val): ERASES ALL OCCURRENCES OF val! -> O(count + log N)
// - ms.erase(iterator): ERASES ONLY THE SINGLE ELEMENT POINTED TO -> Amortized O(1)
// - ms.lower_bound(x) / ms.upper_bound(x): -> O(log N)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// multiset<int> ms;
// ms.insert(10);
// ms.insert(10);
// // Erase ONLY ONE occurrence of 10:
// auto it = ms.find(10);
// if (it != ms.end()) ms.erase(it);

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Insert: O(log N)
// - Erase by iterator: Amortized O(1)
// - Erase by value: O(k + log N) where k is the number of duplicates
// - Find: O(log N)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Sliding Window Median (LeetCode 480).
// - Finding dynamic minimum/maximum in a rolling window with duplicates.

// ==============================
// 8. COMMON MISTAKES (THE #1 MULTISET TRAP)
// ==============================
// - Calling `ms.erase(10)` thinking it deletes one 10. IT DELETES EVERY 10 IN THE ENTIRE MULTISET!
//   TO DELETE JUST ONE INSTANCE: `ms.erase(ms.find(10));` (always verify `ms.find(10) != ms.end()`).
// - Calling `ms.count(x)` when checking existence; if there are 10^5 duplicates, `ms.count(x)` is O(K),
//   causing TLE. Use `ms.find(x) != ms.end()` (O(log N)) instead.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 21: std::multiset Container ===" << '\n';

    multiset<int> ms;
    ms.insert(10);
    ms.insert(20);
    ms.insert(10);
    ms.insert(30);
    ms.insert(10);

    cout << "Initial multiset: ";
    for (int x : ms) cout << x << " ";
    cout << '\n';

    // --- Correct way: Erase exactly ONE instance of 10 ---
    auto it = ms.find(10);
    if (it != ms.end()) {
        ms.erase(it); // Erases only the single node
    }
    cout << "After erasing ONE 10 via iterator: ";
    for (int x : ms) cout << x << " ";
    cout << '\n';

    // --- Trap demonstration: Erase by value erases ALL instances of 10 ---
    ms.erase(10); // Removes all remaining 10s!
    cout << "After ms.erase(10) by value: ";
    for (int x : ms) cout << x << " ";
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::multiset` keeps elements sorted and permits duplicate values.
// 2. CRITICAL: `ms.erase(val)` removes ALL instances of `val`.
// 3. To erase a SINGLE occurrence: `ms.erase(ms.find(val));`.
// 4. Do NOT use `ms.count(x)` to check existence (can be O(N) with many duplicates); use `ms.find(x) != ms.end()` (O(log N)).

