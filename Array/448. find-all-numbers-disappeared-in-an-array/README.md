# 448. Find All Numbers Disappeared in an Array

[LeetCode Problem 448](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Problem Statement

Given an integer array `nums` of length `n` where every element is in the range `[1, n]`, return all numbers in `[1, n]` that do not appear in `nums`.

The returned numbers can be in any order.

## Approach Overview

| # | Approach | Time Complexity | Auxiliary Space | Source |
|---:|---|---:|---:|---|
| 1 | Brute Force — Linear Search | `O(n²)` | `O(1)` | [01-brute-force-linear-search.cpp](./01-brute-force-linear-search.cpp) |
| 2 | Brute Force — Range Vector + Linear Search | `O(n²)` | `O(n)` | [02-brute-force-range-vector.cpp](./02-brute-force-range-vector.cpp) |
| 3 | Sorting + Binary Search | `O(n log n)` | `O(log n)` | [03-sorting-binary-search.cpp](./03-sorting-binary-search.cpp) |
| 4 | Unordered Set — Presence Tracking | `O(n)` average | `O(n)` | [04-unordered-set.cpp](./04-unordered-set.cpp) |
| 5 | Cyclic Sort — Index Placement | `O(n)` | `O(1)` | [05-cyclic-sort-index-placement.cpp](./05-cyclic-sort-index-placement.cpp) |
| 6 | Negative Marking — Index Marking | `O(n)` | `O(1)` | [06-negative-marking.cpp](./06-negative-marking.cpp) |

Auxiliary-space figures exclude the returned answer vector. The sorting approach's space includes the `O(log n)` stack used by `std::sort`. Approaches 3, 5, and 6 modify `nums`.

## 1. Brute Force — Linear Search

For every number from `1` through `n`, linearly search the input array. Add the number to the answer if it is not present. The outer loop checks `n` numbers, and each search can inspect all `n` array elements.

- **Time:** `O(n²)`
- **Auxiliary space:** `O(1)`
- **Source:** [01-brute-force-linear-search.cpp](./01-brute-force-linear-search.cpp)

## 2. Brute Force — Range Vector + Linear Search

First build a vector containing every number from `1` through `n`. Search the input for each value in that range vector and collect the missing ones. This performs the same quadratic number of comparisons as approach 1, with an additional `O(n)` range vector.

- **Time:** `O(n²)`
- **Auxiliary space:** `O(n)`
- **Source:** [02-brute-force-range-vector.cpp](./02-brute-force-range-vector.cpp)

## 3. Sorting + Binary Search

Sort `nums`, then binary-search for each number in `[1, n]`. Sorting and the `n` binary searches each take `O(n log n)` time. Sorting changes the input array.

- **Time:** `O(n log n)`
- **Auxiliary space:** `O(log n)` for the sorting call stack
- **Source:** [03-sorting-binary-search.cpp](./03-sorting-binary-search.cpp)

## 4. Unordered Set — Presence Tracking

Insert all values into an `unordered_set`, then check which values from `1` through `n` are absent. Hash lookups and insertions take `O(1)` average time, giving `O(n)` average total time and `O(n)` auxiliary space.

- **Time:** `O(n)` average
- **Auxiliary space:** `O(n)`
- **Source:** [04-unordered-set.cpp](./04-unordered-set.cpp)

## 5. Cyclic Sort — Index Placement

Place each value `c` at index `c - 1` by swapping it into its corresponding position. Once values are in their target positions, scan the array: a mismatch at index `i` means the number `i + 1` is missing. Each value is moved into place at most once, so the total work is linear. This rearranges the input array.

- **Time:** `O(n)`
- **Auxiliary space:** `O(1)`
- **Source:** [05-cyclic-sort-index-placement.cpp](./05-cyclic-sort-index-placement.cpp)

## 6. Negative Marking — Index Marking

For each value `c`, use index `abs(c) - 1` to mark that number as present by making the value at that index negative. A final scan collects the indices that remain positive. The input array is modified in place.

- **Time:** `O(n)`
- **Auxiliary space:** `O(1)`
- **Source:** [06-negative-marking.cpp](./06-negative-marking.cpp)
