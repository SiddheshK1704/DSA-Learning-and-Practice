/**
 * 24_stl_unordered_map.cpp
 * Topic: std::unordered_map Container (Hash Map)
 * Purpose: Hash Table key-value store with average O(1) time complexity; workhorse of frequency counting.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::unordered_map` is an associative container that stores key-value pairs with unique keys.
// Keys are organized into buckets using hash functions. Keys are NOT kept in sorted order.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - The single most common container for frequency counting and hash lookups in interview problems.
// - Average O(1) time complexity for insertion, access, and deletion.
// - Caching / Memoization in dynamic programming (e.g., top-down recursion with state memoization).

// ==============================
// 3. DECLARATION
// ==============================
// unordered_map<int, int> freq;
// unordered_map<string, vector<string>> anagram_groups;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - mp[key]: accesses/inserts key -> Average O(1), Worst O(N)
// - mp.find(key): returns iterator to key or `mp.end()` -> Average O(1)
// - mp.count(key): returns 1 or 0 -> Average O(1)
// - mp.erase(key): removes key and value -> Average O(1)
// - mp.size() / mp.empty(): -> O(1)
// - mp.reserve(N): preallocates space for N elements to prevent repeated rehashing -> O(N)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// unordered_map<int, int> count;
// for (int x : arr) count[x]++;
// if (count.find(target) != count.end()) { /* found */ }

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Insert / Access / Erase: Average O(1), Worst Case O(N) (due to hash collisions)
// - Iteration through all elements: O(N)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Two Sum (LeetCode 1: storing complements).
// - Subarray Sum Equals K (prefix sum hash map pattern).
// - Group Anagrams (mapping sorted strings to lists of words).
// - Frequency array / Most Frequent Element.

// ==============================
// 8. COMMON MISTAKES & WORST-CASE CAVEAT
// ==============================
// - HASH COLLISION TLE IN COMPETITIVE PROGRAMMING:
//   Default `std::hash<int>` in GCC is identity hash (`hash(x) = x`). Malicious inputs constructed
//   using modulo of table size cause all elements to collide into a single bucket, making lookups O(N)
//   and total time O(N^2) (Time Limit Exceeded on Codeforces).
//   For standard technical interviews (LeetCode), `unordered_map` is completely safe and preferred.
// - DOES NOT SUPPORT PAIRS AS KEYS DIRECTLY:
//   `unordered_map<pair<int, int>, int>` fails to compile because no default hash exists for `pair`.
//   Use `map<pair<int, int>, int>` or encode coordinates as a 64-bit int: `(1LL * r << 32) | c`.
// - Remember that `mp[key]` inserts the key with default value 0 if not present!

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 24: std::unordered_map Container ===" << '\n';

    // Frequency Counting Pattern (Classic DSA)
    vector<int> nums = {4, 2, 4, 5, 2, 4, 1};
    unordered_map<int, int> freq;

    for (int x : nums) {
        freq[x]++;
    }

    cout << "Element frequencies:\n";
    for (const auto& p : freq) {
        cout << "Element " << p.first << " appears " << p.second << " time(s)\n";
    }

    // Two Sum Pattern Check: find pair with sum 7
    int target_sum = 7;
    unordered_map<int, int> seen_idx;
    bool found_pair = false;

    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target_sum - nums[i];
        if (seen_idx.count(complement)) {
            cout << "Two sum match: " << nums[i] << " (index " << i 
                 << ") and " << complement << " (index " << seen_idx[complement] << ")\n";
            found_pair = true;
            break;
        }
        seen_idx[nums[i]] = i;
    }
    if (!found_pair) cout << "No two sum match found.\n";

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::unordered_map` is the go-to container for frequency counting and O(1) lookups.
// 2. Average time complexity is O(1); worst-case is O(N) on hash collisions.
// 3. `mp[key]++` is the standard frequency counting idiom in C++ DSA.
// 4. Checking existence: use `mp.count(key)` or `mp.find(key) != mp.end()`.
// 5. Pairs cannot be keys unless a custom hash is defined (use `map` for pairs as keys).
