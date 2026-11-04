# 229. Majority Element II

**LeetCode Problem:** [Majority Element II](https://leetcode.com/problems/majority-element-ii/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Sorting, Divide and Conquer, Counting

Return every element that appears more than `⌊n / 3⌋` times. There can be at most two such elements.

## Solutions

| File | Approach | Time complexity | Auxiliary space |
|---|---|---:|---:|
| [01.brute-force-nested-loops.cpp](./01.brute-force-nested-loops.cpp) | Count occurrences of each distinct value with nested loops | `O(n²)` | `O(1)` excluding the result |
| [02.hash-map-frequency-counting.cpp](./02.hash-map-frequency-counting.cpp) | Count each value with a hash map | Average `O(n)` | `O(n)` |
| [03.sorting-frequency-counting.cpp](./03.sorting-frequency-counting.cpp) | Sort values and count each consecutive run | `O(n log n)` | `O(1)` auxiliary, excluding sort stack and result |
| [04.divide-and-conquer.cpp](./04.divide-and-conquer.cpp) | Recursively find candidates in each half and count them in the current range | `O(n log n)` | `O(log n)` recursion stack |
| [05.boyer-moore-voting-algorithm.cpp](./05.boyer-moore-voting-algorithm.cpp) | Find up to two candidates, then verify their counts | `O(n)` | `O(1)` excluding the result |

The sorting solution sorts `nums` in place. The hash-map solution returns qualifying values in unspecified order.
