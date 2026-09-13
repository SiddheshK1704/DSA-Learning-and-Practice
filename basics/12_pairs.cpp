/**
 * 12_pairs.cpp
 * Topic: std::pair and Nested Pairs
 * Purpose: Group related data together without creating custom classes (e.g. coordinates, intervals, graph weights).
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. STD::PAIR DECLARATION & INITIALIZATION
// ==============================
// Explanation:
// `std::pair` couples together two values which may be of different types.
// Members are accessed via `.first` and `.second`.
//
// Syntax:
// pair<int, int> p1 = {10, 20};          // C++11 list initialization (cleanest)
// pair<string, int> p2 = make_pair("A", 1); // Legacy / helper syntax
// pair<int, pair<int, int>> nested;     // 3-tuple representation

// ==============================
// 2. PAIR COMPARISONS & SORTING BEHAVIOR
// ==============================
// Explanation:
// `std::pair` has built-in lexicographical comparison operators (`<`, `==`):
// - Compares `.first` first.
// - If `.first` values are equal, breaks the tie by comparing `.second`.
// This makes sorting a `vector<pair<int, int>>` effortless in DSA!

// ==============================
// 3. COMMON DSA USE CASES
// ==============================
// 1. Coordinates on a 2D grid: `{row, col}`
// 2. Intervals: `{start_time, end_time}`
// 3. Graph edges with weights: `{weight, destination_node}`
// 4. Frequency pairs: `{element, count}`

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 12: std::pair in C++ ===" << '\n';

    // --- 1. Basic Pair Access ---
    pair<int, string> student = {101, "Alice"};
    cout << "ID: " << student.first << ", Name: " << student.second << '\n';

    // Modifying pair values
    student.first = 102;
    student.second = "Bob";
    cout << "Updated: ID " << student.first << ", Name: " << student.second << '\n';

    // --- 2. Nested Pair (3 elements: {x, y, weight}) ---
    pair<int, pair<int, int>> point_3d = {1, {2, 3}};
    cout << "3D Point: (" << point_3d.first << ", " 
         << point_3d.second.first << ", " 
         << point_3d.second.second << ")\n";

    // --- 3. Vector of Pairs & Default Sorting ---
    // Notice intervals: {1, 4}, {2, 3}, {1, 2}
    vector<pair<int, int>> intervals = {{1, 4}, {2, 3}, {1, 2}};
    
    cout << "\nBefore sorting:\n";
    for (auto& p : intervals) cout << "{" << p.first << ", " << p.second << "} ";
    cout << '\n';

    // Default sort sorts by .first, then by .second
    sort(intervals.begin(), intervals.end());

    cout << "After sorting (by first, tie-break by second):\n";
    for (auto& p : intervals) cout << "{" << p.first << ", " << p.second << "} ";
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Declare and initialize with braces: `pair<int, int> p = {x, y};`.
// 2. Access elements with `p.first` and `p.second`.
// 3. Pairs compare naturally: `p1 < p2` checks `p1.first < p2.first`; if equal, checks `p1.second < p2.second`.
// 4. In `vector<pair<int, int>>`, `sort()` sorts by `.first` ascending, and by `.second` ascending for ties.
// 5. Use nested pairs `pair<int, pair<int, int>>` for 3-tuples without declaring a struct.

