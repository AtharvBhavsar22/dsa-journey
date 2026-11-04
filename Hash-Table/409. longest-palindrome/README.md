# 387. First Unique Character in a String

**LeetCode Problem:** [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String, Queue, Counting

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Brute Force – Nested Loop Frequency Counting

**Approach:** Traverse the string using a nested loop. For each character, count its total occurrences in the string by comparing it with every other character.

To avoid processing the same character multiple times, use another loop to check whether the character has already appeared at an earlier index. If it has, skip it.

If the frequency is even, add the entire count to `ans`. If it is odd, add `count - 1` to `ans` and set `hasOdd = true`.

Finally, if at least one character has an odd frequency, increment `ans` by one to place a remaining character in the middle of the palindrome.

### Code

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        bool hasOdd = false;

        // Step 1: Count the frequency of each character
        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    count++;
                }
            }

            // Step 2: Process each character only once
            bool alreadyProcessed = false;

            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    alreadyProcessed = true;
                    break;
                }
            }

            if (alreadyProcessed) continue;

            // Step 3: Add pairs to the answer
            if (count % 2 == 0) {
                ans += count;
            }
            else {
                ans += count - 1;
                hasOdd = true;
            }
        }

        // Step 4: Add one middle character if available
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## 2. Sorting – Consecutive Frequency Counting

**Approach** Sort the string using `sort(s.begin(), s.end())` so that all occurrences of the same character come together.

Traverse the sorted string and count consecutive occurrences of each character using a `while` loop. Maintain `count` to store the frequency of the current character and `ch` to store that character.

If the frequency is even, add the entire count to `ans`. If it is odd, add `count - 1` to `ans` and set `hasOdd = true`.

Since `i` is incremented inside the `while` loop, we do not need to increment it in the `for` loop.

Finally, if `hasOdd` is true, increment `ans` by one to place a remaining character in the middle of the palindrome.

### Code

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());

        int n = s.length();
        int ans = 0;
        bool hasOdd = false;

        // Step 1: Traverse the sorted string
        for (int i = 0; i < n;) {
            int count = 0;
            char ch = s[i];

            // Step 2: Count consecutive occurrences
            while (i < n && s[i] == ch) {
                count++;
                i++;
            }

            // Step 3: Add pairs to the answer
            if (count % 2 == 0) {
                ans += count;
            }
            else {
                ans += count - 1;
                hasOdd = true;
            }
        }

        // Step 4: Add one middle character if available
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:**  `O(log n)`

---

## 3.Frequency Array – Character Index Mapping

**Approach**

Instead of using a Hash Map, we maintain a fixed-size integer array of **52 positions** to store the frequency of each character.

Why 52 positions?

Because the input contains English uppercase and lowercase letters:

- **Index 0 to 25:** Stores the frequencies of lowercase characters `a` to `z`.
- **Index 26 to 51:** Stores the frequencies of uppercase characters `A` to `Z`.

We initialize the entire array with zero:

```cpp
int freq[52] = {0};
```


**For lowercase characters (`a–z`):**

```cpp
freq[s[i] - 'a']++;
```

Subtracting `'a'` from the current character gives an index between 0 and 25.

For example:

| Character | Calculation | Array Index |
|---|---|---:|
| a | `'a' - 'a'` | 0 |
| b | `'b' - 'a'` | 1 |
| c | `'c' - 'a'` | 2 |
| z | `'z' - 'a'` | 25 |

**For uppercase characters (`A–Z`):**

```cpp
freq[s[i] - 'A' + 26]++;
```

Subtracting `'A'` gives an index between 0 and 25. We add 26 to shift the index into the second half of the array.

For example:

| Character | Calculation | Array Index |
|---|---|---:|
| A | `'A' - 'A' + 26` | 26 |
| B | `'B' - 'A' + 26` | 27 |
| C | `'C' - 'A' + 26` | 28 |
| Z | `'Z' - 'A' + 26` | 51 |

This way, lowercase and uppercase characters get separate positions in the same array.

**Calculate the Maximum Palindrome Length**

After storing all character frequencies, traverse the entire array from index 0 to 51.

We maintain two variables:

- `ans`: Stores the maximum possible palindrome length.
- `hasOdd`: Tracks whether at least one character has an odd frequency.

There are two cases:

**Case 1: Even Frequency**

If the frequency is even, we can use all its occurrences to form matching pairs.

```cpp
if (freq[i] % 2 == 0) {
    ans += freq[i];
}
```

**Case 2: Odd Frequency**

If the frequency is odd, subtract 1 to make it even and add the remaining occurrences to `ans`.

We also set `hasOdd = true` to remember that at least one character has an odd frequency.

```cpp
else {
    ans += freq[i] - 1;
    hasOdd = true;
}
```

**Step 3: Add One Character in the Middle**

After processing all 52 positions, if at least one character has an odd frequency, we can use one remaining character in the middle of the palindrome.

Even if multiple characters have odd frequencies, only one can be placed in the middle.

```cpp
if (hasOdd) {
    ans++;
}
```

### Code

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int freq[52] = {0};

        // Step 1: Count the frequency of each character
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                freq[s[i] - 'a']++;
            }
            else {
                freq[s[i] - 'A' + 26]++;
            }
        }

        int ans = 0;
        bool hasOdd = false;

        // Step 2: Calculate the maximum palindrome length
        for (int i = 0; i < 52; i++) {
            if (freq[i] % 2 == 0) {
                ans += freq[i];
            }
            else {
                ans += freq[i] - 1;
                hasOdd = true;
            }
        }

        // Step 3: Add one character in the middle if an odd frequency exists
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
```


**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)`

---

## 4. Hash Map – Frequency Counting

**Approach** 

We will use an `unordered_map` to maintain the frequency of each character in the string.

First, traverse the string and count the occurrences of every character by using `freq[s[i]]++`.

Once all frequencies are stored, traverse the Hash Map and maintain an `ans` variable to calculate the maximum possible length of the palindrome.

### How It Works

There are two cases to consider while processing each character's frequency:

**Case 1: Even Frequency**

If the frequency is even, we can use all its occurrences because they can be divided equally between the left and right sides of the palindrome.

```cpp
if (it->second % 2 == 0) {
    ans += it->second;
}
```

For example, if a character occurs 4 times, we can use all 4 occurrences to form 2 matching pairs.

**Case 2: Odd Frequency**

If the frequency is odd, we cannot use all its occurrences to form pairs.

Therefore, subtract 1 from the frequency to make it even, and add the remaining pairs to `ans`.

```cpp
else {
    ans += it->second - 1;
    hasOdd = true;
}
```

For example, if a character occurs 5 times, we use `5 - 1 = 4` occurrences to form 2 matching pairs.

We also maintain a boolean variable `hasOdd` to keep track of whether at least one character has an odd frequency.

### Why Do We Need `hasOdd`?

After processing all character frequencies, if at least one odd frequency exists, we can use one remaining character in the middle of the palindrome.

Even if multiple characters have odd frequencies, we can use only one of their remaining occurrences in the middle.

For this, we check `hasOdd` at the end and increment `ans` by one if it is true.

```cpp
if (hasOdd) {
    ans++;
}
```

### Code

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count the frequency of each character
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int ans = 0;
        bool hasOdd = false;

        // Step 2: Calculate the maximum palindrome length
        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (it->second % 2 == 0) {
                ans += it->second;
            }
            else {
                ans += it->second - 1;
                hasOdd = true;
            }
        }

        // Step 3: Add one character in the middle if an odd frequency exists
        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
```

**Time Complexity:**` O(n)`

**Space Complexity:**  `O(k) `


---
Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/0e38bb6f-630d-40fd-b054-20d45b0f650d_1717459756.9780626.png" width="400">
