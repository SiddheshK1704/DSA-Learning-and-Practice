/**
 * 23_stl_map.cpp
 * Topic: std::map Container (Ordered Key-Value Map)
 * Purpose: Red-Black Tree backed key-value mapping with keys automatically maintained in sorted order.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::map` is a sorted associative container that contains key-value pairs with UNIQUE keys.
// Keys are sorted according to a comparator (default is `<`).
// Implemented internally as a self-balancing Binary Search Tree (Red-Black Tree).

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Maintains keys in strictly sorted order.
// - Supports range queries and binary-search operations (`lower_bound` / `upper_bound`) on keys.
// - Useful for coordinate compression and sweep-line event processing.

// ==============================
// 3. DECLARATION
// ==============================
// map<string, int> mp;
// map<int, vector<int>> adj_list;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - mp[key]: accesses value; IF KEY DOES NOT EXIST, INSERTS IT WITH DEFAULT VALUE (0, "", etc.) -> O(log N)
// - mp.at(key): access value; throws exception if key doesn't exist -> O(log N)
// - mp.insert({key, val}): inserts pair -> O(log N)
// - mp.erase(key): removes key and its value -> O(log N)
// - mp.find(key): returns iterator or `mp.end()` -> O(log N)
// - mp.count(key): returns 1 if key exists, 0 otherwise -> O(log N)
// - mp.lower_bound(key): iterator to first key >= key -> O(log N)
// - mp.upper_bound(key): iterator to first key > key -> O(log N)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// map<string, int> age;
// age["Alice"] = 25;
// if (age.find("Bob") != age.end()) { /* exists */ }

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Insert: O(log N)
// - Erase: O(log N)
// - Search: O(log N)
// - Traversal in sorted order: O(N)
// - Space: O(N) with tree pointer overhead

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Coordinate Compression (mapping large sparse coordinates to 0..K-1).
// - Time-based key-value store (e.g. Stock Price Fluctuation).
// - Finding ceiling / floor of keys dynamically.

// ==============================
// 8. COMMON MISTAKES (THE OPERATOR[] INSERTION TRAP)
// ==============================
// - Accessing `mp[key]` to check if a key exists!
//   `if (mp[100] == 0)` will INSERT key 100 with default value 0 into the map!
//   Always use `if (mp.find(key) != mp.end())` or `if (mp.count(key))` for non-mutating checks.
// - Using global `std::lower_bound(mp.begin(), mp.end(), key)` (O(N) time) instead of `mp.lower_bound(key)` (O(log N) time).

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 23: std::map (Ordered Key-Value) ===" << '\n';

    map<int, string> roll_call;
    roll_call[103] = "Charlie";
    roll_call[101] = "Alice";
    roll_call[102] = "Bob";

    cout << "Map traversal (keys automatically in ascending order):\n";
    for (const auto& p : roll_call) {
        cout << "Key: " << p.first << " -> Value: " << p.second << '\n';
    }

    // Binary search on keys
    auto it = roll_call.lower_bound(102); // first key >= 102
    if (it != roll_call.end()) {
        cout << "First key >= 102: " << it->first << " (" << it->second << ")\n";
    }

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::map` stores unique key-value pairs sorted by keys via Red-Black Tree.
// 2. All operations (insert, erase, search) take O(log N) time.
// 3. CAUTION: `mp[key]` will insert the key with default value if it is not found.
// 4. Use `mp.find(key) != mp.end()` or `mp.count(key)` for read-only existence checks.
// 5. Always use member `mp.lower_bound(key)` for O(log N) range queries on keys.
