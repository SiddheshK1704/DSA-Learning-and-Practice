/**
 * 08_arrays.cpp
 * Topic: Fixed-Size (Static) Arrays & Multidimensional Matrices
 * Purpose: Understand memory layout, zero-based indexing, and common pitfalls in DSA arrays.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. STATIC ARRAY BASICS & ZERO-BASED INDEXING
// ==============================
// Explanation:
// An array is a contiguous block of memory holding elements of the same type.
// C++ arrays use ZERO-BASED INDEXING:
// An array of size N has indices ranging from `0` to `N - 1`.
// Accessing index `N` is out-of-bounds (Undefined Behavior, buffer overflow, or garbage value).
//
// Syntax:
// int arr[5];                     // Uninitialized (contains garbage values if local!)
// int arr[5] = {1, 2, 3, 4, 5};   // Fully initialized
// int arr[5] = {0};               // All elements initialized to 0
// int arr[] = {10, 20, 30};       // Size deduced automatically (size = 3)

// ==============================
// 2. COMPUTING STATIC ARRAY SIZE
// ==============================
// Explanation:
// In C++, static arrays don't have a `.size()` method.
// Size is obtained by `sizeof(arr) / sizeof(arr[0])`.
// Note: When passed to a function, arrays decay to pointers, so `sizeof` will no longer give array size!
// (This is one reason `std::vector` is favored in modern DSA).

// ==============================
// 3. 2D ARRAYS (MATRICES)
// ==============================
// Explanation:
// Stored in row-major order (row by row sequentially in memory).
// Indexing: `matrix[row][col]`.
//
// Syntax:
// int matrix[3][3];
// int grid[2][3] = { {1, 2, 3}, {4, 5, 6} };

// ==============================
// 4. COMMON PITFALLS
// ==============================
// - Declaring huge arrays inside functions: Local stack memory is limited (~1-8MB).
//   An array like `int arr[10000000];` inside `main()` causes Stack Overflow!
//   DSA Rule: Large static arrays (e.g. 10^7) should be declared globally (in the data segment) or use `vector`.
// - Off-by-one errors: Accessing `arr[N]` instead of `arr[N - 1]`.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 08: Arrays in C++ ===" << '\n';

    // --- 1. 1D Array Declaration & Traversal ---
    int arr[5] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements (1D): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    // Updating an element
    arr[2] = 99; // Replace 30 with 99
    cout << "After update, arr[2] = " << arr[2] << '\n';

    // --- 2. 2D Array (Matrix) Demonstration ---
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "\n2D Matrix (3x3):\n";
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << '\n';
    }

    // --- 3. Matrix Traversal: Main Diagonal ---
    cout << "Main diagonal elements: ";
    for (int i = 0; i < 3; i++) {
        cout << matrix[i][i] << " ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. C++ arrays are 0-indexed; valid indices for size `N` are `0` through `N - 1`.
// 2. Uninitialized local arrays contain garbage values; initialize with `= {0}`.
// 3. Static array size: `sizeof(arr) / sizeof(arr[0])`.
// 4. Large arrays (> 10^6 elements) must be declared globally or as `vector` to prevent stack overflow.
// 5. 2D matrices are row-major; iterate rows in outer loop and columns in inner loop for cache friendliness.

