/**
 * 01_basics.cpp
 * Topic: C++ Fundamentals for DSA
 * Purpose: Understand the skeleton of every C++ competitive programming / DSA file.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. #INCLUDE DIRECTIVE
// ==============================
// Explanation:
// In standard C++, we include header files (e.g., <iostream>, <vector>, <algorithm>)
// to use library functions. In competitive programming and DSA, <bits/stdc++.h>
// is a popular header that includes virtually all C++ standard library files at once.
//
// Syntax:
// #include <bits/stdc++.h>
//
// Common Mistake:
// Forgetting the `#` or spelling the header wrong. Also, note that <bits/stdc++.h>
// is GCC-specific; in some non-GCC environments (like MSVC by default), standard headers
// like <iostream> and <vector> are explicitly included instead.

// ==============================
// 2. NAMESPACE STD
// ==============================
// Explanation:
// Standard library functions live in the `std` namespace (std::cout, std::vector).
// Writing `using namespace std;` imports all standard names into global scope so we
// don't have to prefix `std::` before every library identifier.
//
// Syntax:
// using namespace std;
//
// Common Mistake:
// Putting this before `#include` (it must come after includes).

// ==============================
// 3. MAIN() FUNCTION & RETURN 0
// ==============================
// Explanation:
// Execution of every C++ program begins at the `main()` function.
// It returns an integer status code to the operating system.
// Returning 0 indicates successful execution without runtime error.
//
// Syntax:
// int main() {
//     // statements
//     return 0;
// }
//
// Common Mistake:
// Writing `void main()`. In standard C++, `main()` must return `int`.

// ==============================
// 4. COMMENTS & SEMICOLONS
// ==============================
// Explanation:
// Single line comments start with `//`. Multi-line comments are enclosed in `/* ... */`.
// Every statement in C++ must terminate with a semicolon `;`.
//
// Common Mistake:
// Missing semicolon at the end of statements, especially after variable declarations or `cin`/`cout`.

// ==============================
// 5. OUTPUT: COUT, ENDL, ESCAPE CHARACTERS
// ==============================
// Explanation:
// `cout` (character output) writes to standard output via the stream insertion operator `<<`.
// `endl` prints a newline character AND flushes the output buffer.
// `'\n'` prints only a newline (preferred in DSA for speed).
// Common escape characters: `\n` (newline), `\t` (tab), `\"` (double quote), `\\` (backslash).
//
// Syntax:
// cout << "Message" << '\n';

// ==============================
// 6. COMPILATION BASICS
// ==============================
// Explanation:
// C++ is a compiled language. Source code (.cpp) is transformed into machine code by a compiler.
// Command line compilation:
// g++ -std=c++17 01_basics.cpp -o 01_basics
// Execution on Windows: .\01_basics.exe (or ./01_basics on Linux/macOS)

int main() {
    // --- 1. Hello World Demonstration ---
    cout << "=== 01: C++ Basics for DSA ===" << '\n';
    cout << "Hello, DSA Journey!" << '\n';

    // --- 2. Escape Characters ---
    cout << "Tabbed:\tColumn1\tColumn2" << '\n';
    cout << "Quotes: \"Solving DSA problems with C++\"" << '\n';

    // --- 3. endl vs '\n' ---
    // endl flushes the output buffer immediately; '\n' is faster because it buffers output.
    cout << "Prefer '\\n' over 'endl' for performance in coding platforms." << endl;

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `#include <bits/stdc++.h>` loads all DSA headers in GCC/MinGW.
// 2. `using namespace std;` lets you write `cout` instead of `std::cout`.
// 3. Every C++ program starts in `int main()` and ends with `return 0;`.
// 4. Every statement requires a semicolon `;`.
// 5. Prefer `'\n'` over `endl` to prevent unnecessary buffer flushing during high-volume output.

