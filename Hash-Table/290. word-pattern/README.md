# 290. Word Pattern

**LeetCode Problem:** [Word Pattern](https://leetcode.com/problems/word-pattern/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String

Determine whether a string of space-separated words follows the same pattern as a sequence of lowercase letters. The mapping must be one-to-one: each pattern character maps to one word, and each word maps to one pattern character.

## Solutions

| File | Approach | Time complexity | Auxiliary space |
|---|---|---:|---:|
| [01.hash-map-bidirectional-mapping.cpp](./01.hash-map-bidirectional-mapping.cpp) | Keep character-to-word and word-to-character maps | Average `O(n + c)` | `O(c + w)` |
| [02.brute-force-pairwise-comparison.cpp](./02.brute-force-pairwise-comparison.cpp) | Compare every pair of positions after splitting the words | `O(n² + c + w)` | `O(c + w)` |
| [03.hash-map-hash-set.cpp](./03.hash-map-hash-set.cpp) | Map pattern characters and track words already assigned | Average `O(n + c)` | `O(c + w)` |
| [04.last-seen-index-array-hash-map.cpp](./04.last-seen-index-array-hash-map.cpp) | Compare last-seen positions for each pattern character and word | Average `O(n + c)` | `O(1 + w)` |

Here, `n` is the pattern length, `c` is the total number of characters in the input words, and `w` is the number of distinct words. The input string is tokenized using `stringstream`; costs include reading and storing its words. The last-seen array assumes lowercase English letters, as guaranteed by the problem constraints.
