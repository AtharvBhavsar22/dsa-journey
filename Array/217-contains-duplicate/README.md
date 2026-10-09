# 👋 Hi, I'm 𝘼𝙩𝙝𝙧𝙫𝙫

🎓 IT Engineering Student · 💻 Developer · 🎬 Cinephile

Documenting my **LeetCode journey** through optimized solutions, clear explanations, and complexity analysis.

### 🧠 What You'll Find

- ⚡ Brute force to optimized approaches
- 💡 Intuition and problem-solving logic
- 📊 Time and space complexity
- 💻 Clean C++ solutions

🎯 **Goal:** Master DSA and prepare for technical interviews.

<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Platform-LeetCode-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode" />
  <img src="https://img.shields.io/badge/Focus-DSA-7C3AED?style=for-the-badge" alt="DSA" />
</p>

---

# 217. Contains Duplicate

**A collection of C++ solutions, from brute force to hashing.**

<p align="center">
  <img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge" alt="Easy" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++" />
  <img src="https://img.shields.io/badge/Topic-Arrays%20%7C%20Hashing-7C3AED?style=for-the-badge" alt="Arrays and Hashing" />
</p>

<p align="center">
  <a href="https://leetcode.com/problems/contains-duplicate/">
    🔗 View Problem on LeetCode
  </a>
</p>

---

## 📌 Table of Contents

- [📘 Problem Statement](#-problem-statement)
- [🧪 Examples](#-examples)
- [📏 Constraints](#-constraints)
- [📊 Solutions Overview](#-solutions-overview)
  - [01. Brute Force — Nested Loops](#1-brute-force--nested-loops)
  - [02. Sorting](#2-sorting)
  - [03. Unordered Set](#3-unordered-set)
  - [04. Unordered Map](#4-unordered-map)
- [💡 Key Learnings](#-key-learnings)

---

## 📘 Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array. Return `false` if every element is distinct.

## 🧪 Examples

### Example 1

- **Input:** `nums = [1, 2, 3, 1]`
- **Output:** `true`
- **Explanation:** The element `1` occurs at indices `0` and `3`.

### Example 2

- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `false`
- **Explanation:** All elements are distinct.

### Example 3

- **Input:** `nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]`
- **Output:** `true`
- **Explanation:** The array contains duplicate elements.

## 📏 Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---

## 📊 Solutions Overview

| # | Approach | Time Complexity | Auxiliary Space |
|---:|---|---|---|
| 1 | Brute Force (Nested Loops) | `O(n²)` | `O(1)` |
| 2 | Sorting | `O(n log n)` | `O(log n)`* |
| 3 | `unordered_set` | `O(n)` average | `O(n)` |
| 4 | `unordered_map` | `O(n)` average | `O(n)` |

> 💡 **Recommended Approach:** `unordered_set` — Provides average `O(n)` time complexity and directly checks whether an element has appeared before, without storing unnecessary values.

*Note: `std::sort` typically uses `O(log n)` auxiliary stack space.*

---

# 1. Brute Force — Nested Loops

## 1.1 Approach Explanation

Compare each element with every element that comes after it. If any pair is equal, return `true`. If all pairs are checked without finding a duplicate, return `false`.

This is called **brute force** because it checks all possible pairs instead of using a more optimized technique.

## 1.2 Code (C++)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

## 1.3 Code Explanation

1. **`vector<int>& nums`** — Stores the integer array. The `&` passes it by reference, avoiding an unnecessary copy.
2. **`int n = nums.size();`** — Stores the array length for use as the loop boundary.
3. **`for (int i = 0; i < n; i++)`** — Selects each element one by one.
4. **`for (int j = i + 1; j < n; j++)`** — Compares the current element only with the elements after it, avoiding self-comparisons and repeated pairs.
5. **`if (nums[i] == nums[j])`** — If the two elements are equal, a duplicate exists, so `return true` ends the function immediately.
6. **`return false;`** — Runs when every pair has been checked and no duplicate was found.

## 1.4 Dry Run

**Case 1: Duplicate exists**

Input: `nums = [1, 2, 3, 1]`

| `i` | `j` | Comparison | Result |
|---:|---:|---|---|
| 0 | 1 | `1 == 2` | Not equal |
| 0 | 2 | `1 == 3` | Not equal |
| 0 | 3 | `1 == 1` | Duplicate found |

**Output:** `true`

The function returns immediately when the duplicate `1` is found.

**Case 2: No duplicate**

Input: `nums = [1, 2, 3, 4]`

| `i` | `j` | Comparison | Result |
|---:|---:|---|---|
| 0 | 1 | `1 == 2` | Not equal |
| 0 | 2 | `1 == 3` | Not equal |
| 0 | 3 | `1 == 4` | Not equal |
| 1 | 2 | `2 == 3` | Not equal |
| 1 | 3 | `2 == 4` | Not equal |
| 2 | 3 | `3 == 4` | Not equal |

**Output:** `false`

Every pair is checked, and no duplicate is found.

## 1.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n²)` — Quadratic Time

The brute-force approach uses two nested loops:

1. **Outer Loop:** Selects each element in the array, running up to `n` times.
2. **Inner Loop:** Compares the selected element with the remaining elements.

**Total Time Complexity:**

\[
O(n \times n) = O(n^2)
\]

As the input size increases, the number of comparisons grows quadratically. Therefore, the overall time complexity is **`O(n²)`**.

### 💾 Space Complexity: `O(1)` — Constant Auxiliary Space

- **Loop Variables:** Only a few variables are used for iteration and comparison.
- **Extra Memory:** No additional array, set, or map is created.

Therefore, the auxiliary space complexity is **`O(1)`**.

### 📊 Complexity Summary

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Nested comparisons | `O(n²)` | `O(1)` |
| **Overall Algorithm** | **`O(n²)`** | **`O(1)`** |

> 💡 **Key Takeaway:** The brute-force approach compares elements pair by pair, resulting in `O(n²)` time complexity while using only `O(1)` auxiliary space.

## 1.6 Key Takeaways

- Nested loops compare each element with the elements after it.
- Starting `j` at `i + 1` avoids comparing an element with itself or repeating pairs.
- This approach uses constant extra space but can be slow for large arrays.

---

# 2. Sorting

## 2.1 Approach Explanation

Sort the array in ascending order. Duplicate elements will then be next to each other. Compare each element with its previous element; if they are equal, return `true`. If no adjacent pair matches, return `false`.

## 2.2 Code (C++)

```cpp
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};
```

## 2.3 Code Explanation

1. **`vector<int>& nums`** — Passes the input array by reference, avoiding a copy.
2. **`sort(nums.begin(), nums.end());`** — Uses `sort()` from `<algorithm>` to arrange the elements in ascending order, placing duplicate values next to each other.
3. **`for (int i = 1; i < nums.size(); i++)`** — Starts at index `1` because the first element has no previous element.
4. **`if (nums[i] == nums[i - 1])`** — Compares the current element with the previous one. If equal, a duplicate exists.
5. **`return false;`** — Runs if no adjacent elements are equal.

## 2.4 Dry Run

**Case 1: Duplicate exists**

Input: `nums = [1, 2, 3, 1]`

After sorting: `nums = [1, 1, 2, 3]`

| `i` | Comparison | Result |
|---:|---|---|
| 1 | `1 == 1` | Duplicate found |

**Output:** `true`

**Case 2: No duplicate**

Input: `nums = [1, 2, 3, 4]`

After sorting: `nums = [1, 2, 3, 4]`

| `i` | Comparison | Result |
|---:|---|---|
| 1 | `2 == 1` | Not equal |
| 2 | `3 == 2` | Not equal |
| 3 | `4 == 3` | Not equal |

**Output:** `false`

## 2.5 Complexity Analysis

**Time Complexity: `O(n log n)` — Linearithmic Time**

Sorting takes `O(n log n)` time. Checking adjacent elements takes `O(n)` time in the worst case.

Total:

`O(n log n) + O(n) = O(n log n)`

We keep `O(n log n)` because it grows faster than `O(n)` as the input size increases.

**Space Complexity: Typically `O(log n)` — Auxiliary Space**

`std::sort` typically uses `O(log n)` extra space for its recursion stack. It rearranges the original array instead of creating another full array. The comparison loop uses `O(1)` extra space. The exact auxiliary-space usage depends on the implementation.

## 2.6 Key Takeaways

- Sorting makes duplicate elements adjacent.
- Starting at index `1` lets each element be compared with its predecessor.
- Time improves over brute force to `O(n log n)`, but the original array is modified.

---

# 3. Unordered Set

## 3.1 Approach Explanation

Create an empty `unordered_set` to store elements already visited. Before inserting each element, check whether it already exists in the set. If it does, return `true`; otherwise, insert it and continue.

An `unordered_set` stores unique values and provides average `O(1)` lookup and insertion.

## 3.2 Code (C++)

```cpp
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            seen.insert(x);
        }

        return false;
    }
};
```

## 3.3 Code Explanation

1. **`unordered_set<int> seen;`** — Creates an empty set to store previously visited values.
2. **`for (int x : nums)`** — Visits each array element one at a time using a range-based loop.
3. **`if (seen.count(x))`** — Checks whether `x` is already in the set. `count(x)` returns `1` if found and `0` otherwise.
4. **`seen.insert(x);`** — Inserts the value if it has not appeared before.
5. **`return false;`** — Runs if every element is processed without finding a duplicate.

## 3.4 Dry Run

**Case 1: Duplicate exists**

Input: `nums = [1, 2, 3, 1]`

| Element (`x`) | Set Before Check | Action |
|---:|---|---|
| 1 | `{}` | Insert `1` |
| 2 | `{1}` | Insert `2` |
| 3 | `{1, 2}` | Insert `3` |
| 1 | `{1, 2, 3}` | Duplicate found |

**Output:** `true`

When `1` appears for the second time, it is already in the set.

**Case 2: No duplicate**

Input: `nums = [1, 2, 3, 4]`

| Element (`x`) | Set Before Check | Action |
|---:|---|---|
| 1 | `{}` | Insert `1` |
| 2 | `{1}` | Insert `2` |
| 3 | `{1, 2}` | Insert `3` |
| 4 | `{1, 2, 3}` | Insert `4` |

**Output:** `false`

Every element is new, so the loop finishes without finding a duplicate.

## 3.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)` — Linear Time on Average

The hash set approach performs two main operations:

1. **Lookup:** `seen.count(x)` checks whether the current element already exists in the set. Average time: `O(1)`.
2. **Insertion:** `seen.insert(x)` adds a new element to the set. Average time: `O(1)`.

In the worst case, all `n` elements are processed. Therefore:

\[
O(n \times 1) = O(n)
\]

Hence, the **average time complexity is `O(n)`**.

> ⚠️ **Worst Case:** Due to hash collisions, hash set operations can take `O(n)` each, resulting in an overall worst-case time complexity of `O(n²)`.

### 💾 Space Complexity: `O(n)` — Linear Auxiliary Space

- **Hash Set:** Stores the unique elements encountered in the array.
- **Additional Memory:** If all `n` elements are unique, the set stores up to `n` elements.

Therefore, the auxiliary space complexity is **`O(n)`**.

### 📊 Complexity Summary

| Operation | Average Time Complexity | Auxiliary Space |
|---|---|---|
| Hash set lookup | `O(1)` per lookup | — |
| Hash set insertion | `O(1)` per insertion | Up to `O(n)` total |
| **Overall Algorithm** | **`O(n)`** | **`O(n)`** |

> 💡 **Key Takeaway:** A hash set detects duplicates in average linear time by checking whether each element has appeared before, without sorting the array.

## 3.6 Key Takeaways

- The set stores unique values and helps identify elements seen earlier.
- Check the set before inserting the current element.
- Average `O(n)` time makes this efficient for large arrays, using `O(n)` extra space.

---

# 4. Unordered Map

## 4.1 Approach Explanation

Create an empty `unordered_map` and store each visited element as a key. Before inserting an element, check whether its key already exists. If it does, return `true`; otherwise, insert the key and continue.

An `unordered_map` provides average `O(1)` key lookup and insertion. However, this problem does not need mapped values, so `unordered_set` is a more suitable choice.

## 4.2 Code (C++)

```cpp
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            seen[x] = 1;
        }

        return false;
    }
};
```

## 4.3 Code Explanation

1. **`unordered_map<int, int> seen;`** — Creates a map with integer keys and integer values. The key tracks whether an element has appeared; the mapped value is not needed for this problem.
2. **`for (int x : nums)`** — Visits each element one at a time.
3. **`if (seen.count(x))`** — Checks whether `x` already exists as a key. If it does, a duplicate exists.
4. **`seen[x] = 1;`** — Inserts `x` as a key with the placeholder value `1`. It does not count occurrences.
5. **`return false;`** — Runs if no existing key is found.

## 4.4 Dry Run

**Case 1: Duplicate exists**

Input: `nums = [1, 2, 3, 1]`

| Element (`x`) | Map Before Check | Action |
|---:|---|---|
| 1 | `{}` | Insert key `1` |
| 2 | `{1:1}` | Insert key `2` |
| 3 | `{1:1, 2:1}` | Insert key `3` |
| 1 | `{1:1, 2:1, 3:1}` | Duplicate found |

**Output:** `true`

When `1` appears again, the map already contains key `1`.

**Case 2: No duplicate**

Input: `nums = [1, 2, 3, 4]`

| Element (`x`) | Map Before Check | Action |
|---:|---|---|
| 1 | `{}` | Insert key `1` |
| 2 | `{1:1}` | Insert key `2` |
| 3 | `{1:1, 2:1}` | Insert key `3` |
| 4 | `{1:1, 2:1, 3:1}` | Insert key `4` |

**Output:** `false`

Each key is new, so the loop completes without finding a duplicate.

## 4.5 Complexity Analysis

### ⏱️ Time Complexity: `O(n)` — Linear Time on Average

The hash map approach performs two main operations:

1. **Lookup:** `seen.count(x)` checks whether the current element already exists as a key in the map. Average time: `O(1)`.
2. **Insertion:** `seen[x] = 1` stores the current element as a key with the value `1`. Average time: `O(1)`.

In the worst case, all `n` elements are processed. Therefore:

`O(n × 1) = O(n)`

Hence, the **average time complexity is `O(n)`**.

> ⚠️ **Worst Case:** Due to hash collisions, hash map operations can take `O(n)` each, resulting in an overall worst-case time complexity of `O(n²)`.

### 💾 Space Complexity: `O(n)` — Linear Auxiliary Space

- **Hash Map:** Stores each unique element as a key with the value `1`.
- **Additional Memory:** If all `n` elements are unique, the map stores up to `n` key-value pairs.

Therefore, the auxiliary space complexity is **`O(n)`**.

### 📊 Complexity Summary

| Operation | Average Time Complexity | Auxiliary Space |
|---|---|---|
| Hash map lookup | `O(1)` per lookup | — |
| Hash map insertion | `O(1)` per insertion | Up to `O(n)` total |
| **Overall Algorithm** | **`O(n)`** | **`O(n)`** |

> 💡 **Key Takeaway:** A hash map detects duplicates in average linear time, but storing a value of `1` for each key is unnecessary when only duplicate existence matters. An `unordered_set` is the more suitable data structure for this problem.

## 4.6 Key Takeaways

- **Hash Map:** Tracks previously encountered elements using keys.
- **`seen.count(x)`:** Checks whether a key already exists.
- **`seen[x] = 1`:** Stores a key with the value `1`.
- **Best Fit:** `unordered_set` is preferable because only the presence of an element matters, not an associated value.

---

## 💡 Key Learnings

- **Brute Force:** A simple starting point, but nested comparisons can be expensive.
- **Sorting:** Places duplicates next to each other but modifies the input array.
- **Hashing:** Reduces average lookup time to `O(1)`.
- **Best Approach:** `unordered_set` provides average `O(n)` time and directly solves the duplicate detection problem.

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