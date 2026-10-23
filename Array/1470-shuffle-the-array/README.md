# 1470. Shuffle the Array

**A collection of C++ solutions, from preallocated vectors to two-pointer traversal.**

<p align="center">
  <a href="https://leetcode.com/problems/shuffle-the-array/">
    <img src="https://img.shields.io/badge/LeetCode-1470%20Shuffle%20the%20Array-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 1470" />
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


## 📘 Problem Statement

Given an array `nums` consisting of `2n` elements in the form:

`[x1, x2, ..., xn, y1, y2, ..., yn]`

Return the array in the form:

`[x1, y1, x2, y2, ..., xn, yn]`

The goal is to interleave the first half and the second half of the original array while preserving the order of elements in each half.

---

## 🧪 Examples

### Example 1

**Input:** `nums = [2, 5, 1, 3, 4, 7], n = 3`

**Output:** `[2, 3, 5, 4, 1, 7]`

**Explanation:** The first half is `[2, 5, 1]` and the second half is `[3, 4, 7]`. Take one element from each half alternately.

### Example 2

**Input:** `nums = [1, 2, 3, 4, 4, 3, 2, 1], n = 4`

**Output:** `[1, 4, 2, 3, 3, 2, 4, 1]`

**Explanation:** Each element from the first half is followed by the corresponding element from the second half.

### Example 3

**Input:** `nums = [1, 1, 2, 2], n = 2`

**Output:** `[1, 2, 1, 2]`

**Explanation:** The two halves `[1, 1]` and `[2, 2]` are interleaved.

---

## 📏 Constraints

- `1 <= n <= 500`
- `nums.length == 2 * n`
- `1 <= nums[i] <= 1000`

---

## 📊 Solutions Overview

| # | Approach | Time Complexity | Auxiliary Space* | Output Space |
|---:|---|---|---|---|
| 1 | Preallocated Vector (Single Loop) | `O(n)` | `O(1)` | `O(n)` |
| 2 | Two Pointers (`push_back()`) | `O(n)` amortized | `O(1)` | `O(n)` |

**Note:** Both approaches return a new vector containing `2n` elements, requiring `O(n)` output space. Auxiliary space here excludes the returned output vector.

---

# 1. Preallocated Vector — Single Loop

## 1.1 Approach Explanation

Create a vector `ans` with a size of `2 * n`. This allocates enough space for all elements in the result before the loop begins.

Use one loop to copy elements from both halves into their correct positions.

- `ans[2 * i] = nums[i]` — Places the element from the first half at an even index.
- `ans[2 * i + 1] = nums[i + n]` — Places the corresponding element from the second half at the next odd index.

The loop runs `n` times, and each iteration places two elements into the result.

## 1.2 Code (C++)

**File:** [`approach-1-preallocated-vector.cpp`](approach-1-preallocated-vector.cpp)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);

        // Fill the even and odd indices.
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }

        return ans;
    }
};
```

## 1.3 Code Explanation

- `vector<int> ans(2 * n);` — Creates a vector with `2 * n` elements.
- `for (int i = 0; i < n; i++)` — Processes each position in the first half.
- `ans[2 * i] = nums[i];` — Places an `x` element at an even index.
- `ans[2 * i + 1] = nums[i + n];` — Places the corresponding `y` element at an odd index.
- `return ans;` — Returns the shuffled array.

## 1.4 Dry Run

**Input:** `nums = [2, 5, 1, 3, 4, 7], n = 3`

Initially:

- `n = 3`
- `ans = [0, 0, 0, 0, 0, 0]`

| `i` | First element | Second element | `ans` after iteration |
|---:|---|---|---|
| 0 | `ans[0] = nums[0] = 2` | `ans[1] = nums[3] = 3` | `[2, 3, 0, 0, 0, 0]` |
| 1 | `ans[2] = nums[1] = 5` | `ans[3] = nums[4] = 4` | `[2, 3, 5, 4, 0, 0]` |
| 2 | `ans[4] = nums[2] = 1` | `ans[5] = nums[5] = 7` | `[2, 3, 5, 4, 1, 7]` |

**Output:** `[2, 3, 5, 4, 1, 7]`

## 1.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)`

- The loop runs exactly `n` times.
- Each iteration performs two constant-time assignments.
- The vector initialization also takes `O(n)` time.

Therefore, the overall time complexity is `O(n)`.

### 💾 Auxiliary Space: `O(1)` Excluding Output

The algorithm uses a constant number of extra variables. The returned vector stores `2n` elements and requires `O(n)` output space.

## 1.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Initialize `ans` | `O(n)` | Allocates output |
| Single loop | `O(n)` | `O(1)` auxiliary |
| Overall algorithm | `O(n)` | `O(n)` output, `O(1)` auxiliary |

---

# 2. Two Pointers — Using `push_back()`

## 2.1 Approach Explanation

Create an empty vector `ans` and initialize two pointers:

- `i = 0` — Starts at the beginning of the first half.
- `j = n` — Starts at the beginning of the second half.

Use a `while` loop to add one element from each half to `ans`.

- `ans.push_back(nums[i++]);` — Adds the current first-half element, then increments `i`.
- `ans.push_back(nums[j++]);` — Adds the current second-half element, then increments `j`.

The loop continues while both pointers remain within their respective halves.

## 2.2 Code (C++)

**File:** [`approach-2-two-pointers.cpp`](approach-2-two-pointers.cpp)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i = 0, j = n;

        // Pick one element from each half.
        while (i < n && j < nums.size()) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }

        return ans;
    }
};
```

## 2.3 Code Explanation

- `vector<int> ans;` — Creates an empty vector for the result.
- `int i = 0, j = n;` — Initializes pointers for the two halves.
- `while (i < n && j < nums.size())` — Continues while both pointers are within bounds.
- `ans.push_back(nums[i++]);` — Appends an element from the first half and advances `i`.
- `ans.push_back(nums[j++]);` — Appends an element from the second half and advances `j`.
- `return ans;` — Returns the shuffled array.

## 2.4 Dry Run

**Input:** `nums = [2, 5, 1, 3, 4, 7], n = 3`

Initially:

- `i = 0`
- `j = 3`
- `ans = []`

| Iteration | `i` before | `j` before | Elements added | `ans` after iteration |
|---:|---:|---:|---|---|
| 1 | 0 | 3 | `2`, `3` | `[2, 3]` |
| 2 | 1 | 4 | `5`, `4` | `[2, 3, 5, 4]` |
| 3 | 2 | 5 | `1`, `7` | `[2, 3, 5, 4, 1, 7]` |

After the third iteration:

- `i = 3`, so `i < n` is false.
- `j = 6`, so `j < nums.size()` is false.

The loop stops.

**Output:** `[2, 3, 5, 4, 1, 7]`

## 2.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)` Amortized

- The loop runs `n` times.
- Each iteration appends two elements.
- `push_back()` takes amortized `O(1)` time per insertion.

Therefore, the overall time complexity is `O(n)` amortized.

### 💾 Auxiliary Space: `O(1)` Excluding Output

The algorithm uses two pointers and a constant number of additional variables. The returned vector requires `O(n)` output space. Vector capacity growth may involve implementation-specific allocation overhead.

## 2.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Initialize pointers | `O(1)` | `O(1)` |
| `while` loop | `O(n)` amortized | Builds output |
| Overall algorithm | `O(n)` amortized | `O(n)` output, `O(1)` auxiliary |

---

## 💡 Key Learnings

- **Preallocated Vector:** Creates the output vector at its final size and fills it using index calculations.
- **Two Pointers:** Uses `i` and `j` to select elements from the two halves.
- **Even and Odd Indices:** The first-half elements go into even indices, while the second-half elements go into odd indices.
- **`push_back()`:** Adds an element to the end of a vector.
- **`i++` and `j++`:** Use the current index first, then increment it.
- **Best Approach for Learning:** Both approaches are valid. Choose the one whose logic you understand best.
- **Complexity:** Both approaches achieve `O(n)` time and `O(n)` output space.

---

## 🔗 Problem Navigation

<p align="center">
  <a href="https://leetcode.com/problems/concatenation-of-array/">
    <img src="https://img.shields.io/badge/Previous-1929%20Concatenation%20of%20Array-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="Previous: LeetCode 1929" />
  </a>
  <a href="https://leetcode.com/problems/shuffle-the-array/">
    <img src="https://img.shields.io/badge/LeetCode-1470%20Shuffle%20the%20Array-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 1470" />
  </a>
</p>

<p align="center">
  <b>🚀 Keep Practising. Understand the Logic. Optimize Your Code.</b>
</p>

<p align="center">
  Every problem has a story. Every solution has a different approach.
</p>

<p align="center">
  <b>Atharv Bhavsar</b>
</p>
