/**
 * 31_bit_manipulation_basics.cpp
 * Topic: Bit Manipulation Essentials for DSA
 * Purpose: Master binary operations (&, |, ^, ~, <<, >>), bitmasking, and XOR tricks.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. CORE BITWISE OPERATORS
// ==============================
// - AND (&): 1 & 1 = 1, otherwise 0.
// - OR  (|): 0 | 0 = 0, otherwise 1.
// - XOR (^): 1 ^ 0 = 1, 0 ^ 1 = 1; same bits yield 0 (1 ^ 1 = 0, 0 ^ 0 = 0).
// - NOT (~): inverts all bits.
// - LEFT SHIFT (<<): `x << k` shifts bits left by k, equivalent to `x * 2^k`.
// - RIGHT SHIFT (>>): `x >> k` shifts bits right by k, equivalent to `x / 2^k`.

// ==============================
// 2. CHECKING, SETTING, CLEARING & TOGGLING THE I-TH BIT
// ==============================
// Let bit mask for i-th bit be: `(1 << i)`
//
// 1. Check if i-th bit is set:
//    `bool is_set = (n & (1 << i)) != 0;`
// 2. Set i-th bit (force to 1):
//    `n = n | (1 << i);`
// 3. Clear i-th bit (force to 0):
//    `n = n & (~(1 << i));`
// 4. Toggle i-th bit (invert 0 <-> 1):
//    `n = n ^ (1 << i);`

// ==============================
// 3. POWER OF TWO CHECK
// ==============================
// Explanation:
// Powers of two have exactly one bit set (e.g., 8 = 1000 in binary).
// `n - 1` flips that bit and sets all lower bits (7 = 0111 in binary).
// Therefore, `n & (n - 1)` removes the lowest set bit!
// If `(n > 0 && (n & (n - 1)) == 0)`, then n is a power of 2!

// ==============================
// 4. XOR PROPERTIES & CANCELLATION TRICK
// ==============================
// 1. `a ^ 0 = a`
// 2. `a ^ a = 0` (Self-cancellation)
// 3. Associative & Commutative: order does not matter.
// DSA Classic (Single Number - LeetCode 136):
// In an array where every element appears twice except one, XORing all elements cancels out duplicates,
// leaving only the unique element!

// ==============================
// 5. COUNTING SET BITS (HAMMING WEIGHT)
// ==============================
// Built-in GCC functions:
// - `__builtin_popcount(n)`: counts set bits for 32-bit int.
// - `__builtin_popcountll(n)`: counts set bits for 64-bit long long.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 31: Bit Manipulation Basics ===" << '\n';

    // --- 1. Odd or Even Check ---
    int val = 27;
    cout << val << " is " << ((val & 1) ? "Odd" : "Even") << '\n';

    // --- 2. Bitwise Operations on i-th bit (e.g. i = 2, representing 2^2 = 4) ---
    int n = 8; // Binary: 1000 (bits: 3, 2, 1, 0)
    int i = 2;

    cout << "\nInitial n: " << n << " (binary: " << bitset<5>(n) << ")\n";

    // Check bit i
    bool bit_set = (n & (1 << i)) != 0;
    cout << "Is bit " << i << " set? " << boolalpha << bit_set << '\n';

    // Set bit i
    n = n | (1 << i);
    cout << "After setting bit " << i << ": " << n << " (" << bitset<5>(n) << ")\n";

    // Toggle bit i
    n = n ^ (1 << i);
    cout << "After toggling bit " << i << ": " << n << " (" << bitset<5>(n) << ")\n";

    // --- 3. Power of 2 check ---
    int test_p2 = 16;
    bool is_p2 = (test_p2 > 0) && ((test_p2 & (test_p2 - 1)) == 0);
    cout << "\nIs " << test_p2 << " a power of 2? " << boolalpha << is_p2 << '\n';

    // --- 4. XOR Single Number Problem ---
    vector<int> nums = {4, 1, 2, 1, 2};
    int unique_elem = 0;
    for (int x : nums) {
        unique_elem ^= x;
    }
    cout << "Single non-duplicate element via XOR: " << unique_elem << '\n';

    // --- 5. Counting Set Bits ---
    int sample = 29; // binary 11101 -> 4 set bits
    cout << "Set bits in " << sample << ": " << __builtin_popcount(sample) << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `(n & 1)`: returns 1 if odd, 0 if even.
// 2. Set bit: `n | (1 << i)`; Clear bit: `n & ~(1 << i)`; Toggle bit: `n ^ (1 << i)`.
// 3. Power of two check: `(n > 0 && (n & (n - 1)) == 0)`.
// 4. XOR cancellation: `x ^ x = 0` and `x ^ 0 = x`.
// 5. Use `__builtin_popcount(x)` for fast O(1) set-bit counting in C++ (use `__builtin_popcountll` for long long).

