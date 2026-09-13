/**
 * 04_operators.cpp
 * Topic: Operators & Expressions in C++
 * Purpose: Learn arithmetic, logic, bitwise, assignment, and operator precedence for DSA.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. ARITHMETIC & MODULO OPERATORS
// ==============================
// Explanation:
// `+`, `-`, `*`, `/`, `%` (modulo - remainder of division).
// Note: Modulo operator `%` only works on integer operands.
// In C++, `-7 % 3` is `-1`. If you need non-negative modulo in DSA:
// `(val % MOD + MOD) % MOD` guarantees a result in [0, MOD - 1].
//
// Common Mistake:
// Division by zero (`a / 0` or `a % 0`) causes SIGFPE (Floating Point Exception / crash).

// ==============================
// 2. INCREMENT & DECREMENT OPERATORS
// ==============================
// Explanation:
// `++x` (pre-increment): increments x, then evaluates.
// `x++` (post-increment): evaluates current value of x, then increments.
// Same logic applies to `--x` and `x--`.
//
// In DSA loops (`for (int i = 0; i < n; ++i)`), prefix increment is standard and idiomatic.

// ==============================
// 3. RELATIONAL & LOGICAL OPERATORS
// ==============================
// Explanation:
// Relational: `==`, `!=`, `<`, `>`, `<=`, `>=`.
// Logical: `&&` (AND), `||` (OR), `!` (NOT).
// Short-circuit evaluation:
// In `A && B`, if `A` is false, `B` is never evaluated.
// In `A || B`, if `A` is true, `B` is never evaluated.
//
// Critical DSA pattern:
// `if (index >= 0 && index < n && arr[index] == target)`
// The bounds check runs first; if out of bounds, `arr[index]` is not accessed, preventing out-of-bounds crash!

// ==============================
// 4. BITWISE OPERATORS (BRIEF OVERVIEW)
// ==============================
// Explanation:
// `&` (AND), `|` (OR), `^` (XOR), `~` (NOT), `<<` (Left Shift), `>>` (Right Shift).
// Left shift `x << 1` multiplies x by 2.
// Right shift `x >> 1` divides x by 2.

// ==============================
// 5. TERNARY OPERATOR
// ==============================
// Explanation:
// Shorthand for simple if-else statements:
// `condition ? expression_if_true : expression_if_false;`

// ==============================
// 6. OPERATOR PRECEDENCE (THE ESSENTIALS)
// ==============================
// Explanation:
// Parentheses `()` have the highest precedence.
// Arithmetic (`*`, `/`, `%` then `+`, `-`) has higher precedence than Relational (`<`, `>`, `==`).
// Relational has higher precedence than Logical (`&&` then `||`).
//
// GOLDEN RULE IN DSA:
// When in doubt, ALWAYS use parentheses, especially with bitwise operators!
// `(a & 1) == 0` is CORRECT.
// `a & 1 == 0` is WRONG because `==` has higher precedence than `&`!

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 04: Operators in C++ ===" << '\n';

    // --- 1. Arithmetic & Modulo ---
    int a = 17, b = 5;
    cout << "a + b = " << (a + b) << '\n';
    cout << "a - b = " << (a - b) << '\n';
    cout << "a * b = " << (a * b) << '\n';
    cout << "a / b = " << (a / b) << " (quotient)" << '\n';
    cout << "a % b = " << (a % b) << " (remainder)" << '\n';

    // Safe negative modulo pattern
    int neg = -7, mod = 3;
    int safe_mod = (neg % mod + mod) % mod;
    cout << "Safe non-negative modulo of -7 % 3 = " << safe_mod << '\n';

    // --- 2. Short-Circuit Evaluation Guard ---
    vector<int> sample = {10, 20, 30};
    int query_idx = 5; // out of bounds
    // The short-circuit protects from runtime index crash
    if (query_idx < (int)sample.size() && sample[query_idx] == 30) {
        cout << "Found target!" << '\n';
    } else {
        cout << "Safely avoided out-of-bounds error via short-circuit &&" << '\n';
    }

    // --- 3. Bitwise quick preview ---
    int num = 4; // binary 0100
    cout << "num << 1 (4 * 2) = " << (num << 1) << '\n';
    cout << "num >> 1 (4 / 2) = " << (num >> 1) << '\n';
    cout << "num is even? (num & 1 == 0): " << boolalpha << ((num & 1) == 0) << '\n';

    // --- 4. Ternary Operator ---
    int x = 25, y = 40;
    int max_val = (x > y) ? x : y;
    cout << "Maximum of " << x << " and " << y << " is " << max_val << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Modulo `%` works only on integer types; use `(val % MOD + MOD) % MOD` for negative values.
// 2. Put boundary checks on the LEFT of `&&` to safely exploit short-circuit evaluation.
// 3. Bitwise operations have LOWER precedence than `==` and `!=`; always wrap them in parentheses: `(x & 1)`.
// 4. `x << k` computes `x * 2^k`; `x >> k` computes `x / 2^k`.
// 5. Ternary `condition ? true_val : false_val` is concise for inline assignments.

