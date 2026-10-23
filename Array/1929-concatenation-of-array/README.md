

# 1929. Concatenation of Array

**A collection of C++ solutions, from two-pass loops to optimized indexing and STL.**


<p align="center">
  <a href="https://leetcode.com/problems/concatenation-of-array/">
    <img src="https://img.shields.io/badge/LeetCode-1929%20Concatenation%20of%20Array-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 1929" />
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge" alt="Difficulty: Easy" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="Language: C++" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Topic-Arrays%20%7C%20Vectors-7C3AED?style=for-the-badge" alt="Topic: Arrays and Vectors" />
  <img src="https://img.shields.io/badge/Time-O%28n%29-orange?style=for-the-badge" alt="Time Complexity: O(n)" />
  <img src="https://img.shields.io/badge/Output%20Space-O%28n%29-blue?style=for-the-badge" alt="Output Space: O(n)" />
</p>

---

## 📌 Table of Contents

- [📘 Problem Statement](#-problem-statement)
- [🧪 Examples](#-examples)
- [📏 Constraints](#-constraints)
- [📊 Solutions Overview](#-solutions-overview)
  - [01. Two-Pass Loops — Using `push_back()`](#1-two-pass-loops--using-push_back)
  - [02. Optimized Approach — Pre-Sized Vector](#2-optimized-approach--pre-sized-vector-with-a-single-loop)
  - [03. STL Approach — Using `insert()`](#3-stl-approach--using-vector-copy-and-insert)
- [💡 Key Learnings](#-key-learnings)
- [🔗 Problem Navigation](#-problem-navigation)

---

## 📘 Problem Statement

Given an integer array `nums` of length `n`, create a new array `ans` of length `2 * n`.

The new array should contain the elements of `nums` **twice, in the same order**.

For every index `i` where `0 <= i < n`:

- `ans[i] = nums[i]`
- `ans[i + n] = nums[i]`

Return the resulting array `ans`.

---

## 🧪 Examples

### Example 1

**Input:** `nums = [1, 2, 1]`

**Output:** `[1, 2, 1, 1, 2, 1]`

**Explanation:** The original array `[1, 2, 1]` is concatenated with itself.

### Example 2

**Input:** `nums = [1, 3, 2, 1]`

**Output:** `[1, 3, 2, 1, 1, 3, 2, 1]`

**Explanation:** The original array `[1, 3, 2, 1]` is repeated twice, preserving the order of its elements.

---

## 📏 Constraints

- `n == nums.length`
- `1 <= n <= 1000`
- `1 <= nums[i] <= 1000`

---

## 📊 Solutions Overview

| # | Approach | Time Complexity | Auxiliary Space* | Output Space |
|---:|---|---|---|---|
| 1 | Two-Pass Loops (`push_back()`) | `O(n)` amortized | `O(1)` excluding output, excluding allocator overhead | `O(n)` |
| 2 | Pre-Sized Vector (Single Loop) | `O(n)` | `O(1)` | `O(n)` |
| 3 | STL Vector Copy and `insert()` | `O(n)` | `O(1)` excluding output, excluding allocator overhead | `O(n)` |

**Note:** The returned vector stores `2n` elements, so its output space is `O(n)`. Auxiliary space excludes the returned output. The table describes algorithmic working space and excludes implementation-specific allocator overhead.

---

# 1. Two-Pass Loops — Using `push_back()`

## 1.1 Approach Explanation

Create an empty vector `ans`. Use the first loop to copy every element of `nums` into `ans`. Then use a second loop to append the original array again using `push_back()`.

The first loop copies the array once, and the second loop adds the same elements again. This creates two copies of the original array in the same order.

## 1.2 Code (C++)

**File:** [`solution-1.cpp`](solution-1.cpp)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // First pass: Copy the original array.
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        // Second pass: Append the array again.
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        return ans;
    }
};
```

## 1.3 Code Explanation

- `int n = nums.size();` — Stores the length of the original array.
- `vector<int> ans;` — Creates an empty vector to store the result.
- First `for` loop — Copies every element of `nums` into `ans`.
- `ans.push_back(nums[i]);` — Adds the current element to the end of the vector.
- Second `for` loop — Traverses `nums` again and appends every element a second time.
- `return ans;` — Returns the concatenated array containing `2 * n` elements.

## 1.4 Dry Run

**Input:** `nums = [1, 2, 3]`

Initially, `n = 3` and `ans = []`.

**First pass: Copy the original array**

| `i` | `nums[i]` | `ans` |
|---:|---:|---|
| 0 | 1 | `[1]` |
| 1 | 2 | `[1, 2]` |
| 2 | 3 | `[1, 2, 3]` |

**Second pass: Append the array again**

| `i` | `nums[i]` | `ans` |
|---:|---:|---|
| 0 | 1 | `[1, 2, 3, 1]` |
| 1 | 2 | `[1, 2, 3, 1, 2]` |
| 2 | 3 | `[1, 2, 3, 1, 2, 3]` |

**Output:** `[1, 2, 3, 1, 2, 3]`

## 1.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)` Amortized

- The first loop performs `n` insertions.
- The second loop performs another `n` insertions.
- There are `2n` calls to `push_back()`.
- Each `push_back()` takes amortized `O(1)` time.

Therefore, the overall time complexity is **`O(n)` amortized**.

### 💾 Auxiliary Space: `O(1)` Excluding Output

The algorithm uses a constant number of additional variables, such as `n` and `i`. The returned vector itself stores `2n` elements and requires `O(n)` output space.

## 1.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| First loop | `O(n)` amortized | Builds output |
| Second loop | `O(n)` amortized | Extends output |
| Overall algorithm | `O(n)` amortized | `O(n)` output, `O(1)` auxiliary |

---

# 2. Optimized Approach — Pre-Sized Vector with a Single Loop

## 2.1 Approach Explanation

Create a vector `ans` with a size of `2 * n`, where `n` is the length of the original array. This allocates enough space for both copies from the beginning.

Use a single loop to copy each element of `nums` into two positions in `ans`.

- `ans[i] = nums[i]` — Copies the element into the first half.
- `ans[i + n] = nums[i]` — Copies the same element into the second half.

Since the vector already has the required size, we can assign values directly using indices instead of repeatedly calling `push_back()`.

## 2.2 Code (C++)

**File:** [`solution-2.cpp`](solution-2.cpp)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        // Copy each element into both halves of the answer.
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
```

## 2.3 Code Explanation

- `int n = nums.size();` — Stores the length of the original array.
- `vector<int> ans(2 * n);` — Creates a vector containing `2 * n` elements, initialized to zero.
- `for (int i = 0; i < n; i++)` — Traverses the original array once.
- `ans[i] = nums[i];` — Copies the current element into the first half of `ans`.
- `ans[i + n] = nums[i];` — Copies the same element into the corresponding position in the second half.
- `return ans;` — Returns the concatenated array.

## 2.4 Dry Run

**Input:** `nums = [1, 2, 3]`

Initially, `n = 3` and `ans` contains `2 * 3 = 6` initialized elements.

`ans = [0, 0, 0, 0, 0, 0]`

**Single pass: Copy elements into both halves**

| `i` | `nums[i]` | First-half assignment | Second-half assignment | `ans` |
|---:|---:|---|---|---|
| 0 | 1 | `ans[0] = 1` | `ans[3] = 1` | `[1, 0, 0, 1, 0, 0]` |
| 1 | 2 | `ans[1] = 2` | `ans[4] = 2` | `[1, 2, 0, 1, 2, 0]` |
| 2 | 3 | `ans[2] = 3` | `ans[5] = 3` | `[1, 2, 3, 1, 2, 3]` |

**Output:** `[1, 2, 3, 1, 2, 3]`

## 2.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)`

- Initializing `ans` with `2n` elements takes `O(n)` time.
- The loop runs exactly `n` times.
- Each iteration performs two constant-time assignments.

Therefore, the overall time complexity is **`O(n)`**.

### 💾 Auxiliary Space: `O(1)` Excluding Output

The algorithm uses a constant number of additional variables. The vector `ans` stores `2n` elements and requires `O(n)` output space.

## 2.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Initialize `ans` | `O(n)` | Allocates output |
| Single loop | `O(n)` | `O(1)` auxiliary |
| Overall algorithm | `O(n)` | `O(n)` output, `O(1)` auxiliary |

---

# 3. STL Approach — Using Vector Copy and `insert()`

## 3.1 Approach Explanation

Create a vector `ans` by copying all elements of the original array `nums`. Then use the built-in `insert()` function to append the entire original array to the end of `ans`.

- `vector<int> ans = nums;` — Creates a copy of `nums`.
- `ans.insert(ans.end(), nums.begin(), nums.end());` — Inserts all elements in the specified range at the end of `ans`.

Here, `ans.end()` specifies the insertion position, while `nums.begin()` and `nums.end()` specify the range of elements to copy.

The ending iterator `nums.end()` is **exclusive**, meaning it points just past the last element.

This approach uses C++ Standard Template Library (STL) functions to concatenate the array without writing an explicit loop.

## 3.2 Code (C++)

**File:** [`solution-3.cpp`](solution-3.cpp)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;

        // Append all elements of nums to the end of ans.
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};
```

## 3.3 Code Explanation

- `vector<int> ans = nums;` — Creates a separate vector containing a copy of every element in `nums`.
- `ans.insert(...)` — Uses the vector's built-in `insert()` function to add a range of elements.
- `ans.end()` — Specifies the position at the end of `ans`.
- `nums.begin()` — Points to the first element of the original array.
- `nums.end()` — Points just past the last element, marking the end of the range.
- `return ans;` — Returns the concatenated vector containing two copies of the original array.

## 3.4 Dry Run

**Input:** `nums = [1, 2, 3]`

**Step 1: Copy the original array**

```cpp
vector<int> ans = nums;
```

After copying:

- `nums = [1, 2, 3]`
- `ans = [1, 2, 3]`

**Step 2: Append the original array**

```cpp
ans.insert(ans.end(), nums.begin(), nums.end());
```

- `ans.end()` — Selects the position after the last element of `ans`.
- `nums.begin()` — Marks the beginning of the range.
- `nums.end()` — Marks the end of the range, just past the last element.

The elements `[1, 2, 3]` are appended to `ans`.

After insertion:

`ans = [1, 2, 3, 1, 2, 3]`

**Output:** `[1, 2, 3, 1, 2, 3]`

## 3.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)`

- Copying `nums` into `ans` takes `O(n)` time.
- Inserting the `n` elements at the end of `ans` takes `O(n)` time.
- The total work is proportional to `2n`.

Therefore, the overall time complexity is **`O(n)`**.

### 💾 Auxiliary Space: `O(1)` Excluding Output

The returned vector `ans` stores `2n` elements and requires `O(n)` output space. Apart from the result and implementation-specific allocation overhead, the algorithm uses a constant number of additional variables.

## 3.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Copy `nums` into `ans` | `O(n)` | Builds output |
| Insert the original range | `O(n)` | Extends output |
| Overall algorithm | `O(n)` | `O(n)` output, `O(1)` auxiliary |

---

## 💡 Key Learnings

- **Two-Pass Loops:** A beginner-friendly approach that copies the array twice using `push_back()`.
- **Pre-Sized Vector:** Creates the result vector in advance and fills both halves using a single loop.
- **STL `insert()`:** Uses built-in vector functions to append the original array without writing an explicit loop.
- **Indexing:** The position `i + n` places each element in the second half of the result.
- **Best Approach:** The pre-sized vector approach makes destination indices explicit and fills both halves in one loop. The STL approach is the most concise.
- **Complexity:** All three approaches achieve `O(n)` time and `O(n)` output space.

---



<p align="center">
  <a href="https://leetcode.com/problems/contains-duplicate/">
    <img src="https://img.shields.io/badge/LeetCode-217%20Contains%20Duplicate-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 217: Contains Duplicate" />
  </a>
</p>

<p align="center">
  <b>🚀 Keep Practising. Understand the Logic. Optimize Your Code.</b>
</p>

<p align="center">
  Every problem has a story. Every solution has a different approach.
</p>

<p align="center">
  <i>Thanks for watching… I mean, reading. 🍿</i>
</p>

<p align="center">
  <b>Until the next problem, keep debugging your plot. 🎥💻</b>
</p>

<p align="center">
  <strong>𝗔𝘁𝗵𝗿𝘃𝘃</strong>
</p>
