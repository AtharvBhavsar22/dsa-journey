# 383. Ransom Note

**LeetCode Problem:** [Ransom Note](https://leetcode.com/problems/ransom-note/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String, Counting, Sorting, Two Pointers

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 01. Brute Force – Nested Loop Character Comparison

**Approach:** Traverse the string using an outer loop and check each character against every other character using an inner loop.

For every character `s[i]`, compare it with all other characters in the string. Skip the current index using `i != j`.

If a matching character is found, mark it as not unique and stop checking. If no duplicate is found, return the current index because it is the first unique character.

If no unique character exists, return `-1`.

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();

        for (int i = 0; i < n; i++) {
            bool isUnique = true;

            // Check all other characters
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

**Space Complexity:** `O(1)`

---

## 02. Hash Map – Character Frequency Counting

**Approach:** Use an `unordered_map<char, int>` to store the frequency of each character in the string.

First, traverse the string and increment the frequency of each character using `freq[s[i]]++`.

After counting all characters, traverse the string again from left to right. If the frequency of the current character is `1`, return its index because it is the first unique character.

If no character has a frequency of `1`, return `-1`.

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        // Step 2: Find the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(k)`

---

## 03. Frequency Array – Character Frequency Counting

**Approach:** Use a frequency array of size `26` to store the frequency of each lowercase English letter.

First, initialize the array with zeros. Traverse the string and increment the frequency of each character using `freq[s[i] - 'a']++`. Subtracting `'a'` maps each lowercase letter to an index between `0` and `25`.

After counting all characters, traverse the string again from left to right. If the frequency of the current character is `1`, return its index because it is the first unique character.

If no character has a frequency of `1`, return `-1`.

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Step 1: Count character frequencies
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Step 2: Find the first unique character
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

**Space Complexity:** `O(1)` 

---

## 04. Hash Map + Queue – Tracking First Unique Character

**Approach:** Use an `unordered_map<char, int>` to maintain the frequency of each character and a `queue<pair<char, int>>` to store characters along with their original indices.

Traverse the string from left to right. For every character, increment its frequency in the hash map and insert the character with its index into the queue.

After inserting each character, check the front of the queue using a `while` loop. If the frequency of the front character is greater than `1`, remove it using `q.pop()` because it is no longer unique.

Continue removing repeated characters until the queue becomes empty or its front contains a character with frequency `1`.

After processing the entire string, the front of the queue contains the first unique character. Return its index using `q.front().second`. If the queue is empty, return `-1`.

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<pair<char, int>> q;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;

            // Add the character and its index
            q.push({s[i], i});

            // Remove repeated characters from the front
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

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(n)` 

---

## 05. Frequency Array – Frequency and First Occurrence Tracking

**Approach:** Use two frequency arrays of size `26` to store the frequency and first occurrence index of each lowercase English letter.

Initialize `freq` with zeros and `firstIndex` with `-1` to indicate that no character has been encountered yet.

Traverse the string and calculate the array index using `s[i] - 'a'`. Increment the character's frequency and store its index in `firstIndex` only when it appears for the first time.

After processing the string, traverse all `26` array positions. For every character whose frequency is `1`, update `result` with the smallest first occurrence index using `min()`.

Finally, return `result`. If no unique character is found, return `-1`.

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        int firstIndex[26];

        fill(firstIndex, firstIndex + 26, -1);

        // Step 1: Store frequency and first occurrence
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';

            freq[index]++;

            if (firstIndex[index] == -1) {
                firstIndex[index] = i;
            }
        }

        // Step 2: Find the smallest index with frequency 1
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

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">

