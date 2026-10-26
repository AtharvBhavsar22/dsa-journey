# 217. Contains Duplicate

**LeetCode Problem:** [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)  
**Difficulty:** Easy  
**Topics:** Array, Hash Table, Sorting

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

## 1. Brute Force — Nested Loop Comparison

**Approach:** Compare each element with every element that comes after it. If any two elements are equal, a duplicate exists.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

**Time Complexity:** `O(n²)`  
**Space Complexity:** `O(1)`

---

## 2. Sorting — Adjacent Element Comparison

**Approach:** Sort the array so that duplicate elements become adjacent. Then compare each element with its previous element. If they are equal, a duplicate exists.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};
```

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(1)`

---

## 3. Set — Unique Element Count Comparison

**Approach:** Insert all array elements into a `set`. Since a set stores only unique elements, compare the original array size with the set size. If the original size is greater, duplicates exist.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
```

**Time Complexity:** `O(n log n)`  
**Space Complexity:** `O(n)`

---

## 4. Unordered Set — Hash Set Lookup and Insertion

**Approach:**

An `unordered_set` is a container that stores unique elements and uses hashing for fast insertion and lookup.

- It does not store duplicate elements.
- `count(x)` checks whether an element exists. It returns `1` if found and `0` if not found.
- `insert(x)` adds the element to the set if it is not already present.

**Logic:** Traverse the array and check each element using `count()`. If found, return `true`; otherwise, insert it using `insert()`. If no duplicates are found, return `false`.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            seen.insert(x);
        }

        return false;
    }
};
```

**Time Complexity:** `O(n)` average  
**Space Complexity:** `O(n)`

---

## 5. Unordered Map — Presence Tracking

**Approach:**

An `unordered_map` stores key-value pairs and uses hashing for fast lookup. It helps track previously encountered elements.

- `count(x)` checks whether the key exists.
- `seen[x] = 1` stores the element.

**Logic:** Traverse the array and check whether each element exists using `count()`. If found, return `true`; otherwise, store it in the map. If no duplicates are found, return `false`.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            seen[x] = 1;
        }

        return false;
    }
};
```

**Time Complexity:** `O(n)` average  
**Space Complexity:** `O(n)`

---

## 6. Unordered Map — Frequency Counting

**Approach:** An `unordered_map` stores elements with their frequencies using hashing for fast lookup.

- `seen[num]` accesses the element's frequency.
- `seen[num] >= 1` checks if it appeared before.
- `seen[num]++` increases its frequency.

### Example

**Input:** `nums = {1, 2, 3, 1}`

| Number | Frequency |
|---|---:|
| 1 | 2 |
| 2 | 1 |
| 3 | 1 |

### Logic

Traverse the array and check each element's frequency. If it is already `1` or greater, return `true`; otherwise, increment its frequency. If no duplicates are found, return `false`.

### Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        for (int num : nums) {
            if (seen[num] >= 1)
                return true;

            seen[num]++;
        }

        return false;
    }
};
```

**Time Complexity:** `O(n)` average  
**Space Complexity:** `O(n)`

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
