Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!


## 1. Brute Force — Subarray Creation + Accumulate

**Approach:**


First, we take `n` to store the size of the array and initialize `minLen = n + 1`. We use `n + 1` because the maximum possible length of a subarray is `n`. 

Therefore, if `minLen` remains `n + 1`, it means no valid subarray has been found.

Then, we initialize `i = 0` and use a `while` loop that runs until `i < n`. Here, `i` represents the starting index of the current subarray.

Inside the `while` loop, we use another `for` loop with `j`, starting from `i` and continuing until `j < n`. Here, `j` represents the ending index of the current subarray.

For every starting index `i`, the inner loop generates subarrays by moving `j` forward. This means we check every possible ending index for the current starting index.

Inside the inner loop, we create a temporary vector called `subarray` using:

```cpp
vector<int> subarray(
    nums.begin() + i,
    nums.begin() + j + 1
);
```

Here, `nums.begin()` represents the iterator pointing to the beginning of the original vector.

- `nums.begin() + i` represents the starting position of the subarray. It starts copying elements from index `i`.
- `nums.begin() + j + 1` represents the ending position of the range. It points to the position immediately after index `j`.

In C++, the range used by the vector constructor includes the starting iterator but excludes the ending iterator.

Therefore, `nums.begin() + j + 1` allows us to include the element at index `j` in the subarray.

For example, if:

```cpp
nums = {2, 3, 1, 2, 4, 3};

i = 1;
j = 3;
```

The subarray becomes:

```cpp
{3, 1, 2}
```

Here, the subarray starts from index `1` and ends at index `3`. The original `nums` vector is not modified. We are creating a separate temporary vector containing the selected elements.

After creating the subarray, we calculate its sum using `accumulate()`:

```cpp
int sum = accumulate(
    subarray.begin(),
    subarray.end(),
    0
);
```

Here, `subarray.begin()` represents the beginning of the temporary subarray, and `subarray.end()` represents the position immediately after its last element.

The third argument, `0`, is the initial value used for calculating the sum.

Therefore, `accumulate()` adds all the elements from the beginning of the subarray up to its ending position and stores the calculated sum in `sum`.

For example:

```cpp
subarray = {3, 1, 2};

sum = 3 + 1 + 2;

sum = 6;
```

Then, we check whether `sum >= target`.

If the sum reaches or exceeds the target, we calculate the length of the current subarray using:

```cpp
int len = j - i + 1;
```

Here, `j - i + 1` gives the number of elements between the starting index `i` and ending index `j`, including both positions.

For example:

```cpp
i = 1;
j = 3;

len = 3 - 1 + 1;

len = 3;
```

After calculating the length, we compare it with `minLen`.

If `len < minLen`, we update `minLen` with the current subarray length because we have found a smaller valid subarray.

After checking the current subarray, the inner `for` loop increments `j` and creates the next subarray using the same starting index `i`.

For example, when `i = 0`, the inner loop generates:

```cpp
{2}
{2, 3}
{2, 3, 1}
{2, 3, 1, 2}
{2, 3, 1, 2, 4}
{2, 3, 1, 2, 4, 3}
```

Once the inner loop finishes, we increment `i` by 1.

This moves the starting index forward, and the inner loop starts again from the new starting index.

The process continues until every possible starting index and ending index has been checked.

Finally, if `minLen` remains equal to `n + 1`, it means no valid subarray was found, so we return `0`.

Otherwise, we return `minLen`, which stores the minimum length among all valid subarrays.

---

### Why This Approach Exceeds the Time Limit

In this approach, we generate every possible subarray using two loops.

For an array of size `n`, the total number of possible contiguous subarrays is:

n(n + 1) / 2

Therefore, generating all possible subarrays takes `O(n²)` time.

However, for every subarray, we create a separate temporary vector and calculate its sum using `accumulate()`.

The creation of the temporary vector requires copying the elements of the current subarray, and `accumulate()` traverses those elements again to calculate their sum.

In the worst case, a subarray can contain `n` elements.

Therefore, creating the subarray and calculating its sum can take `O(n)` time for each generated subarray.

Since we generate `O(n²)` subarrays and perform an `O(n)` operation for each one, the overall time complexity becomes: `O(n³)` & `O(n)`

**Code**

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int minLen = n + 1;

        int i = 0;

        while (i < n) {

            for (int j = i; j < n; j++) {

                // Create the current subarray
                vector<int> subarray(
                    nums.begin() + i,
                    nums.begin() + j + 1
                );

                // Calculate the sum of the subarray
                int sum = accumulate(
                    subarray.begin(),
                    subarray.end(),
                    0
                );

                // Check whether the sum reaches target
                if (sum >= target) {

                    int len = j - i + 1;

                    // Update minimum length
                    if (len < minLen) {
                        minLen = len;
                    }
                }
            }

            // Move the starting index forward
            i++;
        }

        // No valid subarray found
        if (minLen == n + 1) {
            return 0;
        }

        return minLen;
    }
};
```

**Time Complexity:** `O(n³)`

**Space Complexity:** `O(n)`


---

## 2. Brute Force — Prefix Sum

**Approach:**



First, we take `n` to store the size of the array and create a prefix sum vector called `prefix` of size `n + 1`, initialized with `0`.

We use `n + 1` because the prefix sum array stores the cumulative sum of elements, along with an extra `0` at the beginning. This extra element helps us calculate the sum of any subarray using the prefix sum array.

Then, we run a `for` loop from `i = 0` until `i < n` to build the prefix sum array.

Inside the loop, we calculate the cumulative sum using:

```
prefix[i + 1] = prefix[i] + nums[i];
```

Here:

- `prefix[i]` represents the sum of all elements before the current index `i`.
- `nums[i]` represents the current element of the original array.
- `prefix[i + 1]` stores the cumulative sum including the current element.

For example, if:

```
nums = {2, 3, 1, 2, 4, 3};
```

The prefix sum array becomes:

```
prefix = {0, 2, 5, 6, 8, 12, 15};
```

Here, `prefix[3]` stores the sum of elements from index `0` to index `2`.

```
prefix[3] = 2 + 3 + 1;

prefix[3] = 6;
```

After building the prefix sum array, we initialize `minLen = n + 1`.

We use `n + 1` because the maximum possible length of a subarray is `n`. Therefore, if `minLen` remains `n + 1`, it means no valid subarray has been found.

Then, we use two `for` loops to generate every possible subarray.

The outer loop starts with `i = 0` and continues until `i < n`. Here, `i` represents the starting index of the current subarray.

Inside the outer loop, we use another `for` loop with `j`, starting from `i + 1` and continuing until `j <= n`.

Here, `j` represents the ending position of the subarray in the prefix sum array.

Since the prefix sum array contains an extra `0` at the beginning, we start `j` from `i + 1` to generate subarrays containing at least one element.

For every starting index `i`, the inner loop moves `j` forward and generates every possible ending position.

Inside the inner loop, we calculate the sum of the current subarray using:

```
int sum = prefix[j] - prefix[i];
```

Here:

- `prefix[j]` represents the cumulative sum up to the ending position of the subarray.
- `prefix[i]` represents the cumulative sum of elements before the starting index of the subarray.

By subtracting `prefix[i]` from `prefix[j]`, we remove the sum of elements that are present before the current subarray.

Therefore, we get the sum of only the elements present between the starting index `i` and the ending index `j - 1`.

For example:

```
nums = {2, 3, 1, 2, 4, 3};

i = 1;
j = 4;
```

The corresponding prefix sum values are:

```
prefix[4] = 8;
prefix[1] = 2;
```

Therefore:

```
sum = prefix[4] - prefix[1];

sum = 8 - 2;

sum = 6;
```

The current subarray is:

```
{3, 1, 2}
```

Here, we calculate its sum directly using the prefix sum array without creating a separate temporary vector or traversing the elements again.

After calculating the sum, we check whether:

```
sum >= target;
```

If the sum reaches or exceeds the target, we calculate the length of the current subarray using:

```
int len = j - i;
```

Here, `j - i` gives the number of elements present between the starting index `i` and the ending position `j` in the prefix sum array.

For example:

```
i = 1;
j = 4;

len = 4 - 1;

len = 3;
```

After calculating the length, we compare it with `minLen`.

If `len < minLen`, we update `minLen` with the current subarray length because we have found a smaller valid subarray.

After checking the current subarray, the inner `for` loop increments `j` and calculates the sum of the next subarray using the same starting index `i`.

For example, when `i = 0`, the inner loop generates:

```
{2}
{2, 3}
{2, 3, 1}
{2, 3, 1, 2}
{2, 3, 1, 2, 4}
{2, 3, 1, 2, 4, 3}
```

Once the inner loop finishes, the outer loop increments `i` by 1.

This moves the starting index forward, and the inner loop starts again from the new starting index.

The process continues until every possible starting index and ending index has been checked.

Finally, if `minLen` remains equal to `n + 1`, it means no valid subarray was found, so we return `0`.

Otherwise, we return `minLen`, which stores the minimum length among all valid subarrays.

---

### Why This Approach Improves Upon the Previous Brute Force Approach

In the previous approach, we created a separate temporary vector for every subarray and calculated its sum using `accumulate()`.

This required copying the elements and traversing them again to calculate the sum.

In this approach, we first build the prefix sum array in one traversal.

After that, we calculate the sum of any subarray using:

```
prefix[j] - prefix[i];
```

This allows us to calculate each subarray sum in `O(1)` time without creating a temporary vector or traversing its elements again.

However, we still generate every possible subarray using two loops.

Therefore, the total number of subarrays is:

```
n(n + 1) / 2
```

Generating all subarrays takes `O(n²)` time, and calculating each subarray sum takes `O(1)` time.

Building the prefix sum array takes `O(n)`, and generating all subarrays takes `O(n²)`.


The prefix sum array stores `n + 1` elements.

Therefore, this approach improves the previous brute force approach from `O(n³)` time to `O(n²)` time by avoiding repeated subarray creation and sum calculation.

**Code**

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        // Step 1: Build Prefix Sum
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minLen = n + 1;

        // Step 2: Generate all subarrays
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j <= n; j++) {

                // Step 3: Calculate subarray sum
                int sum = prefix[j] - prefix[i];

                // Step 4: Check target
                if (sum >= target) {

                    int len = j - i;

                    minLen = min(minLen, len);
                }
            }
        }

        // Step 5: Return answer
        return minLen == n + 1 ? 0 : minLen;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(n)`

---

### 3. Binary Search on Subarray Length + Sliding Window

**Approach:**

First, initialize `low = 1` and `high = n` to represent the minimum and maximum possible subarray lengths.

Then, calculate `mid` using `(low + high) / 2` to determine the current subarray length being checked.

Build the first window of size `mid` and calculate its sum.

If the sum reaches the target, the length is possible. Otherwise, slide the fixed-size window across the array by adding the next element and subtracting the leftmost element.

If a valid window is found, store `mid` and search for a smaller length by updating `high = mid - 1`.

If no valid window is found, search for a larger length by updating `low = mid + 1`.

Since all array elements are positive, if a particular length is possible, every larger length is also possible.

Therefore, binary search is applied to find the minimum possible subarray length.

**Code**

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 1;
        int high = n;

        int minLen = 0;

        // Binary Search on subarray length
        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = 0;
            bool found = false;

            // Build first window of size mid
            for (int i = 0; i < mid; i++) {
                sum += nums[i];
            }

            if (sum >= target) {
                found = true;
            }

            // Slide fixed-size window
            for (int i = mid; i < n && !found; i++) {

                sum += nums[i];
                sum -= nums[i - mid];

                if (sum >= target) {
                    found = true;
                }
            }

            // Check whether this length is possible
            if (found) {

                minLen = mid;

                // Try smaller length
                high = mid - 1;

            } else {

                // Need a larger length
                low = mid + 1;
            }
        }

        return minLen;
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(1)`

---

### 4. Prefix Sum + Binary Search (`lower_bound`)

**Approach:**

First, take `n` to store the size of the array and create a prefix sum vector called `prefix` of size `n + 1`, initialized with `0`.

Then, run a `for` loop to build the prefix sum array.

Inside the loop, calculate the cumulative sum using:

```cpp
prefix[i + 1] = prefix[i] + nums[i];
```

Here, `prefix[i]` represents the sum of elements before the current index `i`, and `nums[i]` represents the current element.

Therefore, `prefix[i + 1]` stores the cumulative sum including the current element.

For example:

```cpp
nums = {2, 3, 1, 2, 4, 3};

prefix = {0, 2, 5, 6, 8, 12, 15};
```

Since all array elements are positive, the prefix sum array is sorted in increasing order.

After building the prefix sum array, initialize `minLen = n + 1`.

We use `n + 1` because the maximum possible length of a subarray is `n`. Therefore, if `minLen` remains `n + 1`, it means no valid subarray has been found.

Then, run a `for` loop from `i = 0` until `i < n`.

Here, `i` represents the starting index of the current subarray.

Inside the loop, calculate the required prefix sum using:

```cpp
int required = prefix[i] + target;
```

Here, `prefix[i]` represents the sum of elements before the starting index `i`.

By adding `target` to `prefix[i]`, we get the minimum prefix sum value required to make the current subarray sum reach the target.

For example:

```cpp
i = 1;
target = 7;

prefix[i] = 2;

required = 2 + 7;

required = 9;
```

Now, use `lower_bound()` to find the first prefix sum that is greater than or equal to the required value:

```cpp
auto it = lower_bound(
    prefix.begin() + i + 1,
    prefix.end(),
    required
);
```

Here:

- `prefix.begin() + i + 1` represents the starting position of the search.
- `prefix.end()` represents the ending position of the search.
- `required` represents the minimum prefix sum value we need to find.

We start searching from `i + 1` because the ending position of the subarray must come after its starting index.

`lower_bound()` returns an iterator pointing to the first element that is greater than or equal to `required`.

Since the prefix sum array is sorted, binary search can be used to find this position efficiently.

For example:

```cpp
prefix = {0, 2, 5, 6, 8, 12, 15};

i = 1;

required = 9;
```

The first prefix sum greater than or equal to `9` is:

```cpp
prefix[5] = 12;
```

Therefore, `lower_bound()` returns an iterator pointing to `prefix[5]`.

After finding the iterator, calculate the ending index using:

```cpp
int j = it - prefix.begin();
```

Here, subtracting `prefix.begin()` from the iterator gives the index of the prefix sum found by `lower_bound()`.

Then, calculate the current subarray length using:

```cpp
int len = j - i;
```

Here, `j - i` gives the number of elements between the starting index `i` and the ending position `j` in the prefix sum array.

If `lower_bound()` finds a valid prefix sum, calculate the subarray length and update `minLen` whenever a smaller valid length is found.

Continue the outer loop by moving `i` forward to check the next starting index.

For every starting index, `lower_bound()` searches for the smallest ending position that satisfies the target sum.

Finally, if `minLen` remains equal to `n + 1`, it means no valid subarray was found, so return `0`.

Otherwise, return `minLen`, which stores the minimum length among all valid subarrays.

---

### Why This Approach Is Efficient

In this approach, we first build the prefix sum array in `O(n)` time.

Since all array elements are positive, the prefix sum array is sorted.

For every starting index `i`, we use `lower_bound()` to find the smallest ending position that satisfies the target sum.

Binary search takes `O(log n)` time for each starting index.

Since we perform binary search for every index, the total time complexity becomes:

**Code**

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minLen = n + 1;

        for (int i = 0; i < n; i++) {
            long long required = prefix[i] + target;

            auto it = lower_bound(
                prefix.begin() + i + 1,
                prefix.end(),
                required
            );

            if (it != prefix.end()) {
                int j = it - prefix.begin();

                int len = j - i;

                minLen = min(minLen, len);
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};
```

**Time Complexity:** `O(n log n)`

- Building the prefix sum array takes `O(n)`.
- Binary Search is performed for every starting index.
- Each `lower_bound()` takes `O(log n)`.

**Space Complexity:** `O(n)`

- The prefix sum array stores `n + 1` elements.

---

## 5. Sliding Window — Two Pointers (Optimal)

**Approach:**

First, we take `n` to store the size of the array and initialize `minLen = n + 1`.

We use `n + 1` because the maximum possible length of a subarray is `n`. Therefore, if `minLen` remains `n + 1`, it means no valid subarray has been found.

Then, we initialize `i = 0` and `sum = 0`.

Here, `i` represents the starting index of the current window, and `sum` stores the sum of elements present inside the current window.

After that, we use a `for` loop with `j`, starting from `0` and continuing until `j < n`.

Here, `j` represents the ending index of the current window.

Inside the `for` loop, we expand the window by adding the current element `nums[j]` to `sum`:

```cpp
sum += nums[j];
```

Here, `nums[j]` represents the current element at index `j`.

By adding this element to `sum`, we expand the current window towards the right and include the new element in the window.

For example, if:

```cpp
nums = {2, 3, 1, 2, 4, 3};

i = 0;
j = 2;
```

The current window becomes:

```cpp
{2, 3, 1}
```

Therefore:

```cpp
sum = 2 + 3 + 1;

sum = 6;
```

After expanding the window, we check whether:

```cpp
sum >= target;
```

If the current window sum reaches or exceeds the target, we enter the `while` loop.

We use a `while` loop instead of an `if` statement because we want to continue shrinking the current window as long as its sum remains greater than or equal to the target.

Inside the `while` loop, we calculate the current window length using:

```cpp
int len = j - i + 1;
```

Here, `j - i + 1` gives the number of elements present between the starting index `i` and ending index `j`, including both positions.

For example:

```cpp
i = 0;
j = 2;

len = 2 - 0 + 1;

len = 3;
```

After calculating the length, we compare it with `minLen`.

If:

```cpp
len < minLen;
```

we update `minLen` with the current window length because we have found a smaller valid subarray.

Then, we shrink the current window by subtracting the leftmost element from `sum`:

```cpp
sum -= nums[i];
```

Here, `nums[i]` represents the leftmost element of the current window.

By subtracting this element from `sum`, we remove its contribution from the current window sum.

For example:

```cpp
nums = {2, 3, 1, 2, 4, 3};

i = 0;
j = 2;

sum = 6;
```

The current window is:

```cpp
{2, 3, 1}
```

After subtracting the leftmost element:

```cpp
sum = 6 - 2;

sum = 4;
```

Now, we increment `i` by 1:

```cpp
i++;
```

This moves the starting index forward and removes the leftmost element from the current window.

The current window now becomes:

```cpp
{3, 1}
```

Here, `i` represents the new starting index, while `j` remains at the same ending index.

After moving `i`, the `while` loop checks the updated `sum` again.

If `sum >= target`, we calculate the new window length, update `minLen` if necessary, and shrink the window again.

If `sum < target`, the `while` loop stops because the current window is no longer valid.

Once the `while` loop finishes, the outer `for` loop increments `j` by 1.

This expands the window towards the right by including the next element of the array.

The process continues until `j` reaches the end of the array.

Since all array elements are positive, expanding the window increases its sum, while shrinking the window decreases its sum.

Therefore, whenever the window sum reaches the target, we can keep shrinking the window to find smaller valid subarrays without generating every possible subarray separately.

Finally, if `minLen` remains equal to `n + 1`, it means no valid subarray was found, so we return `0`.

Otherwise, we return `minLen`, which stores the minimum length among all valid subarrays.

---

### Why This Approach Is Optimal

In the previous approaches, we generated every possible subarray using two loops.

In this approach, we maintain a single window using two pointers, `i` and `j`.

The right pointer `j` moves forward through the array and expands the window by adding elements to `sum`.

Whenever the current sum reaches or exceeds the target, the left pointer `i` moves forward and shrinks the window.

This allows us to check smaller valid windows without generating every possible subarray separately.

The right pointer traverses the array only once.

The left pointer also moves forward through the array and never moves backwards.

Therefore, each element is added to the window once and removed from the window at most once.

Even though we use a `for` loop and a `while` loop, the total number of pointer movements is proportional to the size of the array.

**Code**

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int minLen = n + 1;

        int i = 0;
        int sum = 0;

        for (int j = 0; j < n; j++) {

            sum += nums[j];

            while (sum >= target) {

                int len = j - i + 1;

                if (len < minLen) {
                    minLen = len;
                }

                sum -= nums[i];

                i++;
            }
        }

        if (minLen == n + 1) {
            return 0;
        }

        return minLen;
    }
};
```

**Time Complexity:** `O(n)`

- The right pointer traverses the array once.
- The left pointer also traverses the array at most once.
- Therefore, the overall time complexity is `O(n)`.

**Space Complexity:** `O(1)`

- Only variables are used to maintain the current window and minimum length.

---

# Understand the Pattern

The problem asks us to find the **minimum length of a contiguous subarray** whose sum reaches or exceeds the target.

**Subarray:** A contiguous portion of an array.

**Prefix Sum:** Stores cumulative sums to calculate subarray sums efficiently.

**Binary Search:** Finds the minimum possible subarray length by searching possible lengths.

**Sliding Window:** Maintains a contiguous subarray using two pointers and its current sum.

**Why Sliding Window?** Since all elements are positive, expanding increases the sum and shrinking decreases it.

**Minimum Subarray Length** → Positive Array → Sliding Window → Two Pointers

**Preferred Approach:** Sliding Window (Two Pointers)
Finds the minimum valid subarray length in `O(n)` time and `O(1)` auxiliary space.


---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">