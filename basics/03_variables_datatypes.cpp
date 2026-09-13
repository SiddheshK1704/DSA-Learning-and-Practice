/**
 * 03_variables_datatypes.cpp
 * Topic: Variables, Primitive Data Types, and Type Conversion
 * Purpose: Master type limits, integer overflow prevention, and DSA numeric rules.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. PRIMITIVE DATA TYPES & SIZES
// ==============================
// Explanation:
// In DSA, choosing the correct data type is critical to prevent Wrong Answer (WA)
// caused by overflow.
// Common types:
// - bool: 1 byte (true or false)
// - char: 1 byte ('a', 'Z', '9')
// - int: 4 bytes (~ -2 * 10^9 to +2 * 10^9) -> exact: [-2,147,483,648 to 2,147,483,647]
// - long long: 8 bytes (~ -9 * 10^18 to +9 * 10^18)
// - float: 4 bytes (single precision, ~6-7 decimal digits)
// - double: 8 bytes (double precision, ~15-17 decimal digits; preferred in DSA)
// - string: dynamic array of characters
// - unsigned int: 0 to ~4 * 10^9 (rarely used in DSA because subtraction can wrap to large positive values)
//
// Syntax:
// int a = 10;
// long long b = 10000000000LL; // Note the 'LL' suffix!

// ==============================
// 2. WHEN TO USE INT VS LONG LONG IN DSA
// ==============================
// Explanation:
// - If the problem statement says numbers can be up to 10^5 or 10^9, a single value fits in `int`.
// - HOWEVER, if you sum an array of 10^5 elements where each element is up to 10^5:
//   Max sum = 10^5 * 10^5 = 10^10 -> EXCEEDS `int` capacity (2 * 10^9).
// - Multiplications of two 10^5 numbers (10^10) will overflow `int`.
// - RULE OF THUMB:
//   - Values up to 10^9: use `int`
//   - Sums, products, or values up to 10^18: use `long long`
//   - Always append `LL` to large literals: `1LL * a * b`

// ==============================
// 3. INTEGER OVERFLOW & INTEGER DIVISION
// ==============================
// Explanation:
// Overflow happens when a computation exceeds the maximum representable value of a type,
// wrapping around to negative numbers (undefined behavior in C++ signed integers).
//
// Integer division truncates towards zero:
// 7 / 2 evaluates to 3, NOT 3.5.
// To get a floating point result, cast at least one operand: `(double)7 / 2` or `7.0 / 2`.
//
// Syntax & Type Casting:
// static_cast<double>(a) / b; // Modern C++ explicit cast
// 1LL * a * b;               // Idiomatic competitive programming cast to long long

// ==============================
// 4. CONSTANTS
// ==============================
// Explanation:
// Constants cannot be modified after initialization.
// In DSA, constants are widely used for modulo arithmetic:
// const int MOD = 1e9 + 7;
// const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 03: Variables, Data Types & Overflow ===" << '\n';

    // --- 1. Basic Declarations ---
    int x = 10;
    long long y = 10000000000LL;
    double pi = 3.141592653589793;
    char grade = 'A';
    bool is_prime = true;
    string title = "DSA Preparation";

    cout << "int x: " << x << '\n';
    cout << "long long y: " << y << '\n';
    cout << "double pi: " << fixed << setprecision(5) << pi << '\n';
    cout << "char: " << grade << ", bool: " << boolalpha << is_prime << '\n';
    cout << "string: " << title << '\n';

    // --- 2. Demonstrating Integer Overflow Trap ---
    int a = 1000000; // 10^6
    int b = 1000000; // 10^6
    
    // BAD: a * b is computed as 32-bit int first, overflows, THEN stored into long long!
    long long bad_product = a * b; 
    
    // GOOD: Multiply by 1LL to promote the calculation to 64-bit long long before multiplication
    long long good_product = 1LL * a * b;

    cout << "\nOverflow Demonstration (10^6 * 10^6):" << '\n';
    cout << "Bad product (overflowed): " << bad_product << '\n';
    cout << "Good product (using 1LL): " << good_product << '\n';

    // --- 3. Integer Division vs Floating-Point Division ---
    int num1 = 7, num2 = 2;
    cout << "\nDivision demonstration:" << '\n';
    cout << "Integer division (7 / 2): " << (num1 / num2) << '\n';
    cout << "Explicit cast (double)7 / 2: " << (static_cast<double>(num1) / num2) << '\n';

    // --- 4. Modulo Arithmetic Constant ---
    const int MOD = 1e9 + 7;
    cout << "Common DSA Modulo constant: " << MOD << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `int` holds up to ~2 * 10^9; `long long` holds up to ~9 * 10^18.
// 2. Always write `10000000000LL` with `LL` suffix for literals exceeding `int`.
// 3. To avoid overflow when multiplying two ints: write `1LL * a * b`.
// 4. In DSA, if an answer can be large, accumulator variables (sum, total) must be `long long`.
// 5. Division between two integers (`7 / 2`) discards remainder; use `(double)a / b` for real numbers.
// 6. Use `double` rather than `float` for precision in geometry / math problems.

