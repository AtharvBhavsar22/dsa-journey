Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!



## 1. Brute Force — Nested Loop Search

**Approach:** Iterate through every number from `0` to `n` and check whether it exists in the array using a nested loop.

 For each number in the expected range, initialize a `found` flag to `false`. 

Use the inner loop to search the entire array for that number. If the number is found, set `found` to `true` and stop searching using `break`. 

After the inner loop finishes, if `found` is still `false`, return that number as the missing number. If all numbers from `0` to `n - 1` are found, return `n` as the missing number.

### Code:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return i;
            }
        }

        return -1;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(1)`

---

## 2. Sorting — Range Comparison

**Approach:** Sort the array in ascending order and create a range vector containing numbers from `0` to `n`.

Since the array contains numbers from `0` to `n` with one number missing, sorting places the numbers in ascending order. 

We compare each element of the sorted array with the corresponding element in the range vector. 

If they don't match, the range element is the missing number. If all elements match, the missing number is `n`.

### Code:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> range(n + 1);

        for (int i = 0; i <= n; i++) {
            range[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != range[i]) {
                return range[i];
            }
        }

        return n;
    }
};
```

**Time Complexity:** `O(n log n)`

**Space Complexity:** `O(n) — range vector`


---
## 3. Vector Marking — Presence Tracking

**Approach:** 

#### Initialize the Vector

Since the nums array contains `n` elements, its indexes range from`0` to `n - 1`. However, the numbers range from `0` to `n`, so we initialize the vector with size `n + 1` to represent the complete range, including the missing number.

#### Given Input

```cpp
nums = [3, 0, 1]
n = nums.size(); // n = 3
```

| Array | Index | 0 | 1 | 2 | 3 |
|---|---|---|---|---|---|
| `nums` | Element | 3 | 0 | 1 | — |
| Complete Range | Number | 0 | 1 | 2 | 3 |

Therefore, we initialize the auxiliary vector with size `n + 1` to represent the complete range, including the missing number.

### Initially

Initially, every element is set to `-1`, indicating that no number has been marked as present.

| Index | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| `v` | -1 | -1 | -1 | -1 |

#### Mark the Numbers Present

Traverse the `nums` array and use each number as an index in the vector.

For every element `nums[i]`, store that number at its corresponding index in `v`.

Here, `i` represents the index of the `nums` array, while `nums[i]` represents the actual number.

**Dry Run:**

| `i` | `nums[i]` | Operation | Vector after operation |
|---|---|---|---|
| 0 | 3 | `v[3] = 3` | `[-1, -1, -1, 3]` |
| 1 | 0 | `v[0] = 0` | `[0, -1, -1, 3]` |
| 2 | 1 | `v[1] = 1` | `[0, 1, -1, 3]` |

After traversing the entire array, the vector becomes:

| Index | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| `v` | 0 | 1 | -1 | 3 |

The numbers `0`, `1`, and `3` have been marked at their corresponding indexes.

However, the number `2` was not present in the original array, so its corresponding index remains `-1`.

### Find the Missing Number

Traverse the marking vector from index `0` to `n`.

At each index, check whether the element is still `-1`.

- If `v[i] == -1`, it means the number represented by that index was never marked as present.
- Therefore, the index `i` represents the missing number.
- Return that index.

**Dry Run:**

| `i` | `v[i]` | Condition | Result |
|---|---|---|---|
| 0 | 0 | `0 == -1` → false | Continue |
| 1 | 1 | `1 == -1` → false | Continue |
| 2 | -1 | `-1 == -1` → true | Return 2 |

The loop reaches index `2`, where the value is still `-1`.

Therefore, the missing number is `2`, and the function returns `2`.

If no missing number is found, `return 0` acts as a fallback. Under the given problem constraints, the missing number will be found and returned by the second loop.


### Code:

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        // Initialize vector with -1
        vector<int> v(n + 1, -1);

        // Mark numbers present
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }

        // Find missing number
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                return i;
            }
        }

        return 0;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(n)`

---

## 4. Mathematical Formula — Expected Sum Calculation

**Approach:** Calculate the expected sum of numbers from `0` to `n` using the mathematical formula. 

Then calculate the actual sum of the array elements. 

Subtract the actual sum from the expected sum to find the missing number.

Logic behind the Expected sum Formula  `S = n * (n + 1) / 2`


**1. Sum of First N Natural Numbers**

The formula calculates the sum of all natural numbers from 1 to n.

`S = n * (n + 1) / 2`

`n` = last number in the sequence
`S` = sum of all numbers from 1 to n

**2. Derivation of the Formula**

#### Write the sum

For numbers from 1 to 5:

`S = 1 + 2 + 3 + 4 + 5`

#### Reverse the sequence

`S = 5 + 4 + 3 + 2 + 1`

#### Add both sequences

```text
S = 1 + 2 + 3 + 4 + 5
S = 5 + 4 + 3 + 2 + 1
-----------------------
2S = 6 + 6 + 6 + 6 + 6
```

Every pair gives 6, and there are 5 pairs.

`2S = 5 * 6`

`2S = 30`

`S = 30 / 2`

`S = 15`

### 3. Generalize for n

#### Original sequence:

`S = 1 + 2 + 3 + ... + n`

#### Reverse sequence:

`S = n + (n - 1) + (n - 2) + ... + 1`

#### Adding both sequences:

Each pair gives `n + 1`.

There are `n` pairs.

`2S = n * (n + 1)`

Dividing both sides by 2:

**`S = n * (n + 1) / 2`**

The formula calculates the expected sum of all numbers from 0 to n.

Since the array contains one missing number, its actual sum will be smaller than the expected sum.

We calculate the actual sum using a loop and subtract it from the expected sum to obtain the missing number.

**Code:**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---
## 5. XOR — Bitwise Cancellation

**Approach:**

Lets understand every thing from zero.

XOR is a bitwise operator in C++.

Its symbol is:

```cpp
^
```

XOR compares two numbers bit by bit.

The rule is:

- If both bits are the same, the result is `0`.
- If both bits are different, the result is `1`.

### XOR Truth Table

| A | B | A ^ B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

**Remember:** Same bits → `0`. Different bits → `1`.

### How XOR Works with Numbers

Let's take:

```cpp
3 ^ 5
```

First, convert both numbers into binary.

| Number | Binary |
|---|---|
| 3 | `011` |
| 5 | `101` |

Now compare each bit.

####  Bit-by-Bit XOR

|  | Bit 2 | Bit 1 | Bit 0 |
|---|---|---|---|
| 3 | 0 | 1 | 1 |
| 5 | 1 | 0 | 1 |
| XOR | 1 | 1 | 0 |

The result is:

```cpp
3 ^ 5 = 6
```

Because the resulting binary number is:

`110` = `6`

Since the numbers in the `nums` array range from `0` to `n`, we initialize `ans` with `0`.

We then traverse the complete range of numbers from `1` to `n` and perform the XOR operation with each number.

After this, we traverse the `nums` array and perform XOR with every element.

The XOR operation has the following properties:

- `a ^ a = 0` — XOR of the same number cancels out.
- `a ^ 0 = a` — XOR with zero leaves the number unchanged.
- `a ^ b = b ^ a` — XOR is commutative.

Therefore, every number present in both the complete range and the `nums` array cancels out.

The only number that remains is the missing number.

### Given Input

```cpp
nums = [3, 0, 1]
n = nums.size(); // n = 3
```

| Array | Index | 0 | 1 | 2 |
|---|---|---|---|---|
| `nums` | Element | 3 | 0 | 1 |

The complete range of numbers is:

| Complete Range | Number | 0 | 1 | 2 | 3 |
|---|---|---|---|---|---|

### Initialize the Answer

Initially, `ans` is set to `0`.

```cpp
int ans = 0;
```

We traverse the numbers from `1` to `n` and perform XOR with `ans`.

**Dry Run:**

| `i` | Operation | `ans` |
|---|---|---|
| 1 | `ans = 0 ^ 1` | 1 |
| 2 | `ans = 1 ^ 2` | 3 |
| 3 | `ans = 3 ^ 3` | 0 |

After traversing the complete range, `ans` becomes `0`.

The XOR operation of the complete range is:

`1 ^ 2 ^ 3 = 0`

### XOR the Numbers Present

Now, traverse the `nums` array and perform XOR with every element.

For every element `nums[i]`, update `ans` using:

```cpp
ans = ans ^ nums[i];
```

**Dry Run:**

| `i` | `nums[i]` | Operation | `ans` |
|---|---|---|---|
| 0 | 3 | `ans = 0 ^ 3` | 3 |
| 1 | 0 | `ans = 3 ^ 0` | 3 |
| 2 | 1 | `ans = 3 ^ 1` | 2 |

After traversing the entire array, `ans` becomes `2`.

#### How XOR Finds the Missing Number

**XOR the Complete Range**

Since `n = 3`, the complete range of numbers is `0, 1, 2, 3`.

We perform XOR on all the numbers in this range.

```cpp
0 ^ 1 ^ 2 ^ 3
```

**XOR the Numbers Present in the Array**

The original array contains the numbers `3, 0, 1`.

We perform XOR with these numbers as well.

```cpp
3 ^ 0 ^ 1
```

**Cancel the Numbers Present in Both**

Now, combine the complete range and the original array.

```cpp
0 ^ 1 ^ 2 ^ 3 ^ 3 ^ 0 ^ 1
```

Since the numbers `0`, `1`, and `3` are present in both the complete range and the original array, they cancel out.

- `0 ^ 0 = 0`
- `1 ^ 1 = 0`
- `3 ^ 3 = 0`

However, the number `2` is present only in the complete range and is missing from the original array.

Therefore, it does not have another matching number to cancel it out.

**Obtain the Missing Number**

After cancelling the matching numbers, only `2` remains.

```cpp
0 ^ 0 ^ 0 ^ 2 = 2
```

Therefore, the final XOR result is `2`, which is the missing number.

The function returns `ans`, which contains the missing number.
### Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = ans ^ i;
        }

        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};
```
**Time Complexity:** `O(n)`

**Auxiliary Space Complexity:** `O(1)`

---
## Understand the Pattern


The problem asks us to find the only missing number from an array containing `n` distinct numbers in the range `[0, n]`.

**Complete Range:** Since the array contains `n` numbers, the complete range contains `n + 1` numbers, from `0` to `n`. Exactly one number is missing.

- **Brute Force:** Checks every number in the complete range against the array to find which number is missing.
- **Sorting:** Sorts the array and compares its elements with the complete range to identify the missing number.
- **Vector Marking:** Uses an auxiliary vector to mark the numbers present in the array. The index that remains unmarked represents the missing number.
- **Mathematical Formula:** Calculates the expected sum of the complete range and subtracts the actual sum of the array to find the missing number.
- **XOR:** Uses bitwise cancellation to eliminate numbers that appear in both the complete range and the array, leaving only the missing number.

**Why XOR?** 

We need to find the missing number without sorting or using an auxiliary data structure. XOR cancels matching numbers using `a ^ a = 0`, leaving the missing number. Therefore, it provides an efficient solution with O(n) time complexity and O(1) auxiliary space.

**Pattern:** Missing Number → Complete Range → XOR Cancellation

**Preferred Approach = XOR**

Uses bitwise cancellation to identify the missing number in O(n) time and O(1) auxiliary space.

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">
