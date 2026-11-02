# 49. Group Anagrams

**LeetCode Problem:** [Group Anagrams](https://leetcode.com/problems/group-anagrams/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, String, Sorting

---

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Brute Force – Pairwise Frequency Comparison

**Approach:**

Maintain a `grouped` boolean array to track which strings have already been added to an anagram group. 

Traverse the input array and skip strings that are already grouped. For every ungrouped string, create a new `group` vector, insert the current string, and mark it as grouped.

Use an inner loop to compare the current string with the remaining ungrouped strings. 

First, check whether their lengths match. If they do, use a frequency array to check whether they are anagrams. If all frequencies become zero, add the matching string to the current group and mark it as grouped.

Once all remaining strings have been checked, add the completed group to the final `result` vector. Repeat until all strings have been processed.

Input: `["eat", "tea", "tan"]`

- `"eat"` → Create a new group and mark it grouped.
- `"tea"` → Frequencies match → Add to the current group and mark it grouped.
- `"tan"` → Frequencies differ → Skip it.
- Add `["eat", "tea"]` to the result.
- `"tan"` → Create a separate group and add it to the result.

Output: `[["eat", "tea"], ["tan"]]`

**Code:**

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<bool> grouped(n, false);
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (grouped[i]) {
                continue;
            }

            vector<string> group;
            group.push_back(strs[i]);
            grouped[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (grouped[j]) {
                    continue;
                }

                if (strs[i].length() != strs[j].length()) {
                    continue;
                }

                int freq[26] = {0};

                for (int k = 0; k < strs[i].length(); k++) {
                    freq[strs[i][k] - 'a']++;
                    freq[strs[j][k] - 'a']--;
                }

                bool isAnagram = true;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] != 0) {
                        isAnagram = false;
                        break;
                    }
                }

                if (isAnagram) {
                    group.push_back(strs[j]);
                    grouped[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
```

**Time Complexity:** `O(n² × k)`

**Space Complexity:** `O(n × k) `


---

## 2. Sorting + Hash Map

**Approach:**

Create an `unordered_map` where each key is a sorted version of a string and its value stores all original strings that share that key.

Traverse the input array and copy each string into `sortedStr`. 

Sort the copied string to create a common key for all its anagrams. Use `mp[sortedStr].push_back(strs[i])` to insert the original string into the corresponding group.

After processing all strings, traverse the map and collect each group's vector into the final `result` vector. Return the result.

Input: `["eat", "tea", "tan"]`

- `"eat"` → Sorted key: `"aet"` → `mp["aet"] = ["eat"]`
- `"tea"` → Sorted key: `"aet"` → `mp["aet"] = ["eat", "tea"]`
- `"tan"` → Sorted key: `"ant"` → `mp["ant"] = ["tan"]`

Map after processing:

| Key | Value |
|---|---|
| `"aet"` | `["eat", "tea"]` |
| `"ant"` | `["tan"]` |

Output: `[["eat", "tea"], ["tan"]]`

**Code:**

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            // Copy the current string
            string sortedStr = strs[i];

            // Sort the string to create a common key
            sort(sortedStr.begin(), sortedStr.end());

            // Group the original string using the sorted key
            mp[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>> result;

        // Collect all groups
        for (auto it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
```

**Time Complexity:** `O(n × k log k) `

**Space Complexity:** `O(n × k) `

---

## 3. Pre-Sorting + Group Comparison

**Approach:**

First, create a `sortedStrs` array to store the sorted version of every input string.

Traverse the input array, copy each string into `sortedStrs`, and sort it. **This sorting acts as our anagram-checking logic:** since anagrams contain the same characters, sorting them produces identical strings. We can compare these sorted versions to check whether two original strings are anagrams.

Next, maintain a `grouped` boolean array to track which strings have already been added to a group.

Traverse the array and skip strings that are already grouped. For every ungrouped string, create a new `group`, add its original string, and mark it as grouped.

Use an inner loop to compare its sorted version with the sorted versions of the remaining ungrouped strings. If two sorted strings match, their original strings are anagrams. Add the original string to the current group and mark it as grouped.

Once all matching strings have been found, add the completed group to `result`. Repeat until all strings have been processed.


Input: `strs = ["eat", "tea", "tan"]`

**Pre-sort all strings**

Create `sortedStrs` with the same size as `strs`. Copy each original string and sort its characters.

| Index | Original `strs[i]` | Sorted `sortedStrs[i]` |
|---|---|---|
| 0 | `"eat"` | `"aet"` |
| 1 | `"tea"` | `"aet"` |
| 2 | `"tan"` | `"ant"` |

Since anagrams contain the same characters, their sorted versions will be identical. We use this property to check whether two strings are anagrams.

**Initialize the grouped array**

```cpp
grouped = {false, false, false};
```

Initially, no strings have been added to a group.

**Compare and create groups**

**Iteration 1: `i = 0`**

- `grouped[0]` is `false`, so create a new group.
- Add `"eat"` to the group and mark `grouped[0] = true`.
- Now compare it with the remaining strings.

| `j` | Comparison | Result |
|---|---|---|
| 1 | `"aet" == "aet"` | Match → Add `"tea"` and mark `grouped[1] = true` |
| 2 | `"aet" == "ant"` | No match → Skip `"tan"` |

Add the completed group to `result`.

```cpp
result = {{"eat", "tea"}};
```

**Iteration 2: `i = 1`**

- `grouped[1]` is `true`.
- Skip this iteration because `"tea"` is already included in a group.

**Iteration 3: `i = 2`**

- `grouped[2]` is `false`, so create a new group.
- Add `"tan"` and mark `grouped[2] = true`.
- There are no remaining strings to compare.

Add the completed group to `result`.

```cpp
result = {{"eat", "tea"}, {"tan"}};
```

**Code:**

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<string> sortedStrs(n);

        // Step 1: Store sorted versions
        for (int i = 0; i < n; i++) {
            sortedStrs[i] = strs[i];
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
        }

        vector<bool> grouped(n, false);
        vector<vector<string>> result;

        // Step 2: Compare sorted strings
        for (int i = 0; i < n; i++) {
            if (grouped[i]) {
                continue;
            }

            vector<string> group;
            group.push_back(strs[i]);
            grouped[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (!grouped[j] && sortedStrs[i] == sortedStrs[j]) {
                    group.push_back(strs[j]);
                    grouped[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
```

**Time Complexity:** `O(n × k log k + n² × k) `

**Space Complexity:** `O(n × k)`

---

## 4. Frequency Array + Hash Map

**Approach:**

Create an `unordered_map<string, vector<string>>` to group original strings using a unique frequency-based key.

Traverse the input array and process each string individually. 

For every string, initialize a frequency array of size 26 with all values set to zero. 

Traverse the string and count the occurrences of each character using `freq[ch - 'a']++`. Since the input contains lowercase English letters, `ch - 'a'` maps each character to an index between 0 and 25.

Next, generate a unique key using the frequency array. 

Traverse all 26 positions and append each character's frequency to a string, followed by `"#"` as a separator. This creates a frequency signature representing the characters and their counts.

**This frequency signature acts as our anagram-checking logic:** two strings containing exactly the same characters with the same frequencies will generate identical keys.

Use `mp[key].push_back(strs[i])` to store the original string under its frequency-based key. Finally, traverse the map and collect all groups into the `result` vector.

Input: `strs = ["eat", "tea", "tan"]`

**Step 1: Count character frequencies**

For each string, initialize:

```cpp
int freq[26] = {0};
```

The frequency array represents characters from `'a'` to `'z'`.


For example, when processing `"eat"`:

- `'e'` → `freq[4]++`
- `'a'` → `freq[0]++`
- `'t'` → `freq[19]++`

The same process is repeated for `"tea"` and `"tan"`.

**Generate unique frequency keys**

Traverse all 26 positions of the frequency array:

```cpp
for (int j = 0; j < 26; j++) {
    key += to_string(freq[j]) + "#";
}
```

For `"eat"`, the beginning of the key looks like:

```text
1#0#0#0#1#0#0#...#1#0#...
```

For `"tea"`, the frequency array is identical, so it generates exactly the same key.

For `"tan"`, the frequencies of `'e'` and `'n'` differ, so it generates a different key.

| Original String | Frequency Key (simplified) |
|---|---|
| `"eat"` | `1#0#0#0#1#...#1#...` |
| `"tea"` | `1#0#0#0#1#...#1#...` |
| `"tan"` | `1#0#0#0#0#...#1#...` |

The actual key contains all 26 frequency values.

**Group original strings**

Now execute:

```cpp
mp[key].push_back(strs[i]);
```

- `"eat"` → Generates key K1 → Store under `mp[K1]`.
- `"tea"` → Generates the same key K1 → Add to the existing group.
- `"tan"` → Generates a different key K2 → Create a separate group.

Map after processing:

| Key | Value |
|---|---|
| K1 | `["eat", "tea"]` |
| K2 | `["tan"]` |

**Collect all groups**

Traverse the map:

```cpp
for (auto it = mp.begin(); it != mp.end(); it++) {
    result.push_back(it->second);
}
```

Each `it->second` contains one group of anagrams. Add these groups to the final result.

**Output:**

```cpp
[["eat", "tea"], ["tan"]]
```

**Code:**

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            // Step 1: Count character frequencies
            int freq[26] = {0};

            for (char ch : strs[i]) {
                freq[ch - 'a']++;
            }

            // Step 2: Generate a unique key
            string key = "";

            for (int j = 0; j < 26; j++) {
                key += to_string(freq[j]) + "#";
            }

            // Step 3: Group original strings
            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        // Step 4: Collect all groups
        for (auto it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
```

**Time Complexity:** `O(n × (k + 26))`

**Space Complexity:** `O(n × k)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
