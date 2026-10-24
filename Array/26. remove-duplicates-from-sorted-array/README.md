Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

## 01. Brute Force — Nested Loop Shifting

**Approach:**

First, we take `n` to store the size of the array. Then, using the first `for` loop, we traverse the sorted array and check whether `nums[i]` is equal to `nums[i + 1]`. If both elements are equal, it means that a duplicate element is found.

If a duplicate is found, we use another `for` loop with `j`, starting from `i + 1`. We take the next element `nums[j + 1]` and place it at the current position `nums[j]`. We continue shifting the remaining elements one position to the left until we reach the second-last element.

After shifting, we decrease `n` by 1 because one duplicate element has been logically removed from the array.

Then, we decrease `i` by 1 so that when the outer loop increments it again, we check the same index. This is necessary because after shifting, another duplicate element may have come into that position.

We continue this process until the entire array has been traversed and return `n`, which represents the number of remaining unique elements in the array.

## Code:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {

            if (nums[i] == nums[i + 1]) {

                // Shift remaining elements to the left
                for (int j = i + 1; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }

                // Decrease logical size and check this index again
                n--;
                i--;
            }
        }

        return n;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## 02. Two Pointers — Overwriting

**Approach:**

First, we take `n` to store the size of the array and initialize `i` to track the position of the last unique element. Then, using the `for` loop with `j`, we traverse the sorted array and compare `nums[i]` with `nums[j]`.

If both elements are different, it means a new unique element is found. We place this element at `nums[i + 1]` and increment `i` to move to the next unique position.

We continue this process until the entire array has been traversed and return `i + 1`, which represents the number of unique elements in the array.

## Code:

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for (int j = 1; j < n; j++) {

            if (nums[i] != nums[j]) {

                // Place the next unique element
                nums[i + 1] = nums[j];

                // Move to the next unique position
                i++;
            }
        }

        return i + 1;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## 03. Two Pointers — Swapping

**Approach:**

First, we take `n` to store the size of the array and initialize `i` to track the position of the last unique element. Then, using the `for` loop with `j`, we traverse the sorted array and compare `nums[i]` with `nums[j]`.

If both elements are different, it means a new unique element is found. We use `swap()` to place `nums[j]` at `nums[i + 1]` and move the element at that position to `nums[j]`. Then, we increment `i` to move to the next unique position.

We continue this process until the entire array has been traversed and return `i + 1`, which represents the number of unique elements in the array.

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for (int j = 1; j < n; j++) {

            if (nums[i] != nums[j]) {

                // Swap the next unique element into its correct position
                swap(nums[i + 1], nums[j]);

                // Move to the next unique position
                i++;
            }
        }

        return i + 1;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## 05. STL — `unique()`

**Approach:**

First, we use `unique()` from the `<algorithm>` library and pass `nums.begin()` and `nums.end()` to it. Here, `nums.begin()` points to the first element of the array, and `nums.end()` points to the position after the last element.

The `unique()` function compares consecutive elements and moves the unique elements to the beginning of the array by overwriting duplicates. It returns an iterator `newEnd` pointing to the position immediately after the last unique element.

Then, we subtract `nums.begin()` from `newEnd` to calculate the number of unique elements. Since both are iterators, their subtraction gives the distance between them, which represents the count of unique elements.

Finally, we return this count. The original vector size remains unchanged because `unique()` only rearranges the elements and does not physically remove them.


**Code:**

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Move consecutive duplicates to the end
        auto newEnd = unique(nums.begin(), nums.end());

        // Return the number of unique elements
        return newEnd - nums.begin();
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---
Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/87599497-3f81-4882-bf7d-e4e46aab593a_1683459516.4004748.jpeg">