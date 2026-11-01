# 387. First Unique Character in a String

**LeetCode Problem:** [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String, Counting, Queue

Given a string `s`, return the index of its first non-repeating character.
Return `-1` if every character repeats. The input contains lowercase
English letters.

Each approach below is also available as a standalone `.cpp` file in this
folder.

---

## 1. Brute Force — Compare Every Pair

**Filename:** `01. brute-force.cpp`

For each character, scan the entire string to see whether it appears at
any other position. Return the first index that has no duplicate.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            bool isUnique = true;

            for (int j = 0; j < n; j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                return i;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** `O(n²)`  
**Space Complexity:** `O(1)` extra space.

---

## 2. Hash Map — Count, Then Find

**Filename:** `02. hash-map.cpp`

Count the occurrences of each character in an `unordered_map`. Scan the
string again and return the first index whose character has a count of
one.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** Expected `O(n)`  
**Space Complexity:** `O(k)`, where `k` is the number of distinct
characters.

---

## 3. Frequency Array — Count, Then Find

**Filename:** `03. frequency-array.cpp`

Because the input contains only lowercase English letters, use a
26-element array to count each character. Scan the string again to find
the first character with a frequency of one.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** `O(n)`  
**Space Complexity:** `O(1)` — the array always contains 26 counters.

---

## 4. Hash Map and Queue — Track Current Unique Candidate

**Filename:** `04. hash-map-queue.cpp`

Count characters as they are read and enqueue each character with its
index. Remove characters from the front while their frequency is greater
than one. The queue's front is the earliest character that has appeared
exactly once; if the queue is empty, no unique character exists.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<pair<char, int>> q;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            q.push({s[i], i});

            while (!q.empty() && freq[q.front().first] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.front().second;
    }
};
```

**Time Complexity:** Expected `O(n)` — each character is enqueued and
dequeued at most once.  
**Space Complexity:** `O(n)` for the queue and frequency map.

---

## 5. Frequency Array — Store First Index

**Filename:** `05. frequency-array-first-index.cpp`

Track both the frequency and first index for every lowercase letter.
After counting, inspect the 26 letters and select the smallest first
index among characters that occur exactly once.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        int firstIndex[26];

        fill(firstIndex, firstIndex + 26, -1);

        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';

            freq[index]++;

            if (firstIndex[index] == -1) {
                firstIndex[index] = i;
            }
        }

        int result = s.length();

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                result = min(result, firstIndex[i]);
            }
        }

        return result == s.length() ? -1 : result;
    }
};
```

**Time Complexity:** `O(n + 26)`, which is `O(n)`  
**Space Complexity:** `O(1)` — two arrays of 26 elements.
