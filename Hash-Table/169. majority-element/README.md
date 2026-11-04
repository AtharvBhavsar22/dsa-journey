# 169. Majority Element

**LeetCode Problem:** [Majority Element](https://leetcode.com/problems/majority-element/)  
**Difficulty:** Easy  
**Topics:** Array, Hash Table, Divide and Conquer, Sorting, Counting

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

After counting all occurrences, we check whether `count > n / 2`. If the condition is satisfied, we return `nums[i]` as the majority element.

Otherwise, the outer loop moves to the next element and repeats the process.

**Code:**

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Traverse through each element
        for (int i = 0; i < n; i++) {

            // Step 2: Skip already processed elements
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

            // Step 3: Initialize frequency count
            int count = 1;

            // Step 4: Count remaining occurrences
            for (int j = i + 1; j < n; j++) {

                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Step 5: Check majority condition
            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
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

Next, we check whether `it->second > n / 2`. If the condition is satisfied, we return `it->first` as the majority element.

Since the problem guarantees that a majority element exists, one of the map entries will satisfy this condition.

Finally, we return the majority element.

**Code:**

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Create a frequency map
        unordered_map<int, int> freq;

        // Step 2: Count occurrences
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 3: Find the majority element
        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (it->second > n / 2) {
                return it->first;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** `O(n)` a

**Space Complexity:** `O(m)`

---

## 3. Sorting – Middle Element

**Approach:**

First, we calculate the size of the array and store it in a variable called `n`.

**Sort the Array**

Next, we sort the input array in ascending order using `sort(nums.begin(), nums.end())`.

After sorting, all occurrences of the same element are placed together.

Since the majority element appears more than `n / 2` times, it occupies the middle position of the sorted array.

**Return the Majority Element**

Finally, we return `nums[n / 2]`, which represents the middle element of the sorted array.

Since the problem guarantees that a majority element always exists, we do not need to perform any additional frequency checks.

**Code:**

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Return the middle element
        return nums[n / 2];
    }
};
```

**Time Complexity:** `O(n log n)` 

**Space Complexity:** `O(log n)` 

---

## 4. Divide and Conquer

**Approach:**

First, we create a helper function called `divide()` that takes three parameters: the input array, the left index, and the right index. These indices represent the current range of the array we are processing.

**Base Case**

If `left == right`, it means the current range contains only one element.

Since that element is the majority element of this single-element range, we simply return `nums[left]`.

**Divide the Array**

Next, we calculate the middle index using:

`mid = left + (right - left) / 2`

This divides the current range into two halves:

- Left half: `left` to `mid`
- Right half: `mid + 1` to `right`

We recursively call `divide()` on both halves and store their returned majority candidates in `leftMajority` and `rightMajority`.

**Combine the Results**

Once both recursive calls return, we compare the two candidates.

- If `leftMajority == rightMajority`, both halves return the same candidate. Therefore, we directly return that candidate without counting its occurrences again.
- Otherwise, we need to determine which candidate occurs more frequently in the current range.

**Count Occurrences**

We initialize two variables, `leftCount` and `rightCount`, to zero.

Next, we traverse the current range from `left` to `right` and count the occurrences of both candidates.

- If `nums[i] == leftMajority`, we increment `leftCount`.
- If `nums[i] == rightMajority`, we increment `rightCount`.

After traversing the range, both variables contain the respective frequencies of the two candidates.

**Return the Majority Element**

Finally, we compare both frequencies using the ternary operator.

- If `leftCount > rightCount`, we return `leftMajority`.
- Otherwise, we return `rightMajority`.

This works because the problem guarantees that a majority element always exists, meaning one element appears more than `n / 2` times in the current range.

We repeat this combining process until the recursive calls return the majority element of the entire array.

In `majorityElement()`, we call `divide(nums, 0, n - 1)` to process the complete array and return the final majority element.

**Code:**

```cpp
class Solution {
public:

    // Step 1: Find the majority candidate in a range
    int divide(vector<int>& nums, int left, int right) {

        // Step 2: Base case
        if (left == right) {
            return nums[left];
        }

        // Step 3: Divide the array into two halves
        int mid = left + (right - left) / 2;

        int leftMajority = divide(nums, left, mid);
        int rightMajority = divide(nums, mid + 1, right);

        // Step 4: Check whether both candidates are equal
        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        // Step 5: Count occurrences of both candidates
        int leftCount = 0;
        int rightCount = 0;

        for (int i = left; i <= right; i++) {

            if (nums[i] == leftMajority) {
                leftCount++;
            }

            if (nums[i] == rightMajority) {
                rightCount++;
            }
        }

        // Step 6: Return the candidate with higher frequency
        return (leftCount > rightCount)
            ? leftMajority
            : rightMajority;
    }

    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        return divide(nums, 0, n - 1);
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(log n)`

---

## 5. Boyer-Moore Voting Algorithm

**Approach:**

First, we initialize two variables: `candidate` and `count`.

- `candidate` stores the potential majority element.
- `count` keeps track of the current candidate's votes.

Initially, we set `candidate = 0` and `count = 0`.

**Traverse the Array**

Next, we traverse the array from left to right.

For each element, we follow these conditions:

1. If `count == 0`, we select the current element as the new `candidate`.
2. If `nums[i] == candidate`, it means the current element matches our candidate, so we increment `count`.
3. Otherwise, the current element is different from our candidate, so we decrement `count`.

**Vote Cancellation**

The main idea behind this algorithm is that every occurrence of a different element cancels one vote for the current candidate.

Since the majority element appears more than `n / 2` times, it cannot be completely eliminated through this cancellation process.

Therefore, the majority element remains as the final candidate.

**Return the Majority Element**

After traversing the entire array, we return `candidate`.

Since the problem guarantees that a majority element always exists, there is no need for an additional verification pass.

**Code:**

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Step 1: Initialize candidate and count
        int candidate = 0;
        int count = 0;

        // Step 2: Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Step 3: Select a new candidate if count becomes zero
            if (count == 0) {
                candidate = nums[i];
            }

            // Step 4: Increase or decrease the vote count
            if (nums[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        // Step 5: Return the majority element
        return candidate;
    }
};
```

**Time Complexity:** `O(n)` 

**Space Complexity:** `O(1)` 

---


Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
