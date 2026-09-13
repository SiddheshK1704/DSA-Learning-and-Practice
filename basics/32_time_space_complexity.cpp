/**
 * 32_time_space_complexity.cpp
 * Topic: Time & Space Complexity Analysis in DSA
 * Purpose: Understand Big-O notation, analyze loops and recursion, and reference STL complexities.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. BIG-O NOTATION PRIMER
// ==============================
// Big-O describes the asymptotic upper bound of time/space as input size N grows.
// Operation limits in Competitive Programming (1-second time limit allows ~10^8 operations):
// - N <= 10: O(N!) or O(2^N * N) -> Permutations, exhaustive search
// - N <= 20: O(2^N) -> Bitmask DP, subset backtracking
// - N <= 500: O(N^3) -> Floyd-Warshall, 3-nested loops
// - N <= 5,000: O(N^2) -> Nested loops, bubble/selection sort
// - N <= 2 * 10^5: O(N log N) -> Sorting, divide-and-conquer, maps/sets
// - N <= 10^6: O(N) -> Single pass, two pointers, sliding window
// - N > 10^9: O(log N) or O(1) -> Binary search, math formulas

// ==============================
// 2. CODE EXAMPLES FOR EACH COMPLEXITY CLASS
// ==============================

// O(1) - Constant Time: direct indexing, math arithmetic
int getFirst(const vector<int>& v) {
    return v[0];
}

// O(log N) - Logarithmic Time: binary search, halving input each step
int logExample(int n) {
    int steps = 0;
    while (n > 1) {
        n /= 2;
        steps++;
    }
    return steps;
}

// O(N) - Linear Time: single pass loop
long long linearSum(const vector<int>& v) {
    long long total = 0;
    for (int x : v) total += x;
    return total;
}

// O(N log N) - Linearithmic Time: merge sort, heap operations, std::sort
void linearithmicExample(vector<int>& v) {
    sort(v.begin(), v.end());
}

// O(N^2) - Quadratic Time: nested loops
int countPairs(const vector<int>& v) {
    int count = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            count++;
        }
    }
    return count;
}

// ==============================
// 3. COMPACT STL COMPLEXITY REFERENCE TABLE
// ==============================
// +-----------------------+-------------------+--------------------+-------------------+
// | Container             | Access            | Insert             | Delete            |
// +-----------------------+-------------------+--------------------+-------------------+
// | vector                | O(1)              | Amortized O(1) back| O(1) back, O(N) mid|
// | deque                 | O(1)              | O(1) front/back    | O(1) front/back   |
// | stack / queue         | O(1) top/front    | O(1)               | O(1)              |
// | priority_queue (heap) | O(1) top          | O(log N)           | O(log N)          |
// | set / map (BST)       | O(log N)          | O(log N)           | O(log N)          |
// | multiset / multimap   | O(log N)          | O(log N)           | O(log N)          |
// | unordered_set / map   | O(1) avg / O(N) wst| O(1) avg / O(N) wst| O(1) avg / O(N) wst|
// +-----------------------+-------------------+--------------------+-------------------+

// ==============================
// 4. ANALYZING RECURSION & SPACE COMPLEXITY
// ==============================
// Time: Number of recursive nodes * work done per node.
// Space: Max depth of the call stack + any memory allocated along the way.
// - Binary search recursion: Depth = log2(N) -> O(log N) auxiliary space.
// - Tree DFS: Depth = Tree Height (H) -> O(H) auxiliary space (O(N) worst, O(log N) balanced).

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 32: Time & Space Complexity in C++ ===" << '\n';

    vector<int> sample = {5, 2, 8, 1, 9};

    cout << "O(1) first element: " << getFirst(sample) << '\n';
    cout << "O(log N) steps to reduce 64 to 1: " << logExample(64) << '\n';
    cout << "O(N) linear sum: " << linearSum(sample) << '\n';
    cout << "O(N^2) pair count for N=5: " << countPairs(sample) << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. In 1 second, modern competitive programming / LeetCode servers execute roughly ~10^8 basic operations.
// 2. Halving the problem size at each step produces O(log N) time (e.g. binary search).
// 3. Independent nested loops multiply complexities: O(N) * O(M) = O(N * M).
// 4. `unordered_map` has average O(1) but worst case O(N) on hash collisions; `map` is strictly O(log N).
// 5. Space complexity includes both auxiliary memory (vectors, sets) AND the recursive call stack depth.

