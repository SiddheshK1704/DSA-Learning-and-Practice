/**
 * 30_recursion_basics.cpp
 * Topic: Recursion Fundamentals for DSA
 * Purpose: Master base cases, the call stack, state transitions, and multiple recursive branches.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. ANATOMY OF RECURSION
// ==============================
// Explanation:
// Recursion occurs when a function calls itself to solve a smaller instance of the same problem.
// Every recursive function must have two components:
// 1. BASE CASE: The terminating condition that stops recursion. Without it, the function calls
//    itself indefinitely until the call stack runs out of memory -> Stack Overflow (Crash).
// 2. RECURSIVE CASE: Calling the function with modified arguments moving towards the base case.

// ==============================
// 2. THE CALL STACK & TRACING
// ==============================
// Tracing factorial(3):
// -> factorial(3) calls factorial(2)  [Pushed to Stack]
//   -> factorial(2) calls factorial(1)  [Pushed to Stack]
//     -> factorial(1) returns 1 (Base Case)  [Popped from Stack]
//   -> factorial(2) receives 1, returns 2 * 1 = 2  [Popped from Stack]
// -> factorial(3) receives 2, returns 3 * 2 = 6  [Popped from Stack]

// --- Example 1: Factorial (Returning Values) ---
long long factorial(int n) {
    if (n <= 1) return 1; // Base case
    return 1LL * n * factorial(n - 1); // Recursive case
}

// --- Example 2: Sum of First N Natural Numbers ---
long long sumOfN(int n) {
    if (n == 0) return 0;
    return n + sumOfN(n - 1);
}

// --- Example 3: Reversing an Array In-Place Recursively ---
void reverseArray(vector<int>& arr, int left, int right) {
    if (left >= right) return; // Base case: pointers crossed
    swap(arr[left], arr[right]);
    reverseArray(arr, left + 1, right - 1); // Recursive case
}

// --- Example 4: String Palindrome Check ---
bool isPalindrome(const string& s, int left, int right) {
    if (left >= right) return true; // Base case
    if (s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1);
}

// --- Example 5: Multiple Recursive Calls (Fibonacci Tree) ---
// Note: Pure recursion for Fibonacci is O(2^N); memoization/DP will optimize this in DSA.
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2); // Two branching calls
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 30: Recursion Fundamentals in C++ ===" << '\n';

    // 1. Factorial
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n) << '\n';

    // 2. Sum of N
    cout << "Sum of 1 to 10 = " << sumOfN(10) << '\n';

    // 3. Array Reversal
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr, 0, (int)arr.size() - 1);
    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << '\n';

    // 4. Palindrome
    string word = "racecar";
    cout << "Is \"" << word << "\" palindrome? " 
         << boolalpha << isPalindrome(word, 0, word.size() - 1) << '\n';

    // 5. Fibonacci
    cout << "Fibonacci(6) = " << fibonacci(6) << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Always identify and write the Base Case first to prevent Stack Overflow.
// 2. Ensure each recursive step moves strictly closer to the base case.
// 3. Pass large containers by reference (`vector<int>& arr`) in recursion to avoid O(N) copying per call.
// 4. Single recursive call forms a linear call stack (O(N) depth); multiple calls form a recursion tree (e.g. O(2^N)).
// 5. Space complexity of recursion is determined by the maximum depth of the call stack.

