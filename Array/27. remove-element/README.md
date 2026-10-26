Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

## 1. Brute Force — Nested Loop Shifting

**Approach:**

First, we take `n` to store the size of the array. Then, using the first `for` loop, we traverse the array and check whether `nums[i]` is equal to `val`.

If `nums[i] == val`, we use another `for` loop with `j`, starting from the same index `i`. We take the next element `nums[j + 1]` and place it at the current position `nums[j]`. We continue shifting the elements one position to the left until we reach the last element.

After shifting, we decrease `n` by 1 because one element has been logically removed from the array.

Then, we decrease `i` by 1 so that when the outer loop increments it again, we check the same index. This is necessary because after shifting, another occurrence of `val` may have come into that position.

We continue this process until the entire array has been traversed and return `n`, which represents the number of remaining valid elements.

**Code:**

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == val) {

                // Shift remaining elements to the left
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }

                // Decrease the logical size
                n--;

                // Check the current index again
                i--;
            }
        }

        return n;
    }
};
```

- Time Complexity: `O(n²)`
- Auxiliary Space: `O(1)`

---

## 2. Marking — Sorting and Restoring

**Approach:** 

First, we take `n` to store the size of the array and initialize `count` to `0` to keep track of the number of elements that are not equal to `val`.

Then, using the first `for` loop, we traverse the array and check whether `nums[i]` is not equal to `val`.

If `nums[i] != val`, we multiply that element by `-1` to mark it and increase `count` by `1` because we found a valid element that should remain in the array.

We continue this process until the entire array has been traversed and all the valid elements have been marked.

After marking, we use the `sort()` function to sort the array. This brings the marked negative elements toward the beginning of the array and the unmarked elements toward the end.

Then, we use another `for` loop to traverse the entire array and multiply every element by `-1` again. This restores the original values of the elements.

Finally, we return `count`, which represents the number of elements that are not equal to `val` and should remain in the array.

### Code:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;

        // Mark elements not equal to val
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[i] = nums[i] * -1;
                count++;
            }
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Restore the marked elements
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * -1;
        }

        return count;
    }
};
```

- Time Complexity: `O(n log n)`
- Auxiliary Space: `O(log n)` typical sorting stack
---

## 3. Two Pointers — Overwrite / In-place Copying

**Approach:**

First, we initialize `i` and `j` to `0`. Here, `j` is used to traverse the array, and `i` is used to track the position where the next valid element should be placed.

Then, using the `for` loop, we traverse the array with `j` and check whether `nums[j]` is not equal to `val`.

If `nums[j] != val`, we take that element and place it at the position `nums[i]`. This means we copy the valid element to the position where the next valid element should be placed.

After copying the element, we increase `i` by `1` because one valid element has been placed in the array.

If `nums[j] == val`, we do not copy that element and do not increase `i`. We only move `j` forward to check the next element.

We continue this process until the entire array has been traversed. Since `i` keeps track of the position where the next valid element should be placed, its final value represents the total number of valid elements.

Finally, we return `i`, which represents the number of elements that are not equal to `val`.

### Code:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {

            if (nums[j] != val) {
                nums[i] = nums[j];

                i++;
            }
        }

        return i;
    }
};
```

- Time Complexity: `O(n)`
- Auxiliary Space: `O(1)`

---

## 4. Two Pointers — Swapping
## Approach:

First, we initialize `i` and `count` to `0`. Here, `i` is used to track the position where the next valid element should be placed, and `count` is used to store the total number of valid elements.

Then, using the `for` loop, we traverse the array with `j` and check whether `nums[j]` is not equal to `val`.

If `nums[j] != val`, we use the `swap()` function to swap `nums[i]` and `nums[j]`. This places the valid element at the position where the next valid element should be placed.

After swapping, we increase `i` by `1` because one valid element has been placed in the array. We also increase `count` by `1` because we found one element that is not equal to `val`.

If `nums[j] == val`, we do not perform any swapping and do not increase `i` or `count`. We only move `j` forward to check the next element.

We continue this process until the entire array has been traversed and all the valid elements have been placed at the beginning of the array.

Finally, we return `count`, which represents the total number of elements that are not equal to `val`.

### Code:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int count = 0;

        for (int j = 0; j < n; j++) {

            if (nums[j] != val) {
                swap(nums[i], nums[j]);

                count++;
                i++;
            }
        }

        return count;
    }
};
```

- Time Complexity: `O(n)`
- Auxiliary Space: `O(1)`

---

## 5. Two Pointers — Reverse Traversal / Replace with Last Element

## Approach:

First, we initialize `i` to `0` and take `n` to store the size of the array. Here, `i` is used to traverse the array, and `n` represents the logical size of the array, which keeps track of the elements that are still unchecked.

Then, using the `while` loop, we traverse the array while `i` is less than `n` and check whether `nums[i]` is equal to `val`.

If `nums[i] == val`, we take the last unchecked element `nums[n - 1]` and place it at the current position `nums[i]`. This replaces the element equal to `val` with another element from the end of the array.

After replacing the element, we decrease `n` by `1` because one element has been logically removed from the array.

We do not increment `i` in this case because the element that came from the last position has not been checked yet. We keep `i` at the same position and check whether the replacement element is also equal to `val`.

If `nums[i] != val`, it means the current element is valid and should remain in the array. Therefore, we increment `i` and move to the next element.

We continue this process until `i` reaches `n`, which means all the elements within the logical size of the array have been checked.

Finally, we return `n`, which represents the number of remaining valid elements.

### Code:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {

            if (nums[i] == val) {
                nums[i] = nums[n - 1];

                n--;
            }
            else {
                i++;
            }
        }

        return n;
    }
};
```

- Time Complexity: `O(n)`
- Auxiliary Space: `O(1)`

---

## 6. STL — `remove()` Algorithm

## Approach:

First, we use the STL `remove()` algorithm to remove all the elements equal to `val` from the array logically.

We pass `nums.begin()`, `nums.end()`, and `val` to the `remove()` function. Here, `nums.begin()` represents the starting position of the array, `nums.end()` represents the position after the last element, and `val` is the element we want to remove.

The `remove()` function traverses the array and checks each element. Whenever `nums[i]` is not equal to `val`, it moves that valid element toward the beginning of the array while preserving the original order of the valid elements.

After traversing the array, `remove()` returns an iterator called `newEnd`, which points to the position immediately after the last valid element.

Then, we subtract `nums.begin()` from `newEnd`. This gives us the number of valid elements present at the beginning of the array.

Finally, we return this value, which represents the number of elements that are not equal to `val`.

### Code:

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        auto newEnd = remove(nums.begin(), nums.end(), val);

        return newEnd - nums.begin();
    }
};
```

- Time Complexity: `O(n)`
- Auxiliary Space: `O(1)`

---
Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/e78315ef-8a9d-492b-9908-e3917f23eb31_1674946036.087042.jpeg">

---

