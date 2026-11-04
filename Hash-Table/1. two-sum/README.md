# 1. Two Sum

**LeetCode Problem:** [Two Sum](https://leetcode.com/problems/two-sum/)  
**Difficulty:** Easy  
**Topics:** Array, Hash Table, Sorting, Two Pointers


Explored multiple approaches, from place-value mapping to greedy solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Brute Force – Pairwise Comparison

**Approach:** Use two nested `for` loops to check every possible pair of elements in the `nums` array.

First, calculate the size of the array and store it in `n`.

Next, use the outer loop to select the first element, `nums[i]`.

For each selected element, use the inner loop to traverse the elements after it, starting from `i + 1`. This ensures that an element is never paired with itself and the same pair is not checked more than once.

For every pair, check whether their sum equals the given `target`.

If `nums[i] + nums[j] == target`, return their indices `{i, j}`.

If no valid pair is found after checking all possible combinations, return an empty vector `{}`.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Select the first element
        for (int i = 0; i < n; i++) {

            // Step 2: Check elements after the first element
            for (int j = i + 1; j < n; j++) {

                // Step 3: Check whether their sum equals target
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        // Step 4: Return an empty vector if no pair is found
        return {};
    }
};
```

**Time Complexity:** `O(n²)` 

**Space Complexity:** `O(1)`

---

## 2. Sorting + Two Pointers

**Approach:** Use a vector of pairs to store each number along with its original index, then sort the vector and apply the two-pointer technique to find the pair whose sum equals the given `target`.

First, create a vector of pairs named `arr`. Store each element of `nums` along with its original index in the form `{number, index}`.

Next, sort `arr` in ascending order based on the numbers. Since each pair stores the original index, we can still return the correct indices after sorting.

Initialize two pointers:

- `left = 0`: Points to the smallest element.
- `right = n - 1`: Points to the largest element.

Now, use a `while` loop while `left < right` and calculate the sum of the two selected numbers.

- If `sum == target`, return their original indices using `arr[left].second` and `arr[right].second`.
- If `sum < target`, increment `left` to select a larger number.
- If `sum > target`, decrement `right` to select a smaller number.

If no valid pair is found, return an empty vector `{}`.

### Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Step 1: Store numbers with their original indices
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort based on numbers
        sort(arr.begin(), arr.end());

        // Step 3: Initialize two pointers
        int left = 0;
        int right = n - 1;

        // Step 4: Find the required pair
        while (left < right) {

            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                return {arr[left].second, arr[right].second};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(n)`

---

## 3. Hash Map – Complement Lookup (Two Pass)

**Approach:** Use an `unordered_map` to store each number along with its index. Then, traverse the array again to find whether the required complement exists in the hash map.

First, create an `unordered_map` named `numMap`, where each number is stored as a key and its corresponding index is stored as the value.

Next, traverse the `nums` array and insert each number and its index into the hash map using `numMap[nums[i]] = i`.

After building the hash map, traverse the array again and calculate the `complement` for each number using `target - nums[i]`.

For every element, check two conditions:

- `numMap.count(complement)`: Checks whether the required complement exists in the hash map.
- `numMap[complement] != i`: Ensures that the complement belongs to a different index and the same element is not used twice.

If both conditions are satisfied, return the current index `i` and the index of the complement stored in `numMap`.

If no valid pair is found, return an empty vector `{}`.

### Code

```cpp id="m8x4pz"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Step 1: Build the hash table
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // Step 2: Find the complement
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];

            // Step 3: Check whether the complement exists
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {};
    }
};
```

**Time Complexity:**  `O(n)`

**Space Complexity:**  `O(n)`

---

## 4. Hash Map – One Pass Complement Lookup

**Approach:** Use an `unordered_map` to store each number along with its index while searching for the required complement in the same traversal.

First, create an `unordered_map` named `mp`, where each number is stored as a key and its corresponding index is stored as the value.

Next, traverse the `nums` array and calculate the `complement` for each element using `target - nums[i]`.

Before inserting the current number into the hash map, check whether its complement already exists using `mp.find(complement) != mp.end()`.

- If the complement exists, return its stored index `mp[complement]` along with the current index `i`.
- If the complement does not exist, insert the current number and its index into the hash map using `mp[nums[i]] = i`.

By checking before inserting, we ensure that the same element is never used twice.

If no valid pair is found after traversing the array, return an empty vector `{}`.

### Code

```cpp id="k9w2bx"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        // Step 1: Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Step 2: Calculate the required complement
            int complement = target - nums[i];

            // Step 3: Check whether the complement exists
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Step 4: Store the current number and its index
            mp[nums[i]] = i;
        }

        return {};
    }
};
```

**Time Complexity:**  `O(n) `

**Space Complexity:**  `O(n)`

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400" />

