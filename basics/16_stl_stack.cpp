/**
 * 16_stl_stack.cpp
 * Topic: std::stack Container
 * Purpose: LIFO (Last-In, First-Out) adapter used for monotonic stacks and recursion simulation.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::stack` is a container adapter that gives the programmer the functionality of a LIFO
// (Last-In, First-Out) data structure. By default, it wraps `std::deque` (or `std::vector`).
// Elements are inserted and extracted only from the top.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Bracket and parentheses matching (e.g. Valid Parentheses).
// - Monotonic stack problems (Next Greater Element, Daily Temperatures, Largest Rectangle in Histogram).
// - Simulating recursion / DFS iteratively.
// - Expression evaluation (Infix to Postfix, Reverse Polish Notation).

// ==============================
// 3. DECLARATION
// ==============================
// stack<int> st;
// stack<char> char_st;
// stack<pair<int, int>> pair_st;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - st.push(val): inserts element at top -> O(1)
// - st.emplace(args): constructs element in place at top -> O(1)
// - st.pop(): removes top element (returns void!) -> O(1)
// - st.top(): returns reference to top element -> O(1)
// - st.empty(): true if stack has no elements -> O(1)
// - st.size(): returns count of elements -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// stack<int> st;
// st.push(10);
// if (!st.empty()) {
//     int top_val = st.top();
//     st.pop();
// }

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Push: O(1)
// - Pop: O(1)
// - Top: O(1)
// - Empty / Size: O(1)
// - Search: O(N) (requires popping elements)
// - Space: O(N)

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Valid Parentheses (LeetCode 20)
// - Next Greater Element I & II (Monotonic Stack)
// - Asteroid Collision
// - Min Stack (maintaining minimum with an auxiliary stack)

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Calling `st.top()` or `st.pop()` on an EMPTY stack -> Undefined Behavior / Segmentation Fault!
//   ALWAYS check `if (!st.empty())` before calling `st.top()` or `st.pop()`.
// - Expecting `st.pop()` to return the value. In C++, `pop()` returns `void`.
//   You must read `st.top()` first, then call `st.pop()`.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 16: std::stack Container ===" << '\n';

    // Canonical DSA Interview Problem: Valid Parentheses
    string brackets = "{[()]}";
    stack<char> st;
    bool is_valid = true;

    for (char c : brackets) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) {
                is_valid = false;
                break;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                is_valid = false;
                break;
            }
        }
    }
    if (!st.empty()) is_valid = false;

    cout << "Is \"" << brackets << "\" valid? " << boolalpha << is_valid << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::stack` operates on LIFO (Last-In, First-Out) principle.
// 2. Critical golden rule: ALWAYS check `!st.empty()` before calling `st.top()` or `st.pop()`.
// 3. `st.pop()` returns `void`, it does not return the removed element.
// 4. Fundamental for monotonic stacks and parentheses validation algorithms.

