# 36. Valid Sudoku

**LeetCode Problem:** [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Matrix

Determine whether a partially filled 9 × 9 Sudoku board is valid. Each digit must appear at most once in every row, column, and 3 × 3 box. Empty cells (`.`) are ignored. The board does not need to be solvable.

## Solutions

| File | Approach | Time complexity | Auxiliary space |
|---|---|---:|---:|
| [01.brute-force-separate-row-column-box-checks.cpp](./01.brute-force-separate-row-column-box-checks.cpp) | Check rows, columns, and boxes separately using a set for each check | `O(1)` | `O(1)` |
| [02.optimized-three-arrays-of-hash-sets.cpp](./02.optimized-three-arrays-of-hash-sets.cpp) | Scan the board once and track seen digits for each row, column, and box | `O(1)` | `O(1)` |

Both complexities are constant because the board is always 9 × 9.
