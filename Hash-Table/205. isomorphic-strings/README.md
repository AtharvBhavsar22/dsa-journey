Explored multiple approaches, from comparing character patterns to using hash maps and optimized array mappings.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 01. Brute Force – Pairwise Character Comparison

**Approach:**

First, find the length of the string and use two nested loops to compare every possible pair of characters.

The outer loop selects a character at index `i`, while the inner loop starts from `i + 1` and compares it with every character that comes after it.

For each pair of positions, check whether `s[i]` is equal to `s[j]` and whether `t[i]` is equal to `t[j]`. 

Both comparisons should produce the same result. This means that if two characters are equal in string `s`, their corresponding characters must also be equal in string `t`. Similarly, if they are different in `s`, they must be different in `t`.

The condition `(s[i] == s[j]) != (t[i] == t[j])` checks whether these two comparison results are different. If they are, the character patterns do not match, so return `false`. If every pair satisfies the same equality relationship, return `true`, meaning both strings are isomorphic.

**Code:**

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = s.length();

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if ((s[i] == s[j]) != (t[i] == t[j])) {
                    return false;
                }

            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n²)` — Every pair of positions is compared.

**Space Complexity:** `O(1)` — No additional data structures are used.

---

## 02. Hash Map + Reverse Hash Map

**Approach:**

Use two hash maps to maintain mappings in both directions.

- `mp1` stores the mapping from characters in `s` to characters in `t`.
- `mp2` stores the reverse mapping from characters in `t` to characters in `s`.
- Traverse both strings simultaneously.
- Check whether the current character from `s` already has a mapping. If it does, verify that it maps to the current character in `t`.
- Similarly, check whether the current character from `t` already maps back to the current character in `s`.
- If either mapping conflicts, return `false`.
- Otherwise, store both mappings.

Maintaining mappings in both directions ensures that every character has a unique corresponding character.

**Code:**

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            // Check forward mapping
            if (mp1.find(ch1) != mp1.end()) {
                if (mp1[ch1] != ch2) {
                    return false;
                }
            }

            // Check reverse mapping
            if (mp2.find(ch2) != mp2.end()) {
                if (mp2[ch2] != ch1) {
                    return false;
                }
            }

            // Store both mappings
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};
```

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)` 

---

## 03. Hash Map + Hash Set

**Approach:**

Use one hash map and one hash set to maintain the character mapping and track already-used characters.

- `mp` stores the mapping from characters in `s` to characters in `t`.
- `used` keeps track of characters in `t` that have already been assigned.
- Traverse both strings simultaneously.
- If the current character from `s` already exists in the map, check whether its mapped character matches the current character from `t`.
- Otherwise, check whether the current character from `t` is already present in `used`.
- If it is already used, another character from `s` is trying to map to the same character, so return `false`.
- If it is unused, store the mapping and insert the character into the set.

This ensures that each character in `s` maps consistently and each character in `t` is used by only one character from `s`.

**Code:**

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < s.length(); i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            if (mp.find(ch1) != mp.end()) {

                if (mp[ch1] != ch2) {
                    return false;
                }

            }
            else {

                if (used.find(ch2) != used.end()) {
                    return false;
                }

                mp[ch1] = ch2;
                used.insert(ch2);
            }
        }

        return true;
    }
};
```

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)`

---

## 04. Two Fixed-Size Arrays – Bidirectional Mapping

**Approach:**

Instead of using hash maps, use two fixed-size arrays to store character mappings.

- `mapST` stores mappings from characters in `s` to characters in `t`.
- `mapTS` stores mappings from characters in `t` to characters in `s`.
- Initialize both arrays with `-1`, indicating that no mapping has been assigned yet.
- Traverse both strings simultaneously.
- Convert each character into its ASCII index.
- Check whether the current character already has a mapping. If it does, verify that the mapping matches the current corresponding character.
- Perform the same check in the reverse mapping array.
- If either mapping conflicts, return `false`.
- Otherwise, store both mappings using their ASCII indices.

Since the arrays are initialized with `-1`, we can directly check whether a mapping exists without using `find()`.

**Code:**

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int mapST[128];
        int mapTS[128];

        fill(mapST, mapST + 128, -1);
        fill(mapTS, mapTS + 128, -1);

        for (int i = 0; i < s.length(); i++) {

            int ch1 = s[i];
            int ch2 = t[i];

            if (mapST[ch1] != -1 && mapST[ch1] != ch2) {
                return false;
            }

            if (mapTS[ch2] != -1 && mapTS[ch2] != ch1) {
                return false;
            }

            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }

        return true;
    }
};
```

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
