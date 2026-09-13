/**
 * 28_custom_comparators.cpp
 * Topic: Custom Comparators & Lambda Functions in C++
 * Purpose: Define custom ordering rules for sorting algorithms and priority queues in DSA.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. COMPARATOR PHILOSOPHY (STRICT WEAK ORDERING)
// ==============================
// Explanation:
// In C++, a comparator function `comp(a, b)` must return `true` if element `a` SHOULD APPEAR BEFORE element `b`.
// Otherwise, it returns `false`.
//
// CRITICAL RULE (STRICT WEAK ORDERING):
// If two elements are EQUAL, the comparator MUST return `false`!
// Returning `true` for equal elements violates strict weak ordering and can cause `std::sort`
// to crash with a Segmentation Fault due to infinite recursion!
// Wrong: `return a <= b;`  (CRASH RISK!)
// Right: `return a < b;`

// ==============================
// 2. REGULAR FUNCTION COMPARATOR
// ==============================
// Explanation:
// Sorting pairs by their second element ascending:
bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second < b.second; // smaller second element comes first
    }
    return a.first < b.first;       // tie-breaker: smaller first element comes first
}

// ==============================
// 3. LAMBDA EXPRESSIONS (MODERN C++)
// ==============================
// Explanation:
// Lambdas let you write inline, anonymous functions right where you call `sort()`.
// Syntax:
// `[](const auto& a, const auto& b) { return ...; }`
//
// DSA Use Case: Sorting intervals by end time (Greedy Activity Selection):
// `sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a.second < b.second; });`

// ==============================
// 4. CUSTOM STRUCT SORTING
// ==============================
struct Job {
    int id;
    int deadline;
    int profit;
};

// ==============================
// 5. COMPARATOR FOR PRIORITY_QUEUE (FUNCTOR STRUCT)
// ==============================
// Explanation:
// `std::priority_queue` does NOT take a regular function or lambda easily as a third template argument;
// it requires a struct with an overloaded `operator()`.
// INVERTED LOGIC IN PRIORITY QUEUES:
// A comparator returning `true` for `a < b` produces a MAX-HEAP (largest on top).
// A comparator returning `true` for `a > b` produces a MIN-HEAP (smallest on top).
struct CompareJobs {
    bool operator()(const Job& a, const Job& b) {
        return a.profit < b.profit; // Max-heap: highest profit at top
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 28: Custom Comparators in C++ ===" << '\n';

    // --- 1. Sorting Pairs by Second Element with Function ---
    vector<pair<int, int>> pairs = {{1, 50}, {2, 20}, {3, 40}, {4, 20}};
    sort(pairs.begin(), pairs.end(), compareBySecond);

    cout << "Pairs sorted by .second (with tie-break):\n";
    for (const auto& p : pairs) {
        cout << "{" << p.first << ", " << p.second << "} ";
    }
    cout << '\n';

    // --- 2. Lambda Function Comparator ---
    vector<pair<int, int>> intervals = {{10, 30}, {5, 20}, {15, 25}};
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a.second < b.second; // Ascending by end-time
    });

    cout << "Intervals sorted by end-time with lambda:\n";
    for (const auto& p : intervals) {
        cout << "[" << p.first << ", " << p.second << "] ";
    }
    cout << '\n';

    // --- 3. Sorting Custom Structs with Lambda ---
    vector<Job> jobs = {{1, 4, 70}, {2, 2, 100}, {3, 1, 40}};
    // Sort descending by profit
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    cout << "Jobs sorted descending by profit:\n";
    for (const auto& j : jobs) {
        cout << "Job ID: " << j.id << ", Profit: " << j.profit << '\n';
    }

    // --- 4. Priority Queue with Struct Comparator ---
    priority_queue<Job, vector<Job>, CompareJobs> pq;
    pq.push({1, 4, 70});
    pq.push({2, 2, 100});
    pq.push({3, 1, 40});

    cout << "Priority queue top job (highest profit): Job " 
         << pq.top().id << " with profit " << pq.top().profit << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `comp(a, b)` must return `true` if `a` belongs BEFORE `b`.
// 2. NEVER use `<=` in comparators; equal elements must return `false` to satisfy strict weak ordering.
// 3. Lambdas `[](const auto& a, const auto& b) { return ...; }` are the most convenient way to sort in modern C++.
// 4. `std::priority_queue` requires a functor struct `struct Compare { bool operator()(const T& a, const T& b) { ... } };`.
// 5. In priority queues, `<` creates a Max-Heap; `>` creates a Min-Heap.
