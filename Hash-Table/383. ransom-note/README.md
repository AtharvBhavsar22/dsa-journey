Explored multiple approaches, from brute force to optimized solutions,
along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it
a try yourself!

---

## 01. Brute Force – Character Matching Using a Used Array

<badge color="warning">TLE – Time Limit Exceeded</badge>

**Approach:** Use a `vector<bool>` named `used` to keep track of which characters in `magazine` have already been used.

First, initialize the `used` array with `false`, where each position represents a character in `magazine`.

Next, traverse `ransomNote`. For each character, search through `magazine` using a nested loop.

If a matching character is found and its position has not been used, mark that position as `true` and move to the next character in `ransomNote`.

If no unused matching character is found, return `false`.

Finally, if all characters in `ransomNote` are successfully matched, return `true`.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        vector<bool> used(m, false);

        // Step 1: Find an unused matching character in magazine
        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < m; j++) {
                if (magazine[j] == ransomNote[i] && !used[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            // Step 2: Check whether a matching character was found
            if (!found) {
                return false;
            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n × m)`, 

**Space Complexity:** `O(m)`

---

## 2. Brute Force - Character Frequency Comparison Using count()

<badge color="warning">TLE – Time Limit Exceeded</badge>

**Approach:** Use the STL `count()` function to calculate the frequency of each character in both `ransomNote` and `magazine`.

First, check whether `ransomNote` is longer than `magazine`. If it is, return `false` because there are not enough characters available.

Next, traverse `ransomNote` and consider each character individually.

For every character, use `count()` to calculate:
- `required`: The number of times the character appears in `ransomNote`.
- `available`: The number of times the character appears in `magazine`.

If `required` is greater than `available`, return `false` because `magazine` does not contain enough occurrences of that character.

If all character frequencies satisfy the requirement, return `true`.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        // Step 1: Check whether magazine has enough characters
        if (n > m) {
            return false;
        }

        // Step 2: Check the frequency of each character
        for (int i = 0; i < n; i++) {
            char ch = ransomNote[i];

            int required = count(ransomNote.begin(), ransomNote.end(), ch);
            int available = count(magazine.begin(), magazine.end(), ch);

            // Step 3: Compare required and available frequencies
            if (required > available) {
                return false;
            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n × (n + m))`

**Space Complexity:** `O(n + m)` 

---

## 3. Brute Force - Find and Erase Characters

**Approach:** Traverse `ransomNote` and search for each character in `magazine` using `magazine.find(ransomNote[i])`.

If the character is not found, `find()` returns `string::npos`, which means the required character is unavailable. In that case, return `false`.

If the character is found, remove its first occurrence from `magazine` using `magazine.erase(pos, 1)`. This ensures that the same occurrence cannot be reused for another character in `ransomNote`.

Continue this process until all characters in `ransomNote` are found and removed. If every character is successfully matched, return `true`.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        // Step 1: Search for each ransomNote character in magazine
        for (int i = 0; i < n; i++) {
            size_t pos = magazine.find(ransomNote[i]);

            // Step 2: Check whether the character exists
            if (pos == string::npos) {
                return false;
            }

            // Step 3: Remove the matched character
            magazine.erase(pos, 1);
            m--;
        }

        // Step 4: All characters were successfully matched
        return true;
    }
};
```

**Time Complexity:** `O(n × m)`

**Space Complexity:** `O(m)`

---

## 4. Sorting - Sort Both Strings and Use Two Pointers

**Approach:** First, check whether `ransomNote` is longer than `magazine`. If it is, return `false` because there are not enough characters available.

Next, sort both strings in ascending order using `sort(ransomNote.begin(), ransomNote.end())` and `sort(magazine.begin(), magazine.end())`.

Use two pointers, `i` and `j`, to traverse both sorted strings.

- If both characters are equal, move both pointers forward.
- If `magazine[j]` is smaller than `ransomNote[i]`, move `j` forward to find the required character.
- If `ransomNote[i]` is smaller than `magazine[j]`, return `false` because the required character cannot be found in the remaining magazine characters.

Finally, return `i == n` to check whether all characters in `ransomNote` have been matched.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        // Step 1: Check whether magazine has enough characters
        if (n > m) {
            return false;
        }

        // Step 2: Sort both strings
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        int i = 0;
        int j = 0;

        // Step 3: Match characters using two pointers
        while (i < n && j < m) {
            if (ransomNote[i] == magazine[j]) {
                i++;
                j++;
            }
            else if (ransomNote[i] > magazine[j]) {
                j++;
            }
            else {
                return false;
            }
        }

        // Step 4: Check whether all ransomNote characters were matched
        return i == n;
    }
};
```

**Time Complexity:** `O(n log n + m log m)`

**Space Complexity:** `O(n + m)`


---

## 5. Hash Map - Count Magazine Characters and Decrement

**Approach:** Use an `unordered_map<char, int>` to store the frequency of each character in `magazine`.

First, traverse `magazine` and increment the frequency of each character using `freq[magazine[i]]++`.

Next, traverse `ransomNote` and decrement the frequency of each required character using `freq[ransomNote[i]]--`.

After decrementing, check whether the frequency becomes negative. If it does, the required character is unavailable or has been used more times than it appears in `magazine`, so return `false`.

Finally, if all characters are processed successfully, return `true`.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        int n = ransomNote.length();
        int m = magazine.length();

        // Step 1: Count the frequency of each character in magazine
        for (int i = 0; i < m; i++) {
            freq[magazine[i]]++;
        }

        // Step 2: Decrement the count for each character in ransomNote
        for (int i = 0; i < n; i++) {
            freq[ransomNote[i]]--;

            // Step 3: Check whether the count becomes negative
            if (freq[ransomNote[i]] < 0) {
                return false;
            }
        }

        // Step 4: All required characters are available
        return true;
    }
};
```

**Time Complexity:** `O(n + m)` 

**Space Complexity:** `O(k)`

---

## 6. Frequency Array - Count Magazine Characters and Decrement

**Approach:** Use an integer array `freq[26]` to store the frequency of each lowercase English character in `magazine`.

First, traverse `magazine` and increment the frequency of each character using `freq[magazine[i] - 'a']++`.

Next, traverse `ransomNote` and decrement the frequency of each required character using `freq[ransomNote[i] - 'a']--`.

After decrementing, check whether the frequency becomes negative. If it does, the required character is unavailable or has been used more times than it appears in `magazine`, so return `false`.

Finally, if all characters are processed successfully, return `true`.

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        int freq[26] = {0};

        // Step 1: Count the frequency of each character in magazine
        for (int i = 0; i < m; i++) {
            freq[magazine[i] - 'a']++;
        }

        // Step 2: Use the available characters for ransomNote
        for (int i = 0; i < n; i++) {
            freq[ransomNote[i] - 'a']--;

            // Step 3: Check whether the character count becomes negative
            if (freq[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(1)`

---

Thank you for taking the time to read this. Hope you find it helpful and
enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/0fdd2a8c-e63e-4a99-a028-442244a0126a_1688985760.8163922.jpeg" width="400">
