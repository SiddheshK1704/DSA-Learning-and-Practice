/**
 * 05_conditionals.cpp
 * Topic: Conditional Statements & Branching Logic
 * Purpose: Control execution flow in algorithms, base cases, and state transitions.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. IF, ELSE IF, ELSE
// ==============================
// Explanation:
// Executes code blocks based on boolean evaluations.
// In DSA, used for boundary conditions, base cases in recursion, and branch selection.
//
// Syntax:
// if (condition1) {
//     // executes if condition1 is true
// } else if (condition2) {
//     // executes if condition1 is false and condition2 is true
// } else {
//     // executes if all above conditions are false
// }
//
// Common Mistake:
// Using single `=` (assignment) instead of `==` (comparison):
// `if (x = 5)` assigns 5 to x and always evaluates to true!

// ==============================
// 2. NESTED IF STATEMENTS
// ==============================
// Explanation:
// Placing an `if` block inside another `if` block. Useful when a secondary condition
// only makes sense if the primary condition has succeeded (e.g. 2D grid boundary checking).
//
// Common Mistake:
// Deeply nesting when conditions could be flattened using `&&`.
// Flattened: `if (r >= 0 && r < rows && c >= 0 && c < cols)` is cleaner and more readable.

// ==============================
// 3. SWITCH STATEMENTS
// ==============================
// Explanation:
// Selects one of many code blocks based on the equality of an integral/char expression.
// Often used in state machine simulations, calculator problems, or parsing direction strings ('U', 'D', 'L', 'R').
//
// Syntax:
// switch (expression) {
//     case val1:
//         // statements
//         break;
//     case val2:
//         // statements
//         break;
//     default:
//         // fallback statements
// }
//
// Common Mistake:
// Forgetting the `break;` statement, causing "fall-through" into subsequent cases.

// ==============================
// 4. TERNARY OPERATOR FOR INLINE DSA CHECKS
// ==============================
// Explanation:
// Compact single-line condition. Often used inside return statements or when setting initial min/max boundaries.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 05: Conditionals in C++ ===" << '\n';

    // --- 1. Sign & Parity Analysis (DSA Pattern) ---
    int score = 75;
    if (score >= 90) {
        cout << "Grade: A\n";
    } else if (score >= 75) {
        cout << "Grade: B\n";
    } else {
        cout << "Grade: Needs Improvement\n";
    }

    // --- 2. 2D Grid In-Bounds Check Example (Flattened vs Nested) ---
    int row = 2, col = 3;
    int max_rows = 5, max_cols = 5;

    // Standard DSA in-bounds condition
    if (row >= 0 && row < max_rows && col >= 0 && col < max_cols) {
        cout << "Cell (" << row << ", " << col << ") is inside the grid.\n";
    }

    // --- 3. Switch Case: Grid Direction Movement ---
    char direction = 'R';
    int x = 0, y = 0;

    switch (direction) {
        case 'U': y++; break;
        case 'D': y--; break;
        case 'L': x--; break;
        case 'R': x++; break;
        default:  cout << "Invalid direction!\n"; break;
    }
    cout << "New coordinates after moving " << direction << ": (" << x << ", " << y << ")\n";

    // --- 4. Ternary in LeetCode-style return ---
    int num = -12;
    int sign = (num >= 0) ? 1 : -1;
    cout << "Sign of " << num << " is: " << sign << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Double equals `==` tests equality; single equals `=` performs assignment.
// 2. Flatten nested checks using logical `&&` to keep boundary checks clean and readable.
// 3. Always include `break;` in `switch` statements to prevent unwanted fall-through.
// 4. Every `switch` should ideally have a `default:` case for error handling.
// 5. Ternary operators `c ? a : b` simplify inline assignment and return logic.

