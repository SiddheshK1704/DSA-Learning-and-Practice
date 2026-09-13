/**
 * 02_input_output.cpp
 * Topic: Input and Output Handling for DSA & Competitive Programming
 * Purpose: Learn reading inputs reliably, reading strings with spaces, and fast I/O.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. FAST I/O IN C++
// ==============================
// Explanation:
// By default, C++ streams (`cin`/`cout`) synchronize with C standard I/O (`scanf`/`printf`)
// to maintain safety if both are mixed. This creates substantial performance overhead.
// Furthermore, `cin` is tied to `cout`, causing `cout` to flush every time before `cin` runs.
//
// In competitive programming, when tests have 10^5 to 10^6 input lines:
// - `ios::sync_with_stdio(false);` disables the synchronization with C I/O buffers.
// - `cin.tie(nullptr);` unties cin from cout, preventing unnecessary auto-flushes.
//
// Syntax:
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
//
// Common Mistake:
// Mixing `cin`/`cout` with `scanf`/`printf` after disabling sync leads to scrambled I/O.
// Use strictly `cin`/`cout` after turning off sync.

// ==============================
// 2. READING MULTIPLE VALUES WITH CIN
// ==============================
// Explanation:
// `cin` uses the extraction operator `>>`. It skips leading whitespace (spaces, tabs, newlines)
// and stops reading at the next whitespace character. Multiple values can be chained.
//
// Syntax:
// int a, b;
// cin >> a >> b;
//
// Common Mistake:
// Trying to read a full sentence with spaces using `cin >> str;`.
// `cin >>` will only read the first word!

// ==============================
// 3. READING STRINGS WITH SPACES: GETLINE
// ==============================
// Explanation:
// `getline(cin, str)` reads an entire line including spaces up until the newline character `\n`.
//
// Syntax:
// string line;
// getline(cin, line);
//
// Common Mistake (THE NEWLINE BUFFER TRAP):
// If you read an integer using `cin >> n;` before calling `getline(cin, s);`,
// the newline `\n` left in the input stream after the integer will immediately consume `getline`,
// leaving `s` empty!
// Fix: Use `cin.ignore();` or `cin >> ws;` before `getline`.

// ==============================
// 4. READING ARRAYS AND VECTORS
// ==============================
// Explanation:
// Arrays and vectors of size N are read sequentially inside a loop.
//
// Syntax:
// for(int i = 0; i < n; i++) cin >> arr[i];

int main() {
    // Enable Fast I/O at the start of main
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 02: Input and Output Handling ===" << '\n';

    // Simulated input using stringstream for self-contained, automated execution
    stringstream simulated_input;
    simulated_input << "42 100\n";
    simulated_input << "Competitive Programming in C++\n";
    simulated_input << "5\n";
    simulated_input << "10 20 30 40 50\n";

    // --- 1. Reading Multiple Values ---
    int num1, num2;
    simulated_input >> num1 >> num2;
    cout << "Read two numbers: " << num1 << " and " << num2 << '\n';

    // --- 2. Reading String with Spaces (Consuming leftover newline) ---
    string dummy_newline;
    getline(simulated_input, dummy_newline); // clears leftover newline
    string full_sentence;
    getline(simulated_input, full_sentence);
    cout << "Read line with spaces: \"" << full_sentence << "\"" << '\n';

    // --- 3. Reading Array / Vector Elements ---
    int n;
    simulated_input >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        simulated_input >> numbers[i];
    }

    cout << "Read " << n << " array elements: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. Always put `ios::sync_with_stdio(false); cin.tie(nullptr);` at the top of `main()`.
// 2. Use `cin >> a >> b;` for whitespace-delimited tokens.
// 3. Use `getline(cin, str);` to read strings containing spaces.
// 4. If `cin >>` was used before `getline()`, clear the lingering newline with `cin.ignore()` or `getline(cin, dummy)`.
// 5. Prefer `'\n'` over `endl` to avoid TLE (Time Limit Exceeded) on large output sets.

