# 692. Top K Frequent Words

**LeetCode Problem:** [Top K Frequent Words](https://leetcode.com/problems/top-k-frequent-words/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, String, Trie, Sorting, Heap (Priority Queue), Bucket Sort, Quickselect

Explored multiple approaches, from place-value mapping to greedy solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Hash Map + Sorting

**Approach:**

First, use an `unordered_map` to count the frequency of each word, storing each word as a key and its frequency as the corresponding value.

Initialize a `vector<pair<string, int>>` to store the words along with their frequencies.

Then, traverse the hash map and insert each word-frequency pair into the vector using `push_back()`.

Next, sort the vector using `sort()` with a **lambda function**, which acts as a custom comparator to define the sorting order.

The lambda function compares two pairs (`a` and `b`) using the following conditions:

- If both words have the same frequency (`a.second == b.second`), compare their strings using `a.first < b.first` to arrange them in **lexicographical ascending order** (alphabetical order, where smaller words come first).

- Otherwise, use `a.second > b.second` to arrange words in **descending order of frequency** (higher frequency comes first).

After sorting, initialize an `ans` vector to store the final result.

Traverse the sorted vector and append the first `k` words using `freq[i].first` to `ans`.

Finally, return `ans`.


**Code**

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // Step 2: Store words and frequencies
        vector<pair<string, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Step 3: Sort by frequency and lexicographical order
        sort(freq.begin(), freq.end(),
             [](const pair<string, int>& a, const pair<string, int>& b) {

                 if (a.second == b.second) {
                     return a.first < b.first;
                 }

                 return a.second > b.second;
             });

        // Step 4: Collect the first k words
        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n + m log m)`

**Space Complexity:** `O(m)`


---

## 2. Hash Map + Bucket Sort

**Approach:**

First, use an `unordered_map` to count the frequency of each word, storing each word as a key and its frequency as the corresponding value.

Initialize a 2D vector `freq` of size `words.size() + 1`, where each index represents a frequency and stores the words having that frequency.

We use `words.size() + 1`, Since vector indices start from 0, we need n + 1 buckets to access indices from 0 to n.

Index 0 remains unused, while indices 1 to n represent the possible frequencies.

Then, traverse the hash map and insert each word into its corresponding frequency bucket using `freq[entry.second].push_back(entry.first)`.

Next, initialize an `ans` vector to store the final result.

Traverse the frequency buckets in reverse order, starting from the highest possible frequency down to `1`, so that words with higher frequencies are processed first.

For each bucket, use `sort()` to arrange the words in lexicographical ascending order (alphabetical order), since words with the same frequency must be returned alphabetically.

Then, traverse the sorted bucket and append each word to `ans`.

After inserting each word, check whether `ans.size() == k`. If the required number of words has been collected, return `ans`.

Finally, return `ans` after processing the buckets.

**Code**

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // Step 2: Create buckets based on frequency
        vector<vector<string>> freq(words.size() + 1);

        // Step 3: Place words into their frequency buckets
        for (auto entry : mp) {
            freq[entry.second].push_back(entry.first);
        }

        // Step 4: Collect the k most frequent words
        vector<string> ans;

        for (int i = freq.size() - 1; i >= 1; i--) {

            // Step 5: Sort words alphabetically within each bucket
            sort(freq[i].begin(), freq[i].end());

            for (string word : freq[i]) {
                ans.push_back(word);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n + m log m)`

**Space Complexity:** `O(n + m)`

---

## 3. Hash Map + Repeated Maximum Frequency Selection

**Approach:**

First, use an `unordered_map` to count the frequency of each word, storing each word as a key and its frequency as the corresponding value.

Initialize an `ans` vector to store the `k` most frequent words.

Next, repeat the selection process `k` times using a loop.

Inside each iteration, initialize `maxFreq` to `0` and `maxWord` to an empty string to track the word with the highest frequency.

Then, traverse the hash map using a reference (`auto& entry`) to examine each word-frequency pair without creating unnecessary copies.

For each entry, check the following conditions:

- If its frequency (`entry.second`) is greater than `maxFreq`, update `maxFreq` and `maxWord` with the current entry.
- If both frequencies are equal, compare the words using `entry.first < maxWord` to select the lexicographically smaller word (alphabetically smaller word).

After finding the word with the highest frequency, append `maxWord` to `ans`.

Then, remove the selected word from the hash map using `mp.erase(maxWord)` so that it cannot be selected again in the next iteration.

Repeat this process until `k` words have been selected.

Finally, return `ans`.

**### Code**

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        vector<string> ans;

        // Step 2: Find the maximum frequency k times
        for (int i = 0; i < k; i++) {

            int maxFreq = 0;
            string maxWord = "";

            // Step 3: Find the word with the highest frequency
            for (auto& entry : mp) {
                if (entry.second > maxFreq ||
                    (entry.second == maxFreq && entry.first < maxWord)) {

                    maxFreq = entry.second;
                    maxWord = entry.first;
                }
            }

            // Step 4: Add the word to the answer
            ans.push_back(maxWord);

            // Step 5: Remove it to avoid selecting it again
            mp.erase(maxWord);
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n + k × m)`

**Space Complexity:** `O(m)`

---
## 4. Hash Map + Min-Heap (Priority Queue)

**Approach:**

First, use an `unordered_map` to count the frequency of each word, storing each word as a key and its frequency as the corresponding value.

Next, define a lambda function `cmp` to create a custom comparator for the min-heap.

The comparator uses two conditions:

- If two words have the same frequency (`a.first == b.first`), compare their strings using `a.second < b.second` so that lexicographically larger words get higher priority to be removed first.
- Otherwise, use `a.first > b.first` so that words with lower frequencies get higher priority to be removed first.

Initialize a `priority_queue` using `pair<int, string>` to store frequency-word pairs, `vector<pair<int, string>>` as its underlying container, and `decltype(cmp)` as its custom comparator.

Here, `decltype(cmp)` is a C++ keyword that determines the data type of `cmp`, allowing us to specify the lambda function's type as the comparator. Passing `cmp` to `pq(cmp)` initializes the priority queue with our custom comparator.

Then, traverse the hash map and insert each frequency-word pair into the priority queue using `pq.push()`.

After each insertion, check whether the heap size exceeds `k`. If it does, remove the top element using `pq.pop()` to maintain only the `k` most frequent words.

The comparator gives higher removal priority to words with lower frequencies and, when frequencies are equal, lexicographically larger words. Therefore, the least desirable word stays at the top of the min-heap and gets removed whenever the heap size exceeds `k`.

For example, if `"i"` and `"love"` both have frequency `2`, `"love"` gets higher removal priority because it comes later alphabetically. Therefore, when the heap exceeds size `k`, `"love"` is removed first, allowing `"i"` to remain.

Next, initialize an `ans` vector and extract all words from the priority queue using `pq.top().second`, removing each element using `pq.pop()`.

Since the heap returns the selected words in the opposite order of the required result, use `reverse(ans.begin(), ans.end())` to arrange them correctly. For example, if extraction produces `["love", "i"]`, reversing it gives `["i", "love"]`.

Finally, return `ans`.

**Code**

```cpp
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // Step 2: Create a min-heap based on frequency
        auto cmp = [](const pair<int, string>& a,
                      const pair<int, string>& b) {

            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        };

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        // Step 3: Insert words and frequencies
        for (auto entry : mp) {
            pq.push({entry.second, entry.first});

            // Keep only k elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract the words
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 5: Reverse to get the required order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

**Time Complexity:** `O(n + m log k)`

**Space Complexity:** `O(m + k)`

---

## 05. Hash Map + Quickselect (Divide and Conquer)

**Approach:**

First, use an `unordered_map` to count the frequency of each word. Each word is stored as a key, and its frequency is stored as the corresponding value.

Next, store all unique words and their frequencies in a vector of pairs called `freq`. The word is stored in `.first`, and its frequency is stored in `.second`.

Instead of sorting the entire vector, use Quickselect to find the position of the kth most frequent word.

### Partition Function

The `partition()` function rearranges the elements around a randomly selected pivot.

First, generate a random index between `left` and `right`, then swap that element with the last element of the current range. We use `freq[right]` as the pivot.

Initialize `i = left` and traverse the remaining elements using `j` from `left` to `right - 1`.

Here:

- `j` traverses the elements and compares them with the pivot.
- `i` keeps track of the position where the next preferred word should be placed.

The comparison checks two conditions:

- If a word has a higher frequency than the pivot, it should come before it.
- If both frequencies are equal, the lexicographically smaller word should come first.

Whenever a word satisfies either condition, swap `freq[i]` and `freq[j]`, then increment `i`.

After the loop, swap `freq[i]` with `freq[right]` to place the pivot in its correct position. Finally, return `i`, which represents the pivot's final index.

### Quickselect: Finding the Kth Position

Inside `quickSelect()`, initialize `left` and `right` to represent the current search range.

Call `partition()` to rearrange the elements and obtain the pivot's final position.

Our target index is `k - 1` because vector indexing starts from zero.

Compare `pivotIndex` with the target:

- If `pivotIndex == k - 1`, the first `k` positions contain the required top `k` words, so we stop.
- If `pivotIndex > k - 1`, search the left portion by updating `right = pivotIndex - 1`.
- If `pivotIndex < k - 1`, search the right portion by updating `left = pivotIndex + 1`.

Repeat this process until the required position is found.

### Collecting and Sorting the Answer

Once Quickselect finishes, the first `k` positions of `freq` contain the top `k` words.

Traverse these positions and collect `freq[i].first`, since `.first` stores the actual word.

### Why do we sort again?

#### Understanding Partitioning vs Final Sorting in Quickselect

In our Quickselect approach, we use the same ordering rules in two different places:

1. Inside the `partition()` function.
2. During the final `sort()` operation.

Although both use the same comparison rules, they perform different tasks.

### 1. Ordering During Partitioning

```cpp
if (freq[j].second > pivot.second ||
    (freq[j].second == pivot.second &&
     freq[j].first < pivot.first)) {

    swap(freq[i], freq[j]);
    i++;
}
```

This condition decides whether the current word should be placed before the pivot.

It follows two rules:

- **Higher frequency first:** If the current word has a higher frequency than the pivot, it should come before the pivot.
- **Alphabetical order for equal frequencies:** If both words have the same frequency, the lexicographically smaller word should come first.

For example, consider these two words:

| Word | Frequency |
|---|---:|
| i | 2 |
| love | 2 |

Both words have the same frequency, so we cannot decide their order based on frequency.

We compare their names alphabetically instead.

Since `i` comes before `love`, the condition:

```cpp
freq[j].first < pivot.first
```

evaluates to true when the current word is `"i"` and the pivot is `"love"`.

Therefore, `"i"` is placed before `"love"`.

But the partition function only compares every element with the pivot. It does not compare every element with every other element.

**Important:** Partitioning places elements on the correct side of the pivot according to our ordering rules. However, it does not completely sort all the elements.

### 2. What Does Quickselect Actually Do?

Quickselect uses the partition function to find the position of the kth element.

After each partition:

- Elements that come before the pivot are placed on its left.
- The pivot reaches its correct position.
- Elements that do not come before the pivot are placed on its right.

Quickselect then checks whether the pivot has reached the target index `k - 1`.

If it has, we stop.

At this point, the first `k` positions contain the required top `k` words.

However, **Quickselect guarantees the correct selection, not the complete sorting of the selected elements.**

### 3. Why Do We Need the Final sort() Function?

After Quickselect, we collect the first `k` words:

```cpp
vector<string> ans;

for (int i = 0; i < k; i++) {
    ans.push_back(freq[i].first);
}
```

These are the correct top `k` words, but their internal order is not guaranteed to be completely sorted.

For example, imagine the selected words are:

```cpp
["love", "i"]
```

Both have frequency `2`, so the correct order should be:

```cpp
["i", "love"]
```

We therefore use:

```cpp
sort(ans.begin(), ans.end(),
     [&mp](const string& a, const string& b) {

         if (mp[a] == mp[b]) {
             return a < b;
         }

         return mp[a] > mp[b];
     });
```

This comparator applies the complete ordering to the selected words:

- If frequencies are equal, `a < b` places the alphabetically smaller word first.
- Otherwise, `mp[a] > mp[b]` places the word with the higher frequency first.

The `[&mp]` capture allows the lambda to access the frequency map and retrieve the frequency of each word.

**Code**


```cpp
class Solution {
public:

    // Step 1: Partition the vector around a random pivot
    int partition(vector<pair<string, int>>& freq, int left, int right) {

        int randomIndex = left + rand() % (right - left + 1);

        swap(freq[randomIndex], freq[right]);

        pair<string, int> pivot = freq[right];

        int i = left;

        for (int j = left; j < right; j++) {

            // Higher frequency first.
            // If frequencies are equal, alphabetical order first.
            if (freq[j].second > pivot.second ||
                (freq[j].second == pivot.second &&
                 freq[j].first < pivot.first)) {

                swap(freq[i], freq[j]);
                i++;
            }
        }

        swap(freq[i], freq[right]);

        return i;
    }

    // Step 2: Find the position of the kth most frequent word
    void quickSelect(vector<pair<string, int>>& freq, int k) {

        int left = 0;
        int right = freq.size() - 1;

        while (left <= right) {

            int pivotIndex = partition(freq, left, right);

            if (pivotIndex == k - 1) {
                return;
            }
            else if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            }
            else {
                left = pivotIndex + 1;
            }
        }
    }

    // Step 3: Find the k most frequent words
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (const string& word : words) {
            mp[word]++;
        }

        // Step 2: Store words and their frequencies
        vector<pair<string, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Step 3: Apply Quickselect
        quickSelect(freq, k);

        // Step 4: Collect the first k words
        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        // Step 5: Sort the selected words
        sort(ans.begin(), ans.end(),
             [&mp](const string& a, const string& b) {

                if (mp[a] == mp[b]) {
                    return a < b;
                }

                return mp[a] > mp[b];
             });

        return ans;
    }
```

**Time Complexity:** `O(n + m + k log k)`

**Space Complexity:** `O(m)`

---

## 06. Trie + Min-Heap

**Approach:**

First, create a Trie to store each word character by character. At the ending node of each complete word, maintain its frequency and store the complete word.

Next, use a Min-Heap to maintain the `k` most frequent words while traversing the Trie using DFS.

### 1. TrieNode Structure

Create a `TrieNode` structure containing:

- `children[26]`: Stores pointers to the next character nodes (`a` to `z`).
- `freq`: Stores the frequency of the complete word ending at that node.
- `word`: Stores the complete word when a word ends at that node.

Initialize the frequency to `0`, the word to an empty string, and all child pointers to `nullptr`.

### 2. Min-Heap Comparator

Define a `Compare` structure to customize the ordering of the Min-Heap.

The comparator uses two conditions:

- If frequencies are equal (`a.first == b.first`), use `a.second < b.second` so that the lexicographically larger word gets higher priority for removal.
- Otherwise, use `a.first > b.first` so that the word with the lower frequency gets higher priority for removal.

Therefore, the worst candidate stays at the top of the Min-Heap.

### 3. Insert Function

The `insert()` function inserts each word into the Trie.

- Start from the root node using a pointer called `curr`.
- Traverse each character of the word and calculate its index using `ch - 'a'`.
- If the corresponding child node does not exist, create a new `TrieNode`.
- Move `curr` to the next character node.
- After processing the complete word, increment `curr->freq` and store the word using `curr->word = word`.

If a word appears multiple times, its existing ending node is reached again and its frequency increases.

### 4. DFS Function

The `dfs()` function traverses the Trie and maintains the top `k` frequent words.

First, check whether the current node is `nullptr`. If it is, return.

Next, check whether `node->freq > 0`. This condition identifies a node representing the end of a complete word.

If it is a complete word:

- Push `{node->freq, node->word}` into the Min-Heap.
- Check whether the heap size exceeds `k`.
- If it does, remove the top element using `pq.pop()`.

This ensures that the heap maintains only the best `k` candidates.

After processing the current node, traverse all 26 children. If a child exists, recursively call `dfs()` on that child.

### 5. Delete Trie Function

The `deleteTrie()` function releases the dynamically allocated Trie nodes.

First, check whether the current node is `nullptr`.

Then, recursively delete all its existing child nodes. After deleting the children, delete the current node using `delete node`.

This ensures that the allocated Trie memory is released.

### 6. Main Function

Inside `topKFrequent()`:

1. **Create the Trie:** Allocate a new root node using `new TrieNode()`.
2. **Insert words:** Traverse the input vector and insert every word into the Trie using `insert()`.
3. **Create Min-Heap:** Initialize a priority queue using `P` and the custom `Compare` structure.
4. **Traverse the Trie:** Call `dfs()` to visit complete words and maintain the top `k` candidates in the heap.
5. **Extract words:** Create an `ans` vector and extract words using `pq.top().second`, removing each element with `pq.pop()`.
6. **Reverse the result:** Since the Min-Heap returns words from worst to best, use `reverse(ans.begin(), ans.end())` to obtain the required order.
7. **Free Trie memory:** Call `deleteTrie(root)` to release all allocated Trie nodes.
8. Finally, return `ans`.

### Code

```cpp
class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        int freq;
        string word;

        TrieNode() {
            freq = 0;
            word = "";

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    using P = pair<int, string>;

    // Min-Heap comparator
    struct Compare {
        bool operator()(const P& a, const P& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };

    // Insert words into Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->freq++;
        curr->word = word;
    }

    // DFS traversal and maintain top k words
    void dfs(
        TrieNode* node,
        priority_queue<P, vector<P>, Compare>& pq,
        int k
    ) {
        if (node == nullptr) {
            return;
        }

        // Process a complete word
        if (node->freq > 0) {
            pq.push({node->freq, node->word});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Explore Trie children
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                dfs(node->children[i], pq, k);
            }
        }
    }

    // Delete allocated Trie nodes
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 26; i++) {
            deleteTrie(node->children[i]);
        }

        delete node;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Create Trie
        TrieNode* root = new TrieNode();

        // Step 2: Insert all words
        for (const string& word : words) {
            insert(root, word);
        }

        // Step 3: Create Min-Heap
        priority_queue<P, vector<P>, Compare> pq;

        // Step 4: Traverse Trie and maintain top k
        dfs(root, pq, k);

        // Step 5: Extract words
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 6: Reverse the result
        reverse(ans.begin(), ans.end());

        // Step 7: Free Trie memory
        deleteTrie(root);

        return ans;
    }
};
```

**Time Complexity:** `O(n × L + S + m log k)`

**Space Complexity:** `O(S + W + k)`

---


Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400" />

