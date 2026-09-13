/**
 * 07_functions.cpp
 * Topic: Functions, Signatures, and Parameter Passing
 * Purpose: Understand pass-by-value vs pass-by-reference to avoid TLE and memory overhead in DSA.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. FUNCTION DECLARATION & DEFINITION
// ==============================
// Explanation:
// Functions modularize logic into reusable blocks.
// - Declaration (prototype): specifies name, return type, and parameter types before use.
// - Definition: contains the actual body of the function.
//
// Syntax:
// ReturnType functionName(ParameterType param1, ...);

// ==============================
// 2. PASS BY VALUE VS PASS BY REFERENCE (CRITICAL FOR DSA)
// ==============================
// Explanation:
// - Pass by Value: `void modify(int x)` or `void solve(vector<int> nums)`
//   Creates a FULL COPY of the argument.
//   If `nums` has 10^6 elements, passing by value copies 4MB of memory ON EVERY FUNCTION CALL!
//   Calling this inside recursion leads to Memory Limit Exceeded (MLE) and Time Limit Exceeded (TLE).
//
// - Pass by Reference: `void solve(vector<int>& nums)`
//   Passes an alias (the actual memory address) of the original variable.
//   Zero copy overhead (O(1) time). Modifications directly affect the caller's variable.
//
// - Pass by Const Reference: `void print(const vector<int>& nums)`
//   Zero copy overhead (O(1)), but read-only. Compiler prevents unintended modifications.
//   Standard best practice for read-only vectors/strings in interviews!

// ==============================
// 3. DEFAULT ARGUMENTS & FUNCTION OVERLOADING
// ==============================
// Explanation:
// - Default parameters must be declared from right to left.
// - Overloading: multiple functions sharing the same name but with different parameter signatures.

// ==============================
// 4. RECURSION INTRODUCTION
// ==============================
// Explanation:
// A function that calls itself with a reduced problem state until hitting a base case.

// --- Helper Functions Demonstration ---

// 1. Pass by Value (does NOT change caller's value)
void incrementByValue(int x) {
    x += 10;
}

// 2. Pass by Reference (MODIFIES caller's value)
void incrementByReference(int& x) {
    x += 10;
}

// 3. DSA Pattern: Modify vector in-place
void doubleVectorElements(vector<int>& nums) {
    for (int& val : nums) {
        val *= 2;
    }
}

// 4. DSA Pattern: Read-only vector inspection without copy
int computeSum(const vector<int>& nums) {
    int total = 0;
    for (int val : nums) {
        total += val;
    }
    return total;
}

// 5. Function Overloading
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }

// 6. Intro to Recursion: Countdown
void countdown(int n) {
    if (n == 0) { // Base Case
        cout << "Blastoff!\n";
        return;
    }
    cout << n << " ";
    countdown(n - 1); // Recursive Call
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 07: Functions in C++ ===" << '\n';

    // --- 1. Pass by Value vs Pass by Reference ---
    int num = 5;
    incrementByValue(num);
    cout << "After incrementByValue: " << num << " (Unchanged, copy was modified)\n";

    incrementByReference(num);
    cout << "After incrementByReference: " << num << " (Modified in place!)\n";

    // --- 2. In-Place Vector Modification ---
    vector<int> numbers = {1, 2, 3, 4};
    doubleVectorElements(numbers);
    cout << "Vector doubled via pass-by-reference: ";
    for (int val : numbers) cout << val << " ";
    cout << '\n';

    // --- 3. Const Reference Usage ---
    int total = computeSum(numbers);
    cout << "Sum computed safely via const vector<int>&: " << total << '\n';

    // --- 4. Overloading ---
    cout << "Overload int multiply: " << multiply(3, 4) << '\n';
    cout << "Overload double multiply: " << multiply(2.5, 3.0) << '\n';

    // --- 5. Recursion Intro ---
    cout << "Recursion countdown: ";
    countdown(3);

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. NEVER pass vectors or strings by value (`vector<int> v`) in DSA; it creates O(N) memory copies on every call!
// 2. Use `vector<int>& v` when you want to modify elements in place.
// 3. Use `const vector<int>& v` when reading elements to ensure zero copy overhead and immutability.
// 4. Default arguments must appear at the end of the parameter list.
// 5. Recursion always needs a base case to stop infinite function call stacks.

