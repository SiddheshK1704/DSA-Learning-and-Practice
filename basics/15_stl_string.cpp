/**
 * 15_stl_string.cpp
 * Topic: std::string Container
 * Purpose: Sequence container designed specifically for manipulating character sequences.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. WHAT IT IS
// ==============================
// `std::string` is an instantiation of the `std::basic_string` class template for char.
// It acts like a dynamic array of characters (`vector<char>`) but offers specialized
// string operations like substrings, search, appending, and lexicographical comparisons.

// ==============================
// 2. WHY DSA USES IT
// ==============================
// - Palindrome checking, anagram detection, string matching, and parsing.
// - Easily compared using standard relational operators (`<`, `==`).
// - Works natively with hashing containers (`unordered_map<string, int>`).

// ==============================
// 3. DECLARATION
// ==============================
// string s = "hello";
// string s(5, 'a'); // creates "aaaaa"
// string copy_s = s;

// ==============================
// 4. IMPORTANT OPERATIONS
// ==============================
// - s.size() / s.length(): character count -> O(1)
// - s.push_back(ch): append char -> Amortized O(1)
// - s.pop_back(): remove last char -> O(1)
// - s += str: append string -> Amortized O(M)
// - s.substr(pos, len): extract substring -> O(len)
// - s.find(target): find first index -> O(N * M)
// - s.front() / s.back(): access end characters -> O(1)
// - s.clear(): empty string -> O(1)

// ==============================
// 5. SYNTAX EXAMPLES
// ==============================
// string s = "algorithm";
// string sub = s.substr(0, 4); // "algo"
// size_t idx = s.find("rithm");

// ==============================
// 6. TIME COMPLEXITY
// ==============================
// - Access (s[i]): O(1)
// - Append character: Amortized O(1)
// - Substring extraction: O(K) where K is substring length
// - Comparison (s1 == s2): O(min(L1, L2))
// - Search: O(N * M) worst case

// ==============================
// 7. COMMON INTERVIEW USE CASES
// ==============================
// - Valid Anagram (sort string or character frequency array).
// - Longest Substring Without Repeating Characters (sliding window).
// - String Compression and Run-Length Encoding.
// - Valid Palindrome (two-pointer technique).

// ==============================
// 8. COMMON MISTAKES
// ==============================
// - Using `s = s + ch;` inside a loop of size N -> creates a fresh copy each iteration, causing O(N^2) TLE!
//   Always use `s += ch;` or `s.push_back(ch);` (O(1) amortized, O(N) total).
// - Passing large strings by value instead of `const string&`.
// - Forgetting that `s.substr()` takes `(start_index, count_of_characters)`, NOT `(start, end)`.

// ==============================
// 9. TINY EXAMPLE
// ==============================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 15: std::string Container ===" << '\n';

    // Anagram Verification Demonstration
    string str1 = "anagram";
    string str2 = "nagaram";

    string sorted1 = str1, sorted2 = str2;
    sort(sorted1.begin(), sorted1.end());
    sort(sorted2.begin(), sorted2.end());

    cout << "Are \"" << str1 << "\" and \"" << str2 << "\" anagrams? "
         << boolalpha << (sorted1 == sorted2) << '\n';

    // Efficient string building demonstration
    string result = "";
    for (char c = 'a'; c <= 'e'; c++) {
        result += c; // Fast amortized O(1)
    }
    cout << "Built string: " << result << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `std::string` provides random access, comparison, and dynamic growth.
// 2. Never build strings with `s = s + c;` inside loops; use `s += c;` or `s.push_back(c);`.
// 3. Always pass strings by reference `const string& s` to avoid O(N) copies.
// 4. `s.substr(pos, count)` extracts `count` characters starting at index `pos`.

