# C++ Basics for DSA

> **Purpose:**  
> This folder contains my core C++ reference material while learning Data Structures and Algorithms (DSA) for technical coding interviews and competitive programming.
>
> **Important Note:**  
> **These files are reference material. Actual problem solving belongs in `practice_questions/`.**

---

## 🧭 Repository Overview & Design

This repository is strictly practical and DSA-oriented. It bypasses heavy enterprise C++ features (e.g. templates, smart pointers, complex OOP, meta-programming) and focuses 100% on the C++ constructs that appear in technical interviews (LeetCode, Codeforces, HackerRank).

Every `.cpp` file in this directory:
- Is completely self-contained and independently compilable under standard **C++17**.
- Uses `#include <bits/stdc++.h>` and `using namespace std;`.
- Follows a structured instructional design: **Concept $\rightarrow$ Syntax $\rightarrow$ Example $\rightarrow$ Expected Output $\rightarrow$ Common Pitfalls $\rightarrow$ Quick Recap**.

---

## 📚 Recommended Learning Order

Follow this 15-step progression to build a rock-solid foundation:

1. **Syntax & Skeleton** — [`01_basics.cpp`](01_basics.cpp)
2. **Input / Output & Fast I/O** — [`02_input_output.cpp`](02_input_output.cpp)
3. **Variables, Types & Overflow Prevention** — [`03_variables_datatypes.cpp`](03_variables_datatypes.cpp)
4. **Operators & Precedence** — [`04_operators.cpp`](04_operators.cpp)
5. **Conditionals & Branching** — [`05_conditionals.cpp`](05_conditionals.cpp)
6. **Loops, Traversal & Off-by-One Traps** — [`06_loops.cpp`](06_loops.cpp)
7. **Functions & Passing by Reference** — [`07_functions.cpp`](07_functions.cpp)
8. **Static Arrays & Matrices** — [`08_arrays.cpp`](08_arrays.cpp)
9. **Strings & Character Utilities** — [`09_strings.cpp`](09_strings.cpp)
10. **Pointers, References & Nullptr** — [`10_pointers_references.cpp`](10_pointers_references.cpp)
11. **Vector Foundations** — [`11_vectors.cpp`](11_vectors.cpp)
12. **Pairs & Nested Pairs** — [`12_pairs.cpp`](12_pairs.cpp)
13. **The Standard Template Library (STL)** — [`13_stl_array.cpp`](13_stl_array.cpp) through [`24_stl_unordered_map.cpp`](24_stl_unordered_map.cpp)
14. **Iterators, Sorting & Algorithms** — [`25_iterators.cpp`](25_iterators.cpp) through [`28_custom_comparators.cpp`](28_custom_comparators.cpp)
15. **Recursion, Bits & Big-O Complexity** — [`29_structs_classes.cpp`](29_structs_classes.cpp) through [`32_time_space_complexity.cpp`](32_time_space_complexity.cpp)

Once completed, you are ready to tackle algorithmic problem patterns in `practice_questions/`.

---

## 🗂️ File Directory

| File | Topic | Core DSA Focus |
|---|---|---|
| [`01_basics.cpp`](01_basics.cpp) | Program Structure | `#include`, `main()`, `cout`, `cin`, `endl` vs `\n` |
| [`02_input_output.cpp`](02_input_output.cpp) | I/O Streams | Fast I/O, `getline()`, clearing newline buffer |
| [`03_variables_datatypes.cpp`](03_variables_datatypes.cpp) | Data Types | `int` vs `long long`, 32-bit overflow, `1LL` promotion |
| [`04_operators.cpp`](04_operators.cpp) | Operators | Modulo on negative numbers, short-circuit `&&`, precedence |
| [`05_conditionals.cpp`](05_conditionals.cpp) | Branching | Grid in-bounds checks, `switch`, ternary conditionals |
| [`06_loops.cpp`](06_loops.cpp) | Iteration | Reverse loops, unsigned underflow trap, two-pointer loops |
| [`07_functions.cpp`](07_functions.cpp) | Functions | Pass-by-value vs pass-by-reference (`&`), `const` references |
| [`08_arrays.cpp`](08_arrays.cpp) | Arrays | 1D/2D static arrays, zero-indexing, stack overflow avoidance |
| [`09_strings.cpp`](09_strings.cpp) | Strings | `substr()`, `find()`, `push_back()`, `<cctype>` methods |
| [`10_pointers_references.cpp`](10_pointers_references.cpp) | Memory & Addresses | `&`, `*`, `nullptr`, heap node creation |
| [`11_vectors.cpp`](11_vectors.cpp) | Vector Basics | Dynamic arrays, resizing, `front()`/`back()`, 2D vectors |
| [`12_pairs.cpp`](12_pairs.cpp) | Pairs | `std::pair`, tie-break sorting, `vector<pair<int,int>>` |
| [`13_stl_array.cpp`](13_stl_array.cpp) | STL Array | Fixed-size wrapper, direction vectors (`dx`, `dy`) |
| [`14_stl_vector.cpp`](14_stl_vector.cpp) | STL Vector | Deep dive, memory capacity, graph adjacency lists |
| [`15_stl_string.cpp`](15_stl_string.cpp) | STL String | Anagram sorting, efficient character appending |
| [`16_stl_stack.cpp`](16_stl_stack.cpp) | STL Stack | LIFO, valid parentheses, empty check guard |
| [`17_stl_queue.cpp`](17_stl_queue.cpp) | STL Queue | FIFO, BFS traversal, push/pop mechanics |
| [`18_stl_deque.cpp`](18_stl_deque.cpp) | STL Deque | Double-ended queue, sliding window maximum |
| [`19_stl_priority_queue.cpp`](19_stl_priority_queue.cpp) | STL Priority Queue | Max-heap vs Min-heap (`greater<int>`), Top-K elements |
| [`20_stl_set.cpp`](20_stl_set.cpp) | STL Set | Unique sorted Red-Black Tree, logarithmic `lower_bound` |
| [`21_stl_multiset.cpp`](21_stl_multiset.cpp) | STL Multiset | Duplicate handling, single element erase trap |
| [`22_stl_unordered_set.cpp`](22_stl_unordered_set.cpp) | STL Unordered Set | Hash table, average $O(1)$ lookups, collision caveat |
| [`23_stl_map.cpp`](23_stl_map.cpp) | STL Map | Ordered key-value, sorted keys, coordinate compression |
| [`24_stl_unordered_map.cpp`](24_stl_unordered_map.cpp) | STL Unordered Map | Hash map, frequency counting idiom, Two Sum |
| [`25_iterators.cpp`](25_iterators.cpp) | Iterators | `begin()`, `end()`, `rbegin()`, range-based for loops |
| [`26_sorting.cpp`](26_sorting.cpp) | Sorting | `std::sort`, IntroSort $O(N \log N)$, pair sorting |
| [`27_algorithms.cpp`](27_algorithms.cpp) | STL Algorithms | `lower_bound`, `upper_bound`, `binary_search`, `accumulate` |
| [`28_custom_comparators.cpp`](28_custom_comparators.cpp) | Comparators | Lambdas, strict weak ordering, priority queue functors |
| [`29_structs_classes.cpp`](29_structs_classes.cpp) | Structs & Classes | `ListNode`, `TreeNode`, constructors, DSU class |
| [`30_recursion_basics.cpp`](30_recursion_basics.cpp) | Recursion | Base cases, call stack, tree branching, factorial, fibonacci |
| [`31_bit_manipulation_basics.cpp`](31_bit_manipulation_basics.cpp) | Bit Manipulation | Set/clear/toggle bit, power of two, XOR cancellation |
| [`32_time_space_complexity.cpp`](32_time_space_complexity.cpp) | Complexity | Big-O classes, nested loops, operations per second |
| [`CHEATSHEET.md`](CHEATSHEET.md) | Syntax Cheatsheet | Fast-lookup card for interviews and contest emergencies |

---

## ⚡ How to Compile and Run

Each file can be compiled with any standard C++ compiler (GCC / MinGW / Clang / MSVC).

### Using GCC / MinGW:
```bash
# Compile with C++17 standard
g++ -std=c++17 01_basics.cpp -o 01_basics

# Run on Windows:
.\01_basics.exe

# Run on Linux / macOS:
./01_basics
```

---

## 📊 Summary of STL Container Complexities

| Container | Internal Structure | Access | Insertion | Deletion | Ordered? |
|---|---|---|---|---|---|
| `vector` | Dynamic Array | $O(1)$ | Amort. $O(1)$ back | $O(1)$ back, $O(N)$ mid | Insertion order |
| `deque` | Chunked Array | $O(1)$ | $O(1)$ front/back | $O(1)$ front/back | Insertion order |
| `stack` | Deque adapter | $O(1)$ top | $O(1)$ top | $O(1)$ top | LIFO |
| `queue` | Deque adapter | $O(1)$ front | $O(1)$ back | $O(1)$ front | FIFO |
| `priority_queue` | Binary Heap | $O(1)$ top | $O(\log N)$ | $O(\log N)$ | Heap property |
| `set` | Red-Black Tree | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | Strictly sorted |
| `multiset` | Red-Black Tree | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | Strictly sorted |
| `unordered_set`| Hash Table | Avg $O(1)$ | Avg $O(1)$ | Avg $O(1)$ | Unordered |
| `map` | Red-Black Tree | $O(\log N)$ | $O(\log N)$ | $O(\log N)$ | Sorted by key |
| `unordered_map`| Hash Table | Avg $O(1)$ | Avg $O(1)$ | Avg $O(1)$ | Unordered |

---

## 🚀 What I Should Practice Next

After familiarizing yourself with this reference material, solve actual problems inside the sibling directory **`practice_questions/`**.

Follow this structured roadmap:

```
1. Basic Logic & Simulation
   └── FizzBuzz, Palindrome Number, Reverse Integer
2. Arrays & Vectors
   └── Running Sum, Maximum Subarray (Kadane's), Leaders in Array
3. Strings
   └── Valid Anagram, Longest Common Prefix, Valid Palindrome
4. Hashing & Frequency Maps
   └── Two Sum, Group Anagrams, Subarray Sum Equals K
5. Sorting & Custom Ordering
   └── Merge Intervals, Non-overlapping Intervals, Largest Number
6. Binary Search
   └── Binary Search, Search in Rotated Sorted Array, Find Minimum in Rotated Sorted Array, Koko Eating Bananas
7. Two Pointers
   └── 3Sum, Container With Most Water, Trapping Rain Water
8. Sliding Window
   └── Longest Substring Without Repeating Characters, Minimum Window Substring
9. Linked Lists
   └── Reverse Linked List, Merge Two Sorted Lists, Linked List Cycle, Reorder List
10. Stacks & Queues
    └── Valid Parentheses, Daily Temperatures, Next Greater Element, Min Stack
11. Recursion & Backtracking
    └── Subsets, Permutations, Combination Sum, N-Queens
12. Trees & Binary Search Trees
    └── Invert Tree, Maximum Depth, Level Order Traversal, Validate BST, Lowest Common Ancestor
13. Heaps & Priority Queues
    └── Kth Largest Element, Top K Frequent Elements, Merge K Sorted Lists
14. Graphs
    └── Number of Islands (BFS/DFS), Clone Graph, Course Schedule (Topological Sort), Dijkstra's Algorithm
15. Greedy Algorithms
    └── Jump Game, Gas Station, Task Scheduler
16. Dynamic Programming (DP)
    └── Climbing Stairs, Coin Change, Longest Increasing Subsequence, 0/1 Knapsack, Edit Distance
```

> **Remember:**  
> Refer back to this `basics/` folder and `CHEATSHEET.md` whenever you need a quick syntax check or complexity confirmation while solving problems!

