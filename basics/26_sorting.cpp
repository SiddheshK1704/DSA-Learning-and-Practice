/**
 * 26_sorting.cpp
 * Topic: std::sort & Sorting Techniques in C++
 * Purpose: Master IntroSort (O(N log N)), sorting arrays, vectors, strings, and pairs.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. STD::SORT OVERVIEW
// ==============================
// Explanation:
// `std::sort` in `<algorithm>` is an implementation of IntroSort (a hybrid of QuickSort,
// HeapSort, and InsertionSort). It guarantees O(N log N) worst-case time complexity.
// It sorts in non-decreasing (ascending) order by default.

// ==============================
// 2. SORTING VECTORS & ARRAYS
// ==============================
// Syntax:
// Vector:
// sort(v.begin(), v.end());                 // Ascending
// sort(v.rbegin(), v.rend());               // Descending
// sort(v.begin(), v.end(), greater<int>()); // Descending using functor
//
// Raw Array of size N:
// sort(arr, arr + n);                       // Ascending
// sort(arr, arr + n, greater<int>());       // Descending

// ==============================
// 3. SORTING STRINGS
// ==============================
// Explanation:
// Strings are treated as sequences of characters:
// `sort(s.begin(), s.end());` rearranges characters in ASCII order (e.g. "cab" -> "abc").
// This is the classic technique for detecting anagrams.

// ==============================
// 4. SORTING PAIRS (DEFAULT BEHAVIOR)
// ==============================
// Explanation:
// When sorting `vector<pair<int, int>>`:
// 1. Compares `.first` first (ascending).
// 2. If `.first` values are tied, compares `.second` (ascending).
// This built-in tie-breaking behavior is extremely convenient for interval scheduling and coordinate sorting.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 26: Sorting in C++ ===" << '\n';

    // --- 1. Sorting a Vector (Ascending & Descending) ---
    vector<int> v = {40, 10, 50, 20, 30};
    sort(v.begin(), v.end());
    cout << "Vector sorted ascending: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    sort(v.rbegin(), v.rend());
    cout << "Vector sorted descending (rbegin/rend): ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    // --- 2. Sorting a Raw C-style Array ---
    int arr[] = {9, 3, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Raw array sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << '\n';

    // --- 3. Sorting Strings (Anagram check) ---
    string s = "dcba";
    sort(s.begin(), s.end());
    cout << "String sorted: " << s << '\n';

    // --- 4. Sorting Pairs (Demonstrating tie-breaking) ---
    vector<pair<int, int>> intervals = {{2, 5}, {1, 9}, {1, 3}, {2, 1}};
    sort(intervals.begin(), intervals.end());

    cout << "Pairs sorted by default (<first, second>):\n";
    for (const auto& p : intervals) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::sort` provides guaranteed O(N log N) worst-case time complexity.
// 2. Vectors: `sort(v.begin(), v.end())` (ascending) and `sort(v.rbegin(), v.rend())` (descending).
// 3. Raw arrays: `sort(arr, arr + n)`.
// 4. Strings: `sort(s.begin(), s.end())` sorts characters in ASCII order (anagram signature).
// 5. Default pair sorting breaks ties in `.first` using `.second` in ascending order.
