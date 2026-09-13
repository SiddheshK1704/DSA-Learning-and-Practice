/**
 * 11_vectors.cpp
 * Topic: std::vector - Complete DSA Guide
 * Purpose: Master dynamic arrays, 2D vectors, initializations, and time complexities.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IS STD::VECTOR?
// ==============================
// Explanation:
// `std::vector` is a dynamic array that handles automatic memory resizing.
// When capacity is exceeded, it doubles its allocated internal storage.
// It is contiguous in memory, providing O(1) random access by index.
//
// Common Declarations:
// vector<int> v;                       // Empty vector
// vector<int> v(n);                    // Size n, elements initialized to 0
// vector<int> v(n, value);             // Size n, all elements initialized to `value`
// vector<int> v = {1, 2, 3, 4, 5};     // Initializer list

// ==============================
// 2. CORE OPERATIONS & TIME COMPLEXITY
// ==============================
// - v.push_back(x): adds x to the end -> Amortized O(1)
// - v.pop_back(): removes the last element -> O(1)
// - v[i] or v.at(i): access element at index i -> O(1) (at() performs bounds checking)
// - v.front(): reference to first element -> O(1)
// - v.back(): reference to last element -> O(1)
// - v.size(): number of elements -> O(1)
// - v.empty(): checks if size is 0 -> O(1)
// - v.clear(): removes all elements -> O(N)
// - v.resize(new_size): changes number of elements -> O(N)
// - v.reserve(capacity): preallocates memory without creating elements -> O(N)
// - v.insert(pos, val): inserts element before iterator pos -> O(N) (shifts elements)
// - v.erase(pos): removes element at iterator pos -> O(N) (shifts elements)

// ==============================
// 3. ITERATORS: BEGIN() AND END()
// ==============================
// Explanation:
// - `v.begin()`: iterator pointing to the FIRST element (index 0).
// - `v.end()`: iterator pointing to the position PAST the last element (index N).
// The range `[v.begin(), v.end())` is half-open!
// `*v.begin()` gives the first element.
// Dereferencing `*v.end()` is Undefined Behavior!

// ==============================
// 4. 2D VECTORS & VECTOR OF PAIRS
// ==============================
// Explanation:
// - 2D Vector (Matrix): `vector<vector<int>> matrix(rows, vector<int>(cols, init_val));`
// - Vector of Pairs: `vector<pair<int, int>> pairs;` (used for coordinates, weighted edges)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 11: std::vector in C++ ===" << '\n';

    // --- 1. Basic Operations ---
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout << "After 3 pushes, size: " << v.size() << ", back: " << v.back() << '\n';

    v.pop_back(); // removes 30
    cout << "After pop_back, back: " << v.back() << '\n';

    // --- 2. Initializing with size and default value ---
    int n = 5;
    vector<int> filled(n, -1); // 5 elements, all -1
    cout << "Filled vector (size 5, val -1): ";
    for (int x : filled) cout << x << " ";
    cout << '\n';

    // --- 3. Iterators and sorting ---
    vector<int> nums = {40, 10, 50, 20};
    cout << "First element (*nums.begin()): " << *nums.begin() << '\n';
    cout << "Last element (*(nums.end() - 1)): " << *(nums.end() - 1) << '\n';

    sort(nums.begin(), nums.end());
    cout << "Sorted nums: ";
    for (int x : nums) cout << x << " ";
    cout << '\n';

    // --- 4. Erase & Insert (O(N) operations) ---
    // Erase the second element (index 1)
    nums.erase(nums.begin() + 1);
    cout << "After erasing index 1: ";
    for (int x : nums) cout << x << " ";
    cout << '\n';

    // --- 5. 2D Vector (Grid / Matrix) ---
    int rows = 3, cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    grid[1][2] = 7; // Set cell (1, 2)
    cout << "\n3x4 Grid cell (1, 2): " << grid[1][2] << '\n';

    // --- 6. Vector of Pairs (e.g. Graph edge list: {u, weight}) ---
    vector<pair<int, int>> edges;
    edges.push_back({1, 100});
    edges.push_back({2, 250});
    cout << "Vector of pairs first edge: node " << edges[0].first 
         << ", weight " << edges[0].second << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `push_back` and `pop_back` run in O(1) amortized time.
// 2. `insert()` and `erase()` in the middle require shifting and take O(N) time.
// 3. `v.end()` points past the last element; `*(v.end() - 1)` points to the last element.
// 4. Initialize 2D matrices cleanly: `vector<vector<int>> grid(rows, vector<int>(cols, default_val));`.
// 5. Use `v.reserve(N)` if you know the exact capacity needed upfront to prevent repeated reallocations.

