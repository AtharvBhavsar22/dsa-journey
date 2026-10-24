Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

## 1. Brute Force (Linear Search)

**Approach:**
- Check each number from `1` to `n` using `find()`, which returns its iterator if found or `end(nums)` if not.
- If `find()` returns `end(nums)`, add the missing number to `ans`; otherwise, skip it.

**Code:**
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        for (int i = 1; i <= n; i++) {

            if (find(begin(nums), end(nums), i) == end(nums)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

**Time Complexity:** O(n²)

**Space Complexity:** O(1), excluding the answer vector.

---

## 2. Brute Force (Range Vector + Linear Search)

**Approach:** Create a separate vector containing all numbers from `1` to `n`. Check each number in the range vector using linear search in the original array. If it is not found, add it to the answer.

**Code:**
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> notSeen;
        vector<int> range;

        for (int i = 1; i <= n; i++) {
            range.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (find(nums.begin(), nums.end(), range[i]) == nums.end()) {
                notSeen.push_back(range[i]);
            }
        }

        return notSeen;
    }
};
```

**Time Complexity:** O(n²)

**Space Complexity:** O(n), excluding the answer vector.

---

## 3. Sorting + Binary Search


**Binary Search:**
- Check the middle element of the sorted array and compare it with the target.
- If equal, the element is found; otherwise, search the appropriate half until found or the range becomes empty.

**Approach:**
- Sort the original array, then check each number from `1` to `n` using `binary_search()`.
- If `binary_search()` returns `false`, add the missing number to `ans`; otherwise, skip it.

**Code:**

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<int> ans;

        for (int i = 1; i <= n; i++) {

            if (!binary_search(begin(nums), end(nums), i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

**Time Complexity:** O(n log n)

**Space Complexity:** O(1) auxiliary space, excluding the answer vector and sorting implementation's internal space.

---

## Approach 4: Unordered Set (Presence Tracking)



**Approach:**
- Insert all elements of the original array into an `unordered_set` for fast searching.
- Check each number from `1` to `n` using `find()`. If it returns `st.end()`, add the missing number to `ans`; otherwise, skip it.


```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        vector<int> ans;

        int n = nums.size();

        for (int i = 1; i <= n; i++) {

            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

**Time Complexity:** O(n) average

**Space Complexity:** O(n), excluding the answer vector.

---
## 5. Cyclic Sort / Index Placement

### **Approach:**

The array contains numbers from `1` to `n`, but these numbers may not be present at their correct indexes.

Our goal is to place each number at its correct index.

Since array indexing starts from `0`, each number belongs at the index one less than its value.

For example, number `1` belongs at index `0`, number `2` belongs at index `1`, and so on.

| Array Index | Expected Number |
|---|---|
| `0` | `1` |
| `1` | `2` |
| `2` | `3` |
| `3` | `4` |
| `4` | `5` |
| `5` | `6` |
| `6` | `7` |
| `7` | `8` |

Therefore, the correct index of any number `c` is `c - 1`.

### **Understanding Index Placement:**

The array indexes start from `0`, but the numbers in the array start from `1`.

| Index | Number | Correct Index |
|---|---|---|
| `0` | `1` | `1 - 1 = 0` |
| `1` | `2` | `2 - 1 = 1` |
| `2` | `3` | `3 - 1 = 2` |
| `3` | `4` | `4 - 1 = 3` |
| `4` | `5` | `5 - 1 = 4` |
| `5` | `6` | `6 - 1 = 5` |
| `6` | `7` | `7 - 1 = 6` |
| `7` | `8` | `8 - 1 = 7` |

We traverse the array and check whether the current number `c` is placed at its correct index. If not, we swap it with the element at index `c - 1`.

We continue swapping until the number reaches its correct position or its correct index already contains the same number.

### **Execution:**

**Input:**

```cpp
nums = [4,3,2,7,8,2,3,1]
```

| Iteration | `c` | `c - 1` | `nums[c - 1]` | Operation |
|---|---:|---:|---:|---|
| `i = 0` | `4` | `3` | `7` | Swap `4` and `7` |
| `i = 0` | `7` | `6` | `3` | Swap `7` and `3` |
| `i = 0` | `3` | `2` | `2` | Swap `3` and `2` |
| `i = 0` | `2` | `1` | `3` | Swap `2` and `3` |
| `i = 0` | `3` | `2` | `3` | Stop |
| `i = 1` | `2` | `1` | `2` | No swap |
| `i = 2` | `3` | `2` | `3` | No swap |
| `i = 3` | `4` | `3` | `4` | No swap |
| `i = 4` | `8` | `7` | `1` | Swap `8` and `1` |
| `i = 4` | `1` | `0` | `3` | Swap `1` and `3` |
| `i = 4` | `3` | `2` | `3` | Stop |
| `i = 5` | `2` | `1` | `2` | No swap |
| `i = 6` | `7` | `6` | `7` | No swap |
| `i = 7` | `8` | `7` | `8` | No swap |

**Array After Each Swap:**

| Step | Array |
|---|---|
| 1 | `[7,3,2,4,8,2,3,1]` |
| 2 | `[3,3,2,4,8,2,7,1]` |
| 3 | `[2,3,3,4,8,2,7,1]` |
| 4 | `[3,2,3,4,8,2,7,1]` |
| 5 | `[3,2,3,4,1,2,7,8]` |
| 6 | `[1,2,3,4,3,2,7,8]` |

**Final Array:**

```cpp
nums = [1,2,3,4,3,2,7,8]
```

After placing the numbers, we traverse the array again and compare each index with its expected number.

If `nums[i] != i + 1`, it means the number `i + 1` is missing from the array, so we add it to `ans`.

### **Finding Missing Numbers:**

| Index `i` | Expected `i + 1` | `nums[i]` | Result |
|---|---:|---:|---|
| `0` | `1` | `1` | Correct |
| `1` | `2` | `2` | Correct |
| `2` | `3` | `3` | Correct |
| `3` | `4` | `4` | Correct |
| `4` | `5` | `3` | Add `5` |
| `5` | `6` | `2` | Add `6` |
| `6` | `7` | `7` | Correct |
| `7` | `8` | `8` | Correct |

**Output:**

```cpp
[5,6]
```

### **Code:**

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;

        for(auto& c : nums) {

            while(nums[c-1] != c) {
                swap(c, nums[c-1]);
            }
        }

        for(int i = 1; i <= size(nums); i++) {

            if(i != nums[i-1]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
```

**Time Complexity:** O(n)

**Space Complexity:** O(1), excluding the answer vector.

---

## Approach 6: Negative Marking (Index Marking)

### **Approach:**

Use the array indexes to mark the numbers that are present.

Since array indexing starts from `0`, each number `c` corresponds to index `c - 1`.

For every number `c`, make the element at index `c - 1` negative to mark that the number `c` is present.

If the element is already negative, it means that number has already been marked.

After marking, the indexes that still contain positive values represent the missing numbers.

### **Understanding Index Marking:**

The array indexes start from `0`, but the numbers in the array start from `1`.

| Array Index | Expected Number |
|---|---|
| `0` | `1` |
| `1` | `2` |
| `2` | `3` |
| `3` | `4` |
| `4` | `5` |
| `5` | `6` |
| `6` | `7` |
| `7` | `8` |

Therefore, for any number `c`, we use index `c - 1` to mark its presence.

For example, if `c = 4`, we use index `4 - 1 = 3`.

We make the element at index `3` negative to indicate that number `4` is present.

### **Execution:**

**Input:**

```cpp
nums = [4,3,2,7,8,2,3,1]
```

We traverse the array and use each number `c` to mark its corresponding index `c - 1`.

| Iteration | `c` | `c - 1` | `nums[c - 1]` Before | Operation |
|---|---:|---:|---:|---|
| `i = 0` | `4` | `3` | `7` | Mark index `3` negative |
| `i = 1` | `3` | `2` | `2` | Mark index `2` negative |
| `i = 2` | `2` | `1` | `3` | Mark index `1` negative |
| `i = 3` | `7` | `6` | `3` | Mark index `6` negative |
| `i = 4` | `8` | `7` | `1` | Mark index `7` negative |
| `i = 5` | `2` | `1` | `-3` | Already marked |
| `i = 6` | `3` | `2` | `-2` | Already marked |
| `i = 7` | `1` | `0` | `4` | Mark index `0` negative |

### **Array After Each Marking:**

| Step | Array |
|---|---|
| Initial | `[4,3,2,7,8,2,3,1]` |
| 1 | `[4,3,2,-7,8,2,3,1]` |
| 2 | `[4,3,-2,-7,8,2,3,1]` |
| 3 | `[4,-3,-2,-7,8,2,3,1]` |
| 4 | `[4,-3,-2,-7,8,2,-3,1]` |
| 5 | `[4,-3,-2,-7,8,2,-3,-1]` |
| 6 | `[4,-3,-2,-7,8,2,-3,-1]` |
| 7 | `[4,-3,-2,-7,8,2,-3,-1]` |
| 8 | `[-4,-3,-2,-7,8,2,-3,-1]` |

**Final Array After Marking:**

```cpp
nums = [-4,-3,-2,-7,8,2,-3,-1]
```

After marking, we traverse the array again.

If `nums[i] > 0`, it means the number `i + 1` was never marked, so it is missing from the array.

### **Finding Missing Numbers:**

| Index `i` | Expected `i + 1` | `nums[i]` | Result |
|---|---:|---:|---|
| `0` | `1` | `-4` | Present |
| `1` | `2` | `-3` | Present |
| `2` | `3` | `-2` | Present |
| `3` | `4` | `-7` | Present |
| `4` | `5` | `8` | Add `5` |
| `5` | `6` | `2` | Add `6` |
| `6` | `7` | `-3` | Present |
| `7` | `8` | `-1` | Present |

**Output:**

```cpp
[5,6]
```

### **Code:**

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(auto c : nums)
            nums[abs(c) - 1] = -abs(nums[abs(c) - 1]);

        for(int i = 0; i < n; i++)
            if(nums[i] > 0)
                ans.push_back(i + 1);

        return ans;
    }
};
```

**Time Complexity:** O(n)

**Space Complexity:** O(1), excluding the answer vector.

---
## **Understand the Pattern**

The problem asks us to find all numbers from `1` to `n` that are missing from the given array.

**Index Placement:** A technique that uses the relationship between array indexes and numbers to identify missing elements.

- **Cyclic Sort / Index Placement:** Places each number `c` at its correct index `c - 1`. After placement, if `nums[i] != i + 1`, the number `i + 1` is missing.
- **Negative Marking:** Uses the index `c - 1` to mark the presence of number `c` by making the corresponding element negative. After marking, positive elements indicate missing numbers.
- **Hash Set:** Stores the numbers present in the array. By checking each number from `1` to `n`, we can identify which numbers are missing.

### **Why Index Placement?**

The array contains numbers from `1` to `n`, and each number has a corresponding index `c - 1`.

By placing each number at its correct index, we can identify missing numbers by checking whether the expected number is present at each index.

**Missing Number Detection** → Index Mapping → Cyclic Sort / Index Placement

### **Preferred Approach = Negative Marking**

Uses the array indexes to mark the numbers that are present. After marking, positive elements indicate missing numbers, with `O(n)` time complexity and `O(1)` auxiliary space, excluding the answer vector.

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">


---