/**
 * 27_algorithms.cpp
 * Topic: High-Value STL Algorithms (<algorithm> & <numeric>)
 * Purpose: Master binary search bounds, permutations, min/max, and reduction algorithms.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. REVERSE, SWAP & ROTATE
// ==============================
// - reverse(first, last): reverses elements in range [first, last). Returns void. O(N).
// - swap(a, b): swaps contents of two variables. Returns void. O(1).
// - rotate(first, middle, last): rotates elements such that `middle` becomes the new first element. O(N).

// ==============================
// 2. MIN, MAX, MIN_ELEMENT & MAX_ELEMENT
// ==============================
// - min(a, b), max(a, b): returns smaller / larger of two values. Returns value. O(1).
// - min({a, b, c, ...}), max({a, b, c, ...}): initializer list versions. O(K).
// - min_element(first, last): returns ITERATOR to smallest element. O(N).
// - max_element(first, last): returns ITERATOR to largest element. O(N).
// Note: Dereference with `*` to get the value: `*max_element(v.begin(), v.end())`.
// Get the index: `max_element(v.begin(), v.end()) - v.begin()`.

// ==============================
// 3. COUNT, FIND, ACCUMULATE & UNIQUE
// ==============================
// - count(first, last, val): returns number of times val appears. Returns int/size_t. O(N).
// - find(first, last, val): returns iterator to first occurrence, or `last` if not found. O(N).
// - accumulate(first, last, init_val): located in <numeric>. Sums elements starting with `init_val`. O(N).
//   IMPORTANT: If sum can exceed 32-bit int, pass `0LL` as initial value: `accumulate(v.begin(), v.end(), 0LL);`.
// - unique(first, last): removes CONSECUTIVE duplicates. Must sort first for total unique!
//   Returns iterator to the new logical end.
//   Erase idiom: `v.erase(unique(v.begin(), v.end()), v.end());` -> O(N).

// ==============================
// 4. BINARY SEARCH, LOWER_BOUND & UPPER_BOUND
// ==============================
// CRITICAL REQUIREMENT: The range MUST BE SORTED beforehand!
//
// 1. binary_search(first, last, val):
//    - Returns: bool (`true` if val exists, `false` otherwise).
//    - Complexity: O(log N) for random-access iterators (vector/array).
//
// 2. lower_bound(first, last, val):
//    - Definition: Returns iterator to the FIRST element that is GREATER THAN OR EQUAL TO (>=) val.
//    - If all elements are < val, returns `last` (e.g. `v.end()`).
//    - Index of element: `lower_bound(...) - v.begin()`.
//
// 3. upper_bound(first, last, val):
//    - Definition: Returns iterator to the FIRST element that is STRICTLY GREATER THAN (>) val.
//    - If no element is > val, returns `last` (e.g. `v.end()`).
//
// 4. Counting occurrences in sorted array:
//    `int frequency = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);`

// ==============================
// 5. NEXT_PERMUTATION & PREV_PERMUTATION
// ==============================
// - next_permutation(first, last): transforms range into the lexicographically next greater permutation.
//   Returns `true` if next permutation exists, `false` if range was already descending (wraps to sorted).
//   Complexity: Amortized O(N).
//   Generating all permutations of N items takes O(N * N!).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 27: STL Algorithms in C++ ===" << '\n';

    // --- 1. Min/Max & Min/Max Element ---
    vector<int> nums = {45, 12, 89, 23, 89, 7};
    auto min_it = min_element(nums.begin(), nums.end());
    auto max_it = max_element(nums.begin(), nums.end());
    cout << "Min element: " << *min_it << " at index " << (min_it - nums.begin()) << '\n';
    cout << "Max element: " << *max_it << " at index " << (max_it - nums.begin()) << '\n';

    // --- 2. Accumulate (with 0LL to prevent overflow) ---
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    cout << "Sum of elements: " << sum << '\n';

    // --- 3. Sorting & Binary Search Bounds ---
    vector<int> sorted_v = {10, 20, 20, 20, 30, 40, 50};
    cout << "\nSorted vector: ";
    for (int x : sorted_v) cout << x << " ";
    cout << '\n';

    bool exists = binary_search(sorted_v.begin(), sorted_v.end(), 30);
    cout << "Does 30 exist? " << boolalpha << exists << '\n';

    // lower_bound (first element >= 20)
    auto lb = lower_bound(sorted_v.begin(), sorted_v.end(), 20);
    int lb_idx = lb - sorted_v.begin();
    cout << "lower_bound(20): points to index " << lb_idx << " (value: " << *lb << ")\n";

    // upper_bound (first element > 20)
    auto ub = upper_bound(sorted_v.begin(), sorted_v.end(), 20);
    int ub_idx = ub - sorted_v.begin();
    cout << "upper_bound(20): points to index " << ub_idx << " (value: " << *ub << ")\n";

    // Count duplicates of 20 via bound subtraction
    int count_20 = ub - lb;
    cout << "Frequency of 20 using (ub - lb): " << count_20 << '\n';

    // --- 4. Unique Idiom ---
    vector<int> dupes = {1, 2, 2, 3, 3, 3, 4};
    dupes.erase(unique(dupes.begin(), dupes.end()), dupes.end());
    cout << "After unique + erase: ";
    for (int x : dupes) cout << x << " ";
    cout << '\n';

    // --- 5. next_permutation demonstration ---
    vector<int> perm = {1, 2, 3};
    cout << "Permutations of {1, 2, 3}:\n";
    do {
        cout << perm[0] << " " << perm[1] << " " << perm[2] << '\n';
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `lower_bound`: first element `>= target`.
// 2. `upper_bound`: first element `> target`.
// 3. Subtract `v.begin()` to convert bound iterators into zero-based array indices: `lb - v.begin()`.
// 4. `accumulate(v.begin(), v.end(), 0LL)`: always use `0LL` as the 3rd argument to avoid 32-bit integer overflow.
// 5. `unique` only collapses consecutive duplicates; array must be sorted first.
// 6. `next_permutation` produces the next lexicographical ordering in O(N).

