/**
 * 10_pointers_references.cpp
 * Topic: Pointers, References, and Memory Addresses for DSA
 * Purpose: Learn address-of, dereferencing, nullptr, and reference passing used in Linked Lists & Trees.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IS A POINTER? ADDRESS (&) AND DEREFERENCE (*)
// ==============================
// Explanation:
// A variable stores a value at a specific location in memory.
// - `&x` (address-of operator): gets the memory address of variable x.
// - Pointer `int* ptr`: a variable that holds the memory address of another variable.
// - `*ptr` (dereference operator): accesses the actual value stored at the memory address pointed to.
//
// In DSA, pointers are foundational for:
// 1. Linked Lists (`Node* next`)
// 2. Binary Trees (`TreeNode* left`, `TreeNode* right`)
// 3. Graphs (Adjacency lists / pointer-based nodes)

// ==============================
// 2. NULLPTR
// ==============================
// Explanation:
// `nullptr` represents a pointer that does NOT point to any valid memory location.
// Used to signify the end of a linked list (`tail->next = nullptr`) or empty tree children.
// Always check `if (ptr != nullptr)` before dereferencing to prevent Segmentation Fault!

// ==============================
// 3. REFERENCES (&) IN C++
// ==============================
// Explanation:
// A reference is an alias (another name) for an existing variable.
// - It cannot be null.
// - It cannot be reseated (cannot refer to a different object once bound).
// - It requires no explicit dereferencing syntax (uses standard dot/variable syntax).
//
// WHY REFERENCES APPEAR CONSTANTLY IN DSA:
// Whenever we pass vectors, strings, matrices, or objects into helper functions,
// we pass by reference (`&`) to avoid expensive memory copying:
// `void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)`

// ==============================
// 4. BASIC DYNAMIC MEMORY (NEW AND DELETE)
// ==============================
// Explanation:
// For interview data structures (linked list node creation):
// `Node* node = new Node(val);` allocates memory on the heap.

struct SimpleNode {
    int val;
    SimpleNode* next;
    SimpleNode(int x) : val(x), next(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 10: Pointers and References for DSA ===" << '\n';

    // --- 1. Address-of and Dereferencing ---
    int x = 42;
    int* ptr = &x;

    cout << "Value of x: " << x << '\n';
    cout << "Address of x (&x): " << ptr << '\n';
    cout << "Value via dereference (*ptr): " << *ptr << '\n';

    *ptr = 100; // Modifies x through pointer
    cout << "Value of x after modifying *ptr: " << x << '\n';

    // --- 2. Nullptr Check ---
    int* empty_ptr = nullptr;
    if (empty_ptr == nullptr) {
        cout << "empty_ptr is safely checked against nullptr (no segfault).\n";
    }

    // --- 3. References (Aliases) ---
    int original = 500;
    int& ref = original; // ref is an alias for original
    ref += 25;
    cout << "Original after modifying ref: " << original << '\n';

    // --- 4. Linked List Node Creation Pattern ---
    SimpleNode* head = new SimpleNode(10);
    head->next = new SimpleNode(20);

    cout << "Linked list nodes: " << head->val << " -> " << head->next->val << " -> nullptr\n";

    // Clean up heap allocations
    delete head->next;
    delete head;

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `&x` yields the memory address; `*ptr` accesses the value at that address.
// 2. Dereferencing a `nullptr` or dangling pointer results in Segmentation Fault (Crash).
// 3. Always check `if (node != nullptr)` before accessing `node->next` or `node->val`.
// 4. Pointers can be reassigned and can be null; references cannot be null and cannot be rebound.
// 5. In DSA functions, use references (`&`) for vectors, maps, and state variables to achieve O(1) argument passing.

