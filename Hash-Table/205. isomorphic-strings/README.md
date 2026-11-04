# 290. Word Pattern

**LeetCode Problem:** [Word Pattern](https://leetcode.com/problems/word-pattern/)  
**Difficulty:** Easy  
**Topics:** Hash Table, String, Two Pointers

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Hash Maps — Bidirectional Mapping

**Approach:**

First, we create two `unordered_map` containers to maintain mappings between pattern characters and words.

- `mp1` stores the mapping from characters in `pattern` to words in `s`.
- `mp2` stores the reverse mapping from words in `s` to characters in `pattern`.

We use `stringstream` to extract words from the string `s` one by one using `ss >> word`.

We traverse the pattern using a single loop. Before processing each character, we check whether a corresponding word is available. If no word is available, we return `false`.

For every character and word pair, we perform two checks:

**Forward Mapping:**

We use `mp1.find(ch)` to check whether the current pattern character has already been mapped.

If it exists, we compare its previously stored word with the current word. If they are different, we return `false`.

**Reverse Mapping:**

We use `mp2.find(word)` to check whether the current word has already been assigned to another pattern character.

If it exists and its stored character differs from `ch`, we return `false`.

**Store Both Mappings:**

If both checks pass, we store the mappings:

- `mp1[ch] = word`
- `mp2[word] = ch`

After traversing the pattern, we check whether any extra words remain in the string. If an extra word exists, we return `false`.

Otherwise, we return `true`.

**Code:**

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            char ch = pattern[i];

            // Check forward mapping
            if (mp1.find(ch) != mp1.end()) {
                if (mp1[ch] != word) {
                    return false;
                }
            }

            // Check reverse mapping
            if (mp2.find(word) != mp2.end()) {
                if (mp2[word] != ch) {
                    return false;
                }
            }

            // Store both mappings
            mp1[ch] = word;
            mp2[word] = ch;
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
```

**Time Complexity:** `O(n + L)` 

**Space Complexity:** `O(k + u)` 

---

## 2. Brute Force — Nested Loops

**Approach:**

First, we create a `vector<string>` called `words` to store all the words extracted from the string `s`.

We use `stringstream` to extract each word and insert it into the vector using `push_back()`.

Before comparing the characters and words, we check whether the number of extracted words matches the length of the pattern.

If the sizes are different, we return `false` because every pattern character must correspond to exactly one word.

Next, we use two nested loops to compare every pair of positions.

For every pair of indices `i` and `j`, we compare two conditions:

- `pattern[i] == pattern[j]` checks whether both positions contain the same pattern character.
- `words[i] == words[j]` checks whether both positions contain the same word.

We combine these conditions using the `!=` operator:

`(pattern[i] == pattern[j]) != (words[i] == words[j])`

If the results are different, the relationship between the pattern characters and words is inconsistent, so we return `false`.

If all pairs satisfy the condition, we return `true`.

**Code:**

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        stringstream ss(s);
        string word;

        // Step 1: Extract all words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Check the number of words
        if (words.size() != pattern.length()) {
            return false;
        }

        // Step 3: Compare every pair of positions
        for (int i = 0; i < pattern.length(); i++) {

            for (int j = i + 1; j < pattern.length(); j++) {

                if ((pattern[i] == pattern[j]) != (words[i] == words[j])) {
                    return false;
                }
            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n² + L)` 

**Space Complexity:** `O(n + L)` 

---

## 3. Hash Map + Hash Set — Forward Mapping

**Approach:**

First, we create an `unordered_map<char, string>` called `mp` to store mappings from pattern characters to words.

We also create an `unordered_set<string>` called `used` to track words that have already been assigned.

We use `stringstream` to extract words one by one and traverse the pattern using a single loop.

For every character and word pair, we perform two checks:

**Check Existing Mapping:**

We use `mp.find(ch)` to check whether the current pattern character already exists in the map.

If it exists, we compare its previously stored word with the current word.

If they are different, we return `false` because the same pattern character cannot map to different words.

**Check Used Words:**

If the current pattern character does not exist in the map, we check whether the current word already exists in the `used` set.

If it exists, another pattern character has already been assigned to that word, so we return `false`.

**Store the Mapping:**

If the pattern character is new and the word has not been used, we store the mapping:

- `mp[ch] = word` stores the forward mapping.
- `used.insert(word)` marks the word as already assigned.

After processing all pattern characters, we check whether any extra words remain.

If no extra words or invalid mappings are found, we return `true`.

**Code:**

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp;
        unordered_set<string> used;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            char ch = pattern[i];

            // Check existing mapping
            if (mp.find(ch) != mp.end()) {

                if (mp[ch] != word) {
                    return false;
                }

            }
            else {

                // Check whether the word is already used
                if (used.find(word) != used.end()) {
                    return false;
                }

                // Store the mapping
                mp[ch] = word;
                used.insert(word);
            }
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
```

**Time Complexity:** `O(n + L)` 

**Space Complexity:** `O(k + u)`

---

## 4. Last Seen Index — Array + Hash Map

**Approach:**

Instead of maintaining separate forward and reverse mappings, we use the last seen index of each pattern character and word.

First, we create:

- `lastPattern[26]` to store the last seen index of each lowercase pattern character.
- `lastWord` to store the last seen index of each word.

We initialize the array with `0`. Since we store `i + 1` as the index, `0` represents a character or word that has not been encountered yet.

We traverse the pattern using a single loop and extract the corresponding word using `stringstream`.

If a word is unavailable, we return `false`.

We convert the current pattern character into an array index using:

`int ch = pattern[i] - 'a';`

**Check Last Seen Indices:**

We compare:

`lastPattern[ch] != lastWord[word]`

If the values are different, the pattern character and word have different occurrence histories, so the mapping is inconsistent. We return `false`.

If both values are equal, their previous occurrence patterns match.

**Update Last Seen Indices:**

After the comparison, we update both containers:

- `lastPattern[ch] = i + 1`
- `lastWord[word] = i + 1`

This ensures that both the pattern character and word store the same most recent position.

After processing the entire pattern, we check whether any extra words remain. If they do, we return `false`.

Otherwise, we return `true`.

**Code:**

```cpp
class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int lastPattern[26] = {0};
        unordered_map<string, int> lastWord;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            int ch = pattern[i] - 'a';

            // Check whether both were last seen at the same index
            if (lastPattern[ch] != lastWord[word]) {
                return false;
            }

            // Update last seen indices
            lastPattern[ch] = i + 1;
            lastWord[word] = i + 1;
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
```

**Time Complexity:** `O(n + L)`

**Space Complexity:** `O(u + 1)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">