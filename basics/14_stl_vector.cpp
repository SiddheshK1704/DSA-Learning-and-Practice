/**
 * 14_stl_vector.cpp
 * Topic: std::vector Container
 * Purpose: The foundational dynamic array for competitive programming and DSA.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::vector` is a sequence container that encapsulates dynamic arrays.
// It stores elements contiguously in heap memory. As elements are added, it automatically
// reallocates storage, usually doubling its capacity when full.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Primary container for arrays where size is unknown at compile time.
// - Supports O(1) indexed access and fast amortized O(1) append/pop at the end.
// - Easily represents graphs (adjacency lists: `vector<vector<int>> adj`), grids, and DP tables.

// ==============================
// 3. DECLARATION
// ==============================
// vector<int> v;                        // Empty vector
// vector<int> v(n, 0);                 // Size n initialized with 0
// vector<vector<int>> matrix(r, vector<int>(c, 0)); // r x c 2D matrix

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - push_back(val): append to end -> Amortized O(1)
// - pop_back(): remove last element -> O(1)
// - operator[](i): direct access without bounds check -> O(1)
// - at(i): bounds-checked access -> O(1)
// - size(): element count -> O(1)
// - empty(): checks if empty -> O(1)
// - clear(): removes all elements -> O(N)
// - resize(n, val): alters size -> O(N)
// - reserve(cap): reserves internal capacity to prevent reallocations -> O(N)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// vector<int> v;
// v.push_back(10);
// v.pop_back();
// if (!v.empty()) int x = v.back();

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Random Access: O(1)
// - Insertion / Deletion at the end: Amortized O(1)
// - Insertion / Deletion in middle or front: O(N) (requires element shifting)
// - Search in unsorted vector: O(N)
// - Search in sorted vector (binary search): O(log N)
// - Auxiliary Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Adjacency lists for graph algorithms (BFS, DFS, Dijkstra).
// - Dynamic Programming 1D/2D memoization tables.
// - Monotonic stacks / queues implemented on top of vectors.
// - Prefix sum arrays.

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Passing `vector<int>` by value into recursive calls -> causes O(N) copy each call leading to MLE/TLE.
// - Accessing `v[i]` on an uninitialized empty vector (`vector<int> v; v[0] = 5;` -> CRASH).
//   Must use `push_back(5)` or pre-size `vector<int> v(1);`.
// - Vector of bool (`vector<bool>`) is bit-compressed in standard C++; it does not return standard `bool&` references.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 14: std::vector Container ===" << '\n';

    // Graph Adjacency List Example: 3 nodes (0, 1, 2)
    int nodes = 3;
    vector<vector<int>> adj(nodes);

    // Add undirected edge 0 - 1 and 1 - 2
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);

    cout << "Adjacency List:\n";
    for (int u = 0; u < nodes; u++) {
        cout << "Node " << u << " is connected to: ";
        for (int v : adj[u]) cout << v << " ";
        cout << '\n';
    }

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::vector` is the default container for arrays, matrices, and graphs in DSA.
// 2. `push_back` and `pop_back` run in O(1) amortized time.
// 3. Always pass by reference (`vector<int>& v`) to avoid expensive memory copying.
// 4. Do not use `v[i]` unless `v` has already been allocated at least `i + 1` elements.

