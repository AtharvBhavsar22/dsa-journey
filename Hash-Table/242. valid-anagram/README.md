# 242. Valid Anagram

**LeetCode Problem:** [Valid Anagram](https://leetcode.com/problems/valid-anagram/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String, Sorting

These solutions check whether two strings contain the same characters with the same frequencies.

## Approaches

| File | Approach | Time | Extra space | Character support |
|---|---|---:|---:|---|
| [01. sorting.cpp](./01.%20sorting.cpp) | Sort both strings and compare | `O(n log n)` | `O(n)` for the copied strings | Characters supported by `string` |
| [02. two-hash-maps.cpp](./02.%20two-hash-maps.cpp) | Count each string separately | `O(n)` average | `O(k)` | Lowercase English letters |
| [03. single-hash-map-two-loops.cpp](./03.%20single-hash-map-two-loops.cpp) | Add counts, then subtract counts | `O(n)` average | `O(k)` | Characters supported by `char` |
| [04. single-hash-map-one-loop.cpp](./04.%20single-hash-map-one-loop.cpp) | Add and subtract counts in one traversal | `O(n)` average | `O(k)` | Characters supported by `char` |
| [05. single-frequency-array.cpp](./05.%20single-frequency-array.cpp) | Count with one 26-element array | `O(n)` | `O(1)` | Lowercase English letters |
| [06. two-frequency-arrays.cpp](./06.%20two-frequency-arrays.cpp) | Count with one array per string | `O(n)` | `O(1)` | Lowercase English letters |
| [07. byte-frequency-array.cpp](./07.%20byte-frequency-array.cpp) | Count byte values with one 256-element array | `O(n)` | `O(1)` | 8-bit byte values |

Here, `n` is the input string length and `k` is the number of distinct characters encountered. The hash-map approaches have average-case `O(n)` time.

The lowercase-only approaches assume every character is in the range `'a'` through `'z'`. The byte-array approach treats each `char` as an unsigned byte; it does not count Unicode code points.
