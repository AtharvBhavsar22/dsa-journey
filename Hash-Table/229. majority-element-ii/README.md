# 229. Majority Element II

**LeetCode Problem:** [Majority Element II](https://leetcode.com/problems/majority-element-ii/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Sorting, Counting

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## 1. Brute Force — Nested Loops

**Approach:**

First, we traverse the array using an outer loop and consider each element as a potential majority element.

Before counting its occurrences, we maintain a boolean variable called `visited`, initially set to `false`, to check whether the current element has already been processed.

We use another loop starting from index `0` up to `i - 1` to check whether the current element has appeared before.

- If `nums[k] == nums[i]`, it means the element has already been processed. We set `visited = true` and break the loop.
- If `visited` is true, we use `continue` to skip the current iteration and move to the next element.

If the element has not been processed before, we initialize `count = 1`, since the current element itself has already been encountered.

Next, we run another loop starting from `i + 1` until the end of the array to count its remaining occurrences.

Whenever `nums[i] == nums[j]`, we increment `count`.

After counting all occurrences, we check whether `count > n / 3`. If the condition is satisfied, we add `nums[i]` to the answer vector using `ans.push_back(nums[i])`.

Otherwise, the outer loop moves to the next element and repeats the process.

Finally, we return `ans`, which contains all elements appearing more than `n / 3` times.

**Code:**

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        // Step 1: Traverse through each element
        for (int i = 0; i < n; i++) {

            // Step 2: Skip elements that have already been processed
            bool visited = false;

            for (int k = 0; k < i; k++) {
                if (nums[k] == nums[i]) {
                    visited = true;
                    break;
                }
            }

            if (visited) {
                continue;
            }

            // Step 3: Initialize count with 1 for the current element
            int count = 1;

            // Step 4: Count occurrences of the current element
            for (int j = i + 1; j < n; j++) {

                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Step 5: Check whether the current element is a majority
            if (count > n / 3) {
                ans.push_back(nums[i]);
            }
        }

        // Step 6: Return all majority elements
        return ans;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## 2. Hash Map — Frequency Counting

**Approach:**

First, we create an `unordered_map<int, int>` called `freq` to store each distinct number along with its frequency.

We traverse the input array using a loop and increment the frequency of each element using `freq[nums[i]]++`.

Here, the number acts as the key, while its frequency is stored as the corresponding value in the map.

Once all frequencies are stored, we traverse the map using an iterator, starting from `freq.begin()` and continuing until `freq.end()`.

For every entry, we use `it->first` to access the number and `it->second` to access its frequency.

Next, we check whether `it->second > n / 3`. If the condition is satisfied, we add `it->first` to the answer vector.

Since there can be at most two elements appearing more than `n / 3` times, the answer vector can contain at most two elements.

Finally, we return `ans`.

**Code:**

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;
        vector<int> ans;

        // Step 1: Count the frequency of each element
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 2: Find elements whose frequency is greater than n/3
        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (it->second > n / 3) {
                ans.push_back(it->first);
            }
        }

        // Step 3: Return all majority elements
        return ans;
    }
};
```

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(n)`

---

## 3. Sorting — Frequency Counting

**Approach:**

First, we sort the input array in ascending order using `sort(nums.begin(), nums.end())`.

After sorting, all occurrences of the same number are placed together.

Next, we initialize `count = 1` to track the frequency of the current element.

We traverse the sorted array starting from index `1` and compare each element with the previous element.

- If `nums[i] == nums[i - 1]`, both elements are equal, so we increment `count`.
- Otherwise, we have encountered a new element.

When a new element is found, we check whether the frequency of the previous element is greater than `n / 3`.

If `count > n / 3`, we add `nums[i - 1]` to the answer vector.

After checking the previous element, we reset `count = 1` because the current element starts a new group.

Once the loop finishes, we perform one final check for the last element's frequency. This is necessary because the last group does not encounter a different element to trigger the condition inside the loop.

If its frequency is greater than `n / 3`, we add `nums[n - 1]` to the answer vector.

Finally, we return `ans`.

**Code:**

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Initialize frequency count
        int count = 1;

        // Step 3: Traverse the sorted array
        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {
                count++;
            }
            else {

                // Step 4: Check frequency of the previous element
                if (count > n / 3) {
                    ans.push_back(nums[i - 1]);
                }

                // Step 5: Reset count for the new element
                count = 1;
            }
        }

        // Step 6: Check the frequency of the last element
        if (count > n / 3) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(log n)` 

---

## 4. Divide and Conquer

**Approach:**

We solve the problem by repeatedly dividing the array into two smaller halves until each range contains only one element.

First, we create a helper function called `divide()` that takes three parameters: the input array, the left index, and the right index. These indices represent the current range of the array we are processing.

Unlike the previous Majority Element problem, this problem can have up to two majority elements. Therefore, our helper function returns a vector containing the possible majority candidates in the current range.

**Base Case**

If `left == right`, the current range contains only one element.

We return `{nums[left]}` because that element appears more than one-third of the elements in this single-element range.

**Divide the Array**

We calculate the middle index using:

`mid = left + (right - left) / 2`

This divides the current range into two halves:

- Left half: `left` to `mid`
- Right half: `mid + 1` to `right`

We recursively call `divide()` on both halves and store their returned candidates in `leftMajority` and `rightMajority`.

**Combine Unique Candidates**

Next, we create a vector called `candidates` to collect the possible majority elements from both halves.

First, we copy all elements from `leftMajority` into `candidates`.

Then, we traverse `rightMajority` and check whether each element already exists in `candidates`.

We use a boolean variable called `exists` to avoid inserting duplicate candidates.

If the candidate is not already present, we add it to the vector.

**Count Occurrences**

After collecting the unique candidates, we create an answer vector called `ans`.

We calculate the size of the current range using:

`n = right - left + 1`

Next, we traverse each candidate and count how many times it appears in the current range.

For every candidate, we initialize `count = 0` and traverse the range from `left` to `right`.

Whenever `nums[i] == candidate`, we increment `count`.

**Check the Majority Condition**

After counting its occurrences, we check whether `count > n / 3`.

If the condition is satisfied, we add that candidate to `ans`.

We repeat this process for all unique candidates.

Finally, we return `ans`, containing the majority elements of the current range.

In `majorityElement()`, we call `divide(nums, 0, n - 1)` to process the entire array.

**Code:**

```cpp
class Solution {
public:

    // Step 1: Find majority candidates in the given range
    vector<int> divide(vector<int>& nums, int left, int right) {

        // Step 2: Base case - only one element remains
        if (left == right) {
            return {nums[left]};
        }

        // Step 3: Divide the array into two halves
        int mid = left + (right - left) / 2;

        vector<int> leftMajority = divide(nums, left, mid);
        vector<int> rightMajority = divide(nums, mid + 1, right);

        // Step 4: Combine unique candidates from both halves
        vector<int> candidates;

        for (int num : leftMajority) {
            candidates.push_back(num);
        }

        for (int num : rightMajority) {
            bool exists = false;

            for (int candidate : candidates) {
                if (candidate == num) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                candidates.push_back(num);
            }
        }

        // Step 5: Count each candidate in the current range
        vector<int> ans;
        int n = right - left + 1;

        for (int candidate : candidates) {
            int count = 0;

            for (int i = left; i <= right; i++) {
                if (nums[i] == candidate) {
                    count++;
                }
            }

            // Step 6: Keep candidates appearing more than n / 3 times
            if (count > n / 3) {
                ans.push_back(candidate);
            }
        }

        return ans;
    }

    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        return divide(nums, 0, n - 1);
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(log n)` 

---

## 5. Boyer-Moore Voting Algorithm — Extended Version

**Approach:**

For this problem, we use an extended version of the Boyer-Moore Voting Algorithm.

Since we are looking for elements appearing more than `n / 3` times, there can be at most **two majority elements**.

Therefore, instead of maintaining one candidate and one count, we maintain two candidates and their corresponding counts.

**Initialize Candidates and Counts**

First, we initialize four variables:

- `candidate1` and `candidate2` store the two potential majority elements.
- `count1` and `count2` keep track of their respective votes.

**Find Two Potential Candidates**

We traverse the array and compare each element with both candidates.

We handle the conditions in the following order:

1. If `nums[i] == candidate1`, increment `count1`.
2. Otherwise, if `nums[i] == candidate2`, increment `count2`.
3. Otherwise, if `count1 == 0`, select the current element as `candidate1` and set `count1 = 1`.
4. Otherwise, if `count2 == 0`, select the current element as `candidate2` and set `count2 = 1`.
5. If none of these conditions is satisfied, decrement both `count1` and `count2`.

The last condition represents cancellation: one occurrence of the current element cancels one vote from each candidate.

By repeatedly cancelling groups of three different elements, we eliminate elements that cannot be majority candidates.

**Verify the Candidates**

The first traversal only identifies potential candidates. It does not guarantee that both candidates actually appear more than `n / 3` times.

Therefore, we reset `count1` and `count2` to zero.

Next, we traverse the array again and count the actual occurrences of both candidates.

- If `num == candidate1`, increment `count1`.
- Otherwise, if `num == candidate2`, increment `count2`.

**Check the Majority Condition**

Finally, we create an answer vector called `ans`.

We check both candidates independently:

- If `count1 > n / 3`, add `candidate1` to `ans`.
- If `count2 > n / 3`, add `candidate2` to `ans`.

Since the problem allows at most two majority elements, these checks are sufficient.

Finally, we return `ans`.

**Code:**

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Step 1: Initialize two candidates and their counts
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Step 2: Find two potential majority candidates
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 3: Reset counts to verify actual frequencies
        count1 = 0;
        count2 = 0;

        // Step 4: Count the actual occurrences of both candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
        }

        // Step 5: Store candidates appearing more than n / 3 times
        vector<int> ans;
        int n = nums.size();

        if (count1 > n / 3) {
            ans.push_back(candidate1);
        }

        if (count2 > n / 3) {
            ans.push_back(candidate2);
        }

        // Step 6: Return the majority elements
        return ans;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
