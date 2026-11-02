# 347. Top K Frequent Elements

**LeetCode Problem:** [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Divide and Conquer, Sorting, Heap, Bucket Sort, Quickselect

---
Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---
## 01. Hash Map + Sorting

**Approach:**

Create an `unordered_map<int, int>` to store each number and its frequency.

Traverse the input array and count how many times each number occurs using `mp[num]++`.

Next, create a `vector<pair<int, int>>` to store each distinct number along with its frequency. 

Traverse the map and insert each entry into the vector using `{entry.first, entry.second}`, where `first` represents the number and `second` represents its frequency.

Once all entries are stored, sort the vector in descending order based on frequency using a custom lambda comparator. 

The comparator compares the frequencies of two pairs using `a.second > b.second`, placing the pair with the higher frequency before the pair with the lower frequency.

Finally, create an answer vector and traverse the first `k` positions of the sorted vector. Extract the number from each pair using `freq[i].first` and add it to the answer.

Return the answer containing the `k` most frequent elements.

**Input:** `nums = [1, 1, 1, 2, 2, 3], k = 2`

**Count frequencies**

Initialize an unordered map:

```cpp
unordered_map<int, int> mp;
```

Traverse the input array and update the frequency of each number:

```cpp
for (int num : nums) {
    mp[num]++;
}
```

The map stores each distinct number as a key and its frequency as the corresponding value.

| Number (Key) | Frequency (Value) |
|---|---:|
| 1 | 3 |
| 2 | 2 |
| 3 | 1 |

**Store numbers and frequencies**

Create a vector of pairs:

```cpp
vector<pair<int, int>> freq;
```

Each pair stores a number and its frequency in the format `{number, frequency}`.

Traverse the map:

```cpp
for (auto entry : mp) {
    freq.push_back({entry.first, entry.second});
}
```

- `entry.first` accesses the number (key).
- `entry.second` accesses its frequency (value).
- `push_back()` inserts the pair into the vector.

**Vector after processing:**

```cpp
freq = {
    {1, 3},
    {2, 2},
    {3, 1}
};
```

The order may differ because `unordered_map` does not maintain a sorted order.

**Sort by frequency in descending order**

Use `sort()` with a custom lambda comparator:

```cpp
sort(freq.begin(), freq.end(),
     [](pair<int, int>& a, pair<int, int>& b) {
         return a.second > b.second;
     });
```

- `freq.begin()` points to the first element.
- `freq.end()` points just past the last element.
- `a` and `b` represent the two pairs being compared.
- `a.second` accesses the frequency of pair `a`.
- `b.second` accesses the frequency of pair `b`.
- `a.second > b.second` places the pair with the higher frequency before the pair with the lower frequency.

**Example comparison:**

```cpp
a = {1, 3};
b = {2, 2};

return a.second > b.second;

// 3 > 2 → true
```

Since the first pair has a higher frequency, it should come before the second pair.

**Before sorting:**

```cpp
{{3, 1}, {1, 3}, {2, 2}}
```

**After sorting:**

```cpp
{{1, 3}, {2, 2}, {3, 1}}
```

The vector is now arranged from highest frequency to lowest frequency.

**Step 4: Collect the first k numbers**

Initialize the answer vector:

```cpp
vector<int> ans;
```

Traverse only the first `k` positions:

```cpp
for (int i = 0; i < k; i++) {
    ans.push_back(freq[i].first);
}
```

- `i = 0` starts from the first position.
- `i < k` ensures that only the first `k` elements are selected.
- `freq[i].first` extracts the actual number from the pair, ignoring its frequency.
- `ans.push_back()` adds that number to the answer.

**Dry Run:**

Given:

```cpp
freq = {
    {1, 3},
    {2, 2},
    {3, 1}
};

k = 2;
```

| Iteration | `i` | `freq[i]` | `freq[i].first` | `ans` |
|---|---:|---|---:|---|
| 1 | 0 | `{1, 3}` | 1 | `{1}` |
| 2 | 1 | `{2, 2}` | 2 | `{1, 2}` |

After collecting two elements, the loop stops.

**Output:**

```cpp
[1, 2]
```

The two most frequent numbers are `1` and `2`.

**Code:**

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Store numbers and frequencies
        vector<pair<int, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Step 3: Sort by frequency in descending order
        sort(freq.begin(), freq.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.second > b.second;
             });

        // Step 4: Collect the first k numbers
        vector<int> ans;

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

## 02. Hash Map + Bucket Sort

**Approach**

First, we create an `unordered_map` to store each unique number and its frequency. We traverse the input array and increment the count of each number in the map.

Next, we create a 2D vector called `freq` of size `nums.size() + 1`. 

We use this size because the maximum possible frequency of a number can be equal to the total number of elements in the array. Each index of this vector represents a frequency, and each bucket stores the numbers having that frequency.

Now, we traverse the map and place each number into its corresponding frequency bucket. 

We use `entry.second` as the index because it represents the frequency, and `entry.first` as the number we want to insert. For example, if a number appears 3 times, we insert it into `freq[3]`.

After filling the buckets, we create an empty vector called `ans` to store our result.

Finally, we run a loop from the last bucket towards the first bucket. Since the bucket indices represent frequencies, starting from the last index allows us to process the numbers with the highest frequencies first. Whenever we find a number in a bucket, we add it to `ans`.

We continue this process until `ans.size() == k`, which means we have collected exactly `k` numbers with the highest frequencies. We then return the answer.

### Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Create buckets based on frequency
        vector<vector<int>> freq(nums.size() + 1);

        // Step 3: Place numbers into their frequency buckets
        for (auto entry : mp) {
            freq[entry.second].push_back(entry.first);
        }

        // Step 4: Collect the k most frequent numbers
        vector<int> ans;

        for (int i = freq.size() - 1; i >= 1; i--) {

            for (int num : freq[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
```


**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(n + m)` 

---

## 03. Hash Map + Repeated Maximum Search

**Approach**

First, we create an `unordered_map` to store each unique number and its frequency. We traverse the input array and increment the count of each number in the map.

Next, we create an empty vector called `ans` to store our result.

We then run a loop `k` times because we need to find exactly `k` numbers with the highest frequencies.

Inside the loop, we declare two variables: `maxFreq` and `maxNum`.

We initialize both to `0`. 

`maxFreq` stores the highest frequency found so far, while `maxNum` stores the number having that frequency.

Now, we traverse the entire map and compare each number's frequency with `maxFreq`. If `entry.second` is greater than `maxFreq`, we update `maxFreq` with that frequency and `maxNum` with the corresponding number (`entry.first`).

After checking the map, `maxNum` contains the number with the highest frequency among the remaining elements. We add this number to our answer vector.

We then remove `maxNum` from the map using `mp.erase(maxNum)`. This is important because we have already selected that number, and we don't want to select it again in the next iteration.

The loop repeats until we have selected `k` numbers. In every iteration, we find the highest frequency among the remaining numbers, add its corresponding number to the answer, and remove it from the map.

Finally, we return the answer containing the `k` most frequent numbers.

### Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<int> ans;

        // Step 2: Find the maximum frequency k times
        for (int i = 0; i < k; i++) {

            int maxFreq = 0;
            int maxNum = 0;

            // Step 3: Find the number with the highest frequency
            for (auto& entry : mp) {
                if (entry.second > maxFreq) {
                    maxFreq = entry.second;
                    maxNum = entry.first;
                }
            }

            // Step 4: Add the number to the answer
            ans.push_back(maxNum);

            // Step 5: Remove it to avoid selecting it again
            mp.erase(maxNum);
        }

        return ans;
    }
};
```


**Time Complexity:** `O(n + km)`

**Space Complexity:** `O(m) `

---

## 04. Hash Map + Min-Heap

**Approach:**

First, we create an `unordered_map` to count the frequency of each number in the input array. Each key represents a unique number, and its value represents how many times that number appears.

Next, we create a **min-heap** using `priority_queue`. We use the following structure:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Here, we have three important components:

- **`pair<int, int>`:** Each heap element is a pair containing two integers: the frequency and the actual number. We store the frequency first and the number second.
- **`vector<pair<int, int>>`:** This is the underlying container used to store the pairs inside the heap.
- **`greater<pair<int, int>>`:** This is the comparator that makes the priority queue behave like a min-heap. It keeps the smallest pair at the top.

Now, we traverse the frequency map and insert each number and its frequency into the heap using `pq.push({entry.second, entry.first})`.

Since we use `greater`, the pair with the smallest frequency stays at the top of the heap.

After every insertion, we check whether the heap size is greater than `k`. If it is, we remove the top element using `pq.pop()`. This removes the number with the smallest frequency.

By doing this, we maintain a heap containing at most `k` elements. Whenever a number with a higher frequency enters the heap and its size exceeds `k`, the smallest-frequency element gets removed.

After processing the entire map, the heap contains the `k` numbers with the highest frequencies.

Finally, we create an answer vector and extract the numbers from the heap using `pq.top().second`. We use `.second` because the second value in each pair represents the actual number, while `.first` represents its frequency.

We keep extracting elements until the heap becomes empty and return the answer.

### Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        // Step 2: Create a min-heap based on frequency
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Step 3: Insert numbers and frequencies
        for (auto entry : mp) {
            pq.push({entry.second, entry.first});

            // Keep only k elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract the numbers
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n + m log k)`

**Space Complexity:** `O(m + k)`

---

## 05. Hash Map + Quickselect (Divide and Conquer)

**Approach:** ### Approach: Hash Map + Quickselect

First, we create an `unordered_map` to count the frequency of each number in the input array. Each key represents a unique number, and its value represents how many times that number appears.

Next, we create a vector of pairs called `freq` to store each number along with its frequency. We store the number in `.first` and its frequency in `.second`.

Now, we apply Quickselect to find the position of the kth most frequent element. We pass the frequency vector and `k` to the `quickSelect()` function.

### Quickselect

Inside `quickSelect()`, we initialize two pointers:

- `left` points to the beginning of the vector.
- `right` points to the end of the vector.

Our goal is to arrange the vector so that the first `k` positions contain the `k` most frequent elements. For this, we use the `partition()` function.

### Partition Function

The `partition()` function rearranges the elements around a randomly selected pivot.

First, we generate a random index between `left` and `right` and select that element as our pivot. We then swap it with the last element so that we can easily perform the partition.

We use `freq[right].second` as the pivot because `.second` stores the frequency of each number.

Next, we initialize `i = left` and run another loop using `j` from `left` to `right - 1`.

Here:
- `j` traverses the elements and checks their frequencies against the pivot.
- `i` keeps track of the position where the next element with a higher frequency should be placed.

Whenever `freq[j].second > pivot`, we swap `freq[i]` and `freq[j]`, then increment `i`.

This ensures that all elements having a frequency greater than the pivot are moved towards the left side.

After the loop finishes, we swap `freq[i]` with `freq[right]` to place the pivot in its correct position.

The partition is now complete:
- Elements with higher frequencies are on the left.
- The pivot is at its correct position.
- Elements with lower or equal frequencies are on the right.

Finally, we return `i`, which represents the pivot's final index.

### Quickselect: Finding the Kth Position

Back inside `quickSelect()`, we receive the `pivotIndex` returned by `partition()`.

Our target index is `k - 1` because vector indices start from `0`.

We compare the pivot index with this target:

- If `pivotIndex == k - 1`, we have found the correct position. The first `k` elements contain the `k` most frequent numbers, so we stop.
- If `pivotIndex > k - 1`, the pivot is too far to the right. We continue searching in the left portion by updating `right = pivotIndex - 1`.
- If `pivotIndex < k - 1`, the pivot is too far to the left. We continue searching in the right portion by updating `left = pivotIndex + 1`.

We repeat this process until the pivot reaches the target index.

### Collecting the Answer

Once Quickselect finishes, the first `k` positions of the frequency vector contain the `k` most frequent numbers.

We traverse only these first `k` positions and collect `freq[i].first` because `.first` stores the actual number.

Finally, we return the answer vector.

**Important:** Quickselect does not completely sort the vector. It only ensures that the first `k` positions contain the `k` most frequent elements. Their internal order is not guaranteed.


### Code

```cpp
class Solution {
public:

    // Step 1: Partition the vector around a random pivot
    int partition(vector<pair<int, int>>& freq, int left, int right) {

        int randomIndex = left + rand() % (right - left + 1);

        swap(freq[randomIndex], freq[right]);

        int pivot = freq[right].second;

        int i = left;

        for (int j = left; j < right; j++) {

            if (freq[j].second > pivot) {
                swap(freq[i], freq[j]);
                i++;
            }
        }

        swap(freq[i], freq[right]);

        return i;
    }

    // Step 2: Find the position of the kth most frequent element
    void quickSelect(vector<pair<int, int>>& freq, int k) {

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

    // Step 3: Find the k most frequent elements
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count frequencies
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        // Store numbers and their frequencies
        vector<pair<int, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Apply Quickselect
        quickSelect(freq, k);

        // Collect the first k elements
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
```


**Time Complexity:** `O(n + m)`

**Space Complexity:** `O(m) `

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">

