# 447. Number of Boomerangs

**LeetCode Problem:** [Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Math, Sorting

A boomerang is an ordered tuple of distinct points `(i, j, k)` where the distance from `i` to `j` equals the distance from `i` to `k`.

## Solutions

| File | Approach | Time complexity | Auxiliary space |
|---|---|---:|---:|
| [01.hash-map-distance-frequency-counting.cpp](./01.hash-map-distance-frequency-counting.cpp) | For each reference point, count squared distances in a hash map | Average `O(n²)` | `O(n)` |
| [02.sorting-distance-grouping.cpp](./02.sorting-distance-grouping.cpp) | For each reference point, sort squared distances and count equal groups | `O(n² log n)` | `O(n)` |

For any distance occurring `count` times from a reference point, it contributes `count × (count - 1)` ordered pairs.
