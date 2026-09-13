# C++ DSA Quick-Reference Cheatsheet

A high-density "open this when I forget syntax" cheat sheet tailored for coding interviews and competitive programming.

---

## 1. Fast I/O & Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Code goes here
    return 0;
}
```

---

## 2. Input & Output

```cpp
// Standard reading (skips leading whitespace)
int a, b;
cin >> a >> b;

// Reading full line with spaces
string s;
getline(cin, s);

// Trap: If reading string after cin >> n, clear the newline first!
cin >> n;
cin.ignore(); // or cin >> ws;
getline(cin, s);

// Fast output
cout << "Result: " << a << '\n'; // Prefer '\n' over endl
```

---

## 3. Data Types & Overflow Rules

```cpp
int x = 1e9;                   // ~2 * 10^9 max
long long y = 1e18;            // ~9 * 10^18 max (append LL: 10000000000LL)

// Prevent 32-bit overflow before multiplication:
long long product = 1LL * a * b;

// Safe non-negative modulo:
int safe_rem = (val % MOD + MOD) % MOD;
```

---

## 4. Vector (Dynamic Array)

```cpp
vector<int> v;                        // Empty vector
vector<int> v(n, 0);                  // Size n, all 0s
vector<vector<int>> grid(r, vector<int>(c, 0)); // r x c 2D matrix

v.push_back(x);                       // Append x (amortized O(1))
v.pop_back();                         // Remove last (O(1))
v.size();                             // Element count (O(1))
v.empty();                            // True if empty (O(1))
v.front();                            // First element (O(1))
v.back();                             // Last element (O(1))
v.clear();                            // Remove all elements (O(N))
v.reserve(capacity);                  // Preallocate memory
v.erase(v.begin() + i);               // Remove at index i (O(N))
v.insert(v.begin() + i, val);         // Insert at index i (O(N))
```

---

## 5. String

```cpp
string s = "abcdef";
s.size();                             // Length (O(1))
s.push_back('g');                     // Append char (O(1))
s.pop_back();                         // Remove last char (O(1))
s.substr(pos, len);                   // Substring of length len starting at pos (O(len))
s.find("cde");                        // Returns index or string::npos (O(N*M))
s.front();                            // First char
s.back();                             // Last char
reverse(s.begin(), s.end());          // Reverse in place (O(N))
to_string(1234);                      // Number to string
stoi("1234");                         // String to int
stoll("10000000000");                 // String to long long

// Character checks (<cctype>)
isdigit(c); isalpha(c); isalnum(c); tolower(c); toupper(c);
```

---

## 6. Pair

```cpp
pair<int, int> p = {10, 20};
p.first = 15;
p.second = 25;

// Vector of pairs:
vector<pair<int, int>> pairs = {{1, 2}, {3, 4}};
// Default sort: sorts by .first ascending, tie-breaks with .second ascending
sort(pairs.begin(), pairs.end());
```

---

## 7. Stack (LIFO)

```cpp
stack<int> st;
st.push(x);                           // Insert at top (O(1))
st.pop();                             // Remove top (void, O(1))
st.top();                             // Peek top element (O(1))
st.empty();                           // True if empty (O(1))
st.size();                            // Element count (O(1))

// Trap check:
if (!st.empty()) {
    int top_val = st.top();
    st.pop();
}
```

---

## 8. Queue (FIFO)

```cpp
queue<int> q;
q.push(x);                            // Insert at back (O(1))
q.pop();                              // Remove from front (void, O(1))
q.front();                            // Oldest element (O(1))
q.back();                             // Newest element (O(1))
q.empty();                            // True if empty (O(1))
q.size();                             // Count (O(1))
```

---

## 9. Deque (Double-Ended Queue)

```cpp
deque<int> dq;
dq.push_front(x); dq.push_back(x);     // O(1)
dq.pop_front();   dq.pop_back();      // O(1)
dq.front();       dq.back();          // O(1)
dq[i];                                // O(1) random access
```

---

## 10. Priority Queue (Heap)

```cpp
// 1. Max Heap (Default - largest at top):
priority_queue<int> max_pq;
max_pq.push(x);                       // O(log N)
max_pq.top();                         // Largest element (O(1))
max_pq.pop();                         // Remove largest (O(log N))

// 2. Min Heap (Smallest at top):
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(x);
min_pq.top();                         // Smallest element (O(1))
min_pq.pop();

// 3. Min Heap of Pairs:
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
```

---

## 11. Set & Multiset (Balanced BST, Ordered)

```cpp
// Set (Unique, sorted ascending, O(log N)):
set<int> s;
s.insert(x);                          // O(log N)
s.erase(x);                           // O(log N)
s.count(x);                           // 1 if exists, 0 otherwise (O(log N))
s.find(x);                            // Returns iterator or s.end() (O(log N))
s.lower_bound(x);                     // First element >= x (O(log N))
s.upper_bound(x);                     // First element > x (O(log N))

// Multiset (Allows duplicates, sorted ascending):
multiset<int> ms;
ms.insert(x);
ms.erase(ms.find(x));                 // Erase SINGLE occurrence (Amortized O(1))
// WARNING: ms.erase(x) erases ALL occurrences of x!
```

---

## 12. Map & Unordered Map (Key-Value)

```cpp
// Map (Ordered Red-Black Tree, O(log N)):
map<string, int> mp;
mp["alice"] = 10;                     // Inserts or updates (O(log N))
if (mp.count("bob")) { ... }          // Safe existence check (O(log N))
auto it = mp.lower_bound("cat");      // First key >= "cat"

// Unordered Map (Hash Table, Average O(1)):
unordered_map<int, int> freq;
freq[x]++;                            // Frequency count idiom
if (freq.find(x) != freq.end()) { }   // Safe find without default insertion
```

---

## 13. Algorithms (<algorithm> & <numeric>)

```cpp
sort(v.begin(), v.end());             // Ascending O(N log N)
sort(v.rbegin(), v.rend());           // Descending O(N log N)
reverse(v.begin(), v.end());          // Reverse O(N)

// Min / Max
int m = min(a, b);
int M = max({a, b, c});
int val = *max_element(v.begin(), v.end());
int idx = max_element(v.begin(), v.end()) - v.begin();

// Binary Search (REQUIRES SORTED RANGE)
bool ok = binary_search(v.begin(), v.end(), target); // O(log N)
auto lb = lower_bound(v.begin(), v.end(), target);   // First element >= target
auto ub = upper_bound(v.begin(), v.end(), target);   // First element > target
int count_x = ub - lb;                               // Occurrences of target

// Counting & Sum
int c = count(v.begin(), v.end(), target);           // O(N)
long long sum = accumulate(v.begin(), v.end(), 0LL); // O(N), use 0LL!

// Unique elements (Must be sorted first)
v.erase(unique(v.begin(), v.end()), v.end());

// Permutations
next_permutation(v.begin(), v.end());                // Returns false if last permutation
```

---

## 14. Comparators & Lambdas

```cpp
// 1. Lambda sort by pair second element:
sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
    return a.second < b.second; // strictly less-than (never <=)
});

// 2. Priority queue custom comparator struct:
struct CustomComp {
    bool operator()(const Job& a, const Job& b) {
        return a.profit < b.profit; // Max-heap: highest profit on top
    }
};
priority_queue<Job, vector<Job>, CustomComp> pq;
```

---

## 15. Traversal Loops & Structured Bindings

```cpp
// Range-based for (read-only):
for (const auto& x : v) cout << x << " ";

// Range-based for (in-place modification):
for (auto& x : v) x *= 2;

// C++17 Structured binding for maps / pairs:
for (const auto& [key, val] : freq) {
    cout << key << " : " << val << '\n';
}

// Two pointers inward scan:
int left = 0, right = n - 1;
while (left < right) {
    // logic
    left++; right--;
}
```

---

## 16. Bit Manipulation Cheatsheet

```cpp
n & 1                       // 1 if odd, 0 if even
1 << k                      // 2^k
n & (1 << k)                // check if k-th bit is set
n | (1 << k)                // set k-th bit
n & ~(1 << k)               // clear k-th bit
n ^ (1 << k)                // toggle k-th bit
(n > 0) && (n & (n - 1)) == 0 // true if power of 2
__builtin_popcount(n)       // count set bits (int)
__builtin_popcountll(n)     // count set bits (long long)
```

---

## 17. Complexity Reference Table

| Container | Access | Insert | Erase | Find | Underlying Structure |
|---|---|---|---|---|---|
| `vector` | $O(1)$ | Amort. $O(1)$ back | $O(N)$ mid, $O(1)$ back | $O(N)$ | Dynamic contiguous array |
| `deque` | $O(1)$ | $O(1)$ front/back | $O(1)$ front/back | $O(N)$ | Paged memory chunks |
| `stack` / `queue` | $O(1)$ | $O(1)$ | $O(1)$ | N/A | Adapter over deque |
| `priority_queue` | $O(1)$ top | $O(\log N)$ | $O(\log N)$ | N/A | Binary heap |
| `set` / `map` | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | Red-Black Tree |
| `multiset` | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | Red-Black Tree |
| `unordered_map`/`set`| Avg $O(1)$, Wst $O(N)$| Avg $O(1)$, Wst $O(N)$| Avg $O(1)$, Wst $O(N)$| Avg $O(1)$, Wst $O(N)$| Hash Table (chaining) |

