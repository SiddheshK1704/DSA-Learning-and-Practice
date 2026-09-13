/**
 * 29_structs_classes.cpp
 * Topic: Structs & Classes for DSA (Linked Lists and Trees)
 * Purpose: DSA-focused OOP essentials for custom nodes, graphs, and tree representations.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. STRUCT VS CLASS IN C++
// ==============================
// Explanation:
// In C++, the ONLY difference between a `struct` and a `class` is the default access specifier:
// - `struct`: members are PUBLIC by default.
// - `class`: members are PRIVATE by default.
// In DSA and competitive programming, `struct` is favored because node members (like `val`, `left`, `right`)
// are frequently accessed directly without needing getters/setters.

// ==============================
// 2. CONSTRUCTORS & INITIALIZER LISTS
// ==============================
// Explanation:
// A constructor initializes object member variables when an instance is instantiated.
// Initializer list syntax `: val(x), next(nullptr)` is the fastest and cleanest method.

// ==============================
// 3. LINKED LIST NODE DEFINITION (LEETCODE STANDARD)
// ==============================
struct ListNode {
    int val;
    ListNode* next;

    // Constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
};

// ==============================
// 4. BINARY TREE NODE DEFINITION (LEETCODE STANDARD)
// ==============================
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// ==============================
// 5. MEMBER FUNCTIONS & 'THIS' POINTER
// ==============================
// Explanation:
// Member functions belong to the struct/class and operate on its data.
// `this` is a pointer pointing to the current object instance (`this->val`).

class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 29: Structs and Classes for DSA ===" << '\n';

    // --- 1. Creating Linked List Nodes ---
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    cout << "Linked List: ";
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "nullptr\n";

    // --- 2. Creating a Binary Tree ---
    //        1
    //       / \
    //      2   3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << "Binary Tree Root: " << root->val 
         << " (Left: " << root->left->val 
         << ", Right: " << root->right->val << ")\n";

    // --- 3. Custom Class: Disjoint Set Union (DSU) ---
    DSU dsu(5);
    dsu.unite(1, 2);
    cout << "Are 1 and 2 connected in DSU? " << boolalpha 
         << (dsu.find(1) == dsu.find(2)) << '\n';
    cout << "Are 1 and 3 connected in DSU? " << boolalpha 
         << (dsu.find(1) == dsu.find(3)) << '\n';

    // Clean up dynamic memory
    delete head->next->next;
    delete head->next;
    delete head;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. In C++, `struct` members are public by default; `class` members are private by default.
// 2. Use `struct` for standard DSA nodes (`ListNode`, `TreeNode`) for easy member access.
// 3. Always initialize pointer members (`next`, `left`, `right`) to `nullptr` in constructors.
// 4. Use arrow operator `node->val` when accessing members via pointers.
// 5. Classes are ideal for encapsulating complex data structures like DSU (Disjoint Set Union) or Trie.

