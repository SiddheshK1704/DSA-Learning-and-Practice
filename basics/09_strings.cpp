/**
 * 09_strings.cpp
 * Topic: std::string and Character Manipulations
 * Purpose: Master string methods, search/substrings, character utilities, and interview patterns.
 * Standard: C++17
 */

#include <bits/stdc++.h>
using namespace std;

// ==============================
// 1. STD::STRING BASICS & METHODS
// ==============================
// Explanation:
// `std::string` is a dynamic array of characters. It handles resizing automatically
// and provides rich utility methods for string algorithms (anagrams, palindromes, parsing).
//
// Key Methods:
// - s.length() or s.size(): number of characters (O(1))
// - s.empty(): true if length is 0 (O(1))
// - s.push_back(ch): appends char at end (amortized O(1))
// - s.pop_back(): removes last char (O(1))
// - s.front(): returns reference to first char
// - s.back(): returns reference to last char
// - s.substr(pos, len): returns substring of length `len` starting at `pos` (O(len))
// - s.find(target): returns starting index, or `string::npos` if not found (O(N * M))
// - s.erase(pos, len): erases characters in place (O(N))
// - s.insert(pos, str): inserts string at pos (O(N))
// - reverse(s.begin(), s.end()): reverses string in place (O(N))

// ==============================
// 2. CHARACTER UTILITIES (<cctype>)
// ==============================
// Explanation:
// Essential for parsing and string problem constraints:
// - isdigit(ch): checks if '0' <= ch <= '9'
// - isalpha(ch): checks if ch is an alphabet letter
// - isalnum(ch): checks if alphanumeric (letter or digit)
// - tolower(ch): converts uppercase to lowercase
// - toupper(ch): converts lowercase to uppercase

// ==============================
// 3. STRING NUMERIC CONVERSIONS
// ==============================
// Explanation:
// - to_string(val): converts int/long long/double to string
// - stoi(str): string to int (throws exception if invalid)
// - stoll(str): string to long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== 09: Strings in C++ ===" << '\n';

    // --- 1. Declaration, Push/Pop & Access ---
    string s = "leetcode";
    cout << "Initial string: " << s << " (size: " << s.size() << ")\n";

    s.push_back('s');
    cout << "After push_back('s'): " << s << '\n';

    s.pop_back();
    cout << "After pop_back(): " << s << '\n';

    cout << "First char: " << s.front() << ", Last char: " << s.back() << '\n';

    // --- 2. Substring and Find ---
    // substr(start_index, count_of_characters)
    string sub = s.substr(0, 4); // "leet"
    cout << "Substring s.substr(0, 4): " << sub << '\n';

    size_t found_idx = s.find("code");
    if (found_idx != string::npos) {
        cout << "\"code\" found at index: " << found_idx << '\n';
    }

    // --- 3. In-Place Reverse & Comparisons ---
    string word = "radar";
    string original = word;
    reverse(word.begin(), word.end());
    cout << "Is \"" << original << "\" a palindrome? " << boolalpha << (original == word) << '\n';

    // --- 4. Character Level Manipulation (Palindrome ignore non-alphanumeric) ---
    string mixed = "A man, a plan, a canal: Panama!";
    string cleaned = "";
    for (char c : mixed) {
        if (isalnum(c)) {
            cleaned.push_back(tolower(c));
        }
    }
    cout << "Cleaned string: " << cleaned << '\n';

    // --- 5. Numeric Conversions ---
    string num_str = "12345";
    int parsed_int = stoi(num_str);
    cout << "stoi(\"" << num_str << "\") + 5 = " << (parsed_int + 5) << '\n';

    string back_to_s = to_string(6789);
    cout << "to_string(6789) = " << back_to_s << '\n';

    return 0;
}

// ==============================
// QUICK RECAP
// ==============================
// 1. `s.substr(pos, len)` takes (start_index, length), NOT (start, end).
// 2. `s.find()` returns `string::npos` if the substring is not found.
// 3. String concatenation via `s += ch` or `s.push_back(ch)` is amortized O(1); `s = s + ch` creates a new string (O(N) copy, TLE risk in loops!).
// 4. Use `isalnum()`, `isalpha()`, `isdigit()`, and `tolower()` for character parsing.
// 5. Use `stoi()` and `to_string()` for easy string <-> integer conversions.

