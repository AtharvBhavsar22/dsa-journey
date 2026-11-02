# 409. Longest Palindrome

Given a string of English letters, return the length of the longest palindrome
that can be built from those letters. Each approach uses every available
matching pair and places at most one character with an odd frequency in the
middle.

## 01. Brute Force — Nested Loop Counting

For each character, count its occurrences across the string and skip it if it
has already been processed. Add all available pairs to the result, then add
one center character if any frequency is odd.

**Time Complexity:** `O(n²)`  
**Auxiliary Space:** `O(1)`

See [01. brute-force-nested-loop-counting.cpp](./01.%20brute-force-nested-loop-counting.cpp).

## 02. Sorting — Consecutive Frequency Counting

Sort the string so equal characters are adjacent. Scan each consecutive group
to count its frequency, add its pairs, and track whether a center character
can be used.

**Time Complexity:** `O(n log n)`  
**Auxiliary Space:** `O(log n)` typically for sorting; implementation-dependent

See [02. sorting-consecutive-frequency-counting.cpp](./02.%20sorting-consecutive-frequency-counting.cpp).

## 03. Frequency Array — Character Index Mapping

Use an array of 52 counters: indices `0`–`25` represent lowercase letters,
and indices `26`–`51` represent uppercase letters. This mapping relies on the
problem constraint that the input contains only English letters.

**Time Complexity:** `O(n)`  
**Auxiliary Space:** `O(1)`

See [03. frequency-array-character-index-mapping.cpp](./03.%20frequency-array-character-index-mapping.cpp).

## 04. Hash Map — Frequency Counting

Count each character with an `unordered_map`, then add each frequency's even
portion to the result and use one center character if any frequency is odd.

**Time Complexity:** `O(n)` average  
**Auxiliary Space:** `O(k)`, where `k` is the number of distinct characters

See [04. hash-map-frequency-counting.cpp](./04.%20hash-map-frequency-counting.cpp).
