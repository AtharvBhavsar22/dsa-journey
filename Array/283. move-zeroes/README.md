Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!


## 1. Brute Force — Repeated Shifting

**Approach:** Traverse the array and check whether the current element is zero. 

If it is, search for the next non-zero element and swap it with the current zero. Continue until the entire array has been processed.

**Logic:**

- The outer loop traverses the array using `i`.
- When `nums[i] == 0`, the inner loop searches for a non-zero element using `j`.
- When a non-zero element is found, swap `nums[i]` and `nums[j]`.
- Use `break` to stop the inner loop after the first suitable element is found.

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
```

**Time Complexity:** `O(n²)`

**Auxiliary Space:** `O(1)`

---

## 2. Two Pointers — Swap

**Approach:**

First, initialize `i = 0`. This pointer represents the position where the next non-zero element should be placed.

Then, run a loop with `j` from `0` to `n - 1`. The pointer `j` checks every element of the array one by one.

- If `nums[j] == 0`, we do nothing. The pointer `j` moves forward, but `i` stays at the same position because we have not found a non-zero element to place there.
- If `nums[j] != 0`, we swap `nums[i]` with `nums[j]`. This moves the non-zero element to the position pointed to by `i`.
- After swapping, increment `i` because the current non-zero element is now in its correct position.
- The loop then increments `j` and continues checking the next element.

We continue this process until `j` reaches the end of the array. In this way, all non-zero elements are moved to the beginning while maintaining their original relative order, and all zeroes are pushed to the end.

Initially, `i = 0` and `j = 0`.

| Step | `j` | `nums[j]` | Condition | Action | Array after action | `i` |
|---:|---:|---:|---|---|---|---:|
| 1 | 0 | 0 | `nums[j] != 0` is false | No swap; `j` moves forward | `[0, 1, 0, 3, 12]` | 0 |
| 2 | 1 | 1 | True | Swap `nums[0]` and `nums[1]`; increment `i` | `[1, 0, 0, 3, 12]` | 1 |
| 3 | 2 | 0 | False | No swap; `j` moves forward | `[1, 0, 0, 3, 12]` | 1 |
| 4 | 3 | 3 | True | Swap `nums[1]` and `nums[3]`; increment `i` | `[1, 3, 0, 0, 12]` | 2 |
| 5 | 4 | 12 | True | Swap `nums[2]` and `nums[4]`; increment `i` | `[1, 3, 12, 0, 0]` | 3 |

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                // Swap the non-zero element with the zero
                swap(nums[i], nums[j]);

                // Move to the next position
                i++;
            }
        }
    }
};
```

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`

---

## 3. STL — `remove()` + `fill()`

**Approach:** Use the STL `remove()` algorithm to move all non-zero elements to the beginning, then use `fill()` to replace the remaining positions with zeroes.

**Logic:**

#### Understand remove()

```cpp
auto it = remove(nums.begin(), nums.end(), 0);
```

- `nums.begin()` points to the first element of the vector.
- `nums.end()` represents the position just after the last element.
- `0` is the value we want to remove logically.
- `remove()` rearranges the elements so that all non-zero elements come first, maintaining their relative order.
- It returns an iterator `it` pointing to the **new logical end** of the non-zero elements.



**Input:**

```cpp
nums = {0, 1, 0, 3, 12};
```

After `remove()` finishes, the first three positions contain the non-zero elements in order:

```text
Logical elements:  [1, 3, 12]
                    ↑        ↑
                  begin      it
```

The logical end is at index `3`, meaning `it - nums.begin() == 3`.

The vector's actual size is still `5`. 

#### Understand fill()

```cpp
fill(it, nums.end(), 0);
```

- `it` marks the position immediately after the last non-zero element.
- `nums.end()` marks the position just after the vector's last element.
- `0` is the value to assign to every position in this range.
- `fill()` sets all elements from `it` up to, but not including, `nums.end()` to zero.

`fill()` sets the elements at indices `3` and `4` to zero.

**array:**

```text
[1, 3, 12, 0, 0]
```

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Move all non-zero elements to the beginning
        auto it = remove(nums.begin(), nums.end(), 0);

        // Fill the remaining positions with zeros
        fill(it, nums.end(), 0);
    }
};
```

**Time Complexity:** `O(n)` 

**Auxiliary Space:** `O(1)` 

---

## 4. STL — `stable_partition()` with Lambda

**Approach:**

Use `stable_partition()` to move all non-zero elements to the beginning of the array and all zeroes to the end, while maintaining the original relative order of the elements.

### Logic

**Understand `stable_partition()`**

```cpp
stable_partition(nums.begin(), nums.end(), [](int i) {
    return i != 0;
});
```

- `nums.begin()` points to the first element of the array.
- `nums.end()` represents the position just after the last element.
- `stable_partition()` checks every element using the given condition, called a **predicate**.
- Elements for which the predicate returns `true` are placed before elements for which it returns `false`.
- Since it is a *stable* operation, the relative order of elements within each group is preserved.

**Understand the Lambda Function**

```cpp
[](int i) {
    return i != 0;
}
```

- `[]` indicates that this is a lambda function.
- `int i` receives the current element being checked.
- `return i != 0;` checks whether the element is non-zero.
- If the element is non-zero, it returns `true`.
- If the element is zero, it returns `false`.


**Input:**

```cpp
nums = {0, 1, 0, 3, 12};
```

| Element | Condition | Result | Group |
|---:|---|---|---|
| 0 | `0 != 0` | `false` | Zeroes |
| 1 | `1 != 0` | `true` | Non-zero |
| 0 | `0 != 0` | `false` | Zeroes |
| 3 | `3 != 0` | `true` | Non-zero |
| 12 | `12 != 0` | `true` | Non-zero |


`stable_partition()` places all elements returning `true` first, followed by all elements returning `false`.

```text
Original:  [0, 1, 0, 3, 12]

True group:  [1, 3, 12]
False group: [0, 0]

Final:     [1, 3, 12, 0, 0]
```


### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int i) {
            return i != 0;
        });
    }
};
```

**Time Complexity:** `O(n)`

**Auxiliary Space:** May use `O(n)` 

---

## 5. Reverse Iterators — `stable_partition()` + `logical_not<int>()`

**Approach:** Use reverse iterators to traverse the array backward and `logical_not<int>()` to identify zeroes. Apply `stable_partition()` to place zeroes first in the reversed range, which places them at the end of the original array.

**Logic:**



**Understand Reverse Iterators**

```cpp
nums.rbegin()
nums.rend()
```

- `nums.rbegin()` points to the last element of the original array.
- `nums.rend()` represents the position just before the first element in reverse traversal.
- Therefore, the elements are processed in reverse order.

For the input:

```text
Original array: [0, 1, 0, 3, 12]
Reverse order:  [12, 3, 0, 1, 0]
```
#### But why use reverse iterators here?
Because our predicate is: `logical_not<int>()`


It returns true for zero and false for non-zero elements. stable_partition() puts the true group first in the range it receives.

Using reverse iterators means the zeroes placed first in the reversed range end up at the end of the original array.

**Understand `logical_not<int>()`**

`logical_not<int>()` is an STL function object that applies logical NOT to an integer.

- If the element is `0`, it converts to `false`, and logical NOT makes it `true`.
- If the element is non-zero, it converts to `true`, and logical NOT makes it `false`.

Therefore, `logical_not<int>()` returns `true` for zeroes and `false` for non-zero elements.

| Element | Logical NOT | Result |
|---:|---|---|
| 0 | `!0` | `true` |
| 1 | `!1` | `false` |
| 3 | `!3` | `false` |
| 12 | `!12` | `false` |

**Step 3: Understand `stable_partition()`**

```cpp
stable_partition(
    nums.rbegin(),
    nums.rend(),
    logical_not<int>()
);
```
`stable_partition()` checks each element using `logical_not<int>()`.

Elements returning `true` are placed before elements returning `false` in the reversed range.

Therefore, zeroes are placed first in the reversed range, followed by non-zero elements.

Because we are working with reverse iterators, zeroes at the beginning of the reversed range correspond to zeroes at the end of the original array.

The stable operation preserves the relative order of elements within each group in the reversed range. When viewed in the original direction, the non-zero elements retain their original relative order.


**Input:**

```cpp
nums = {0, 1, 0, 3, 12};
```

| Step | Element in Reverse | Predicate Result | Group |
|---:|---:|---|---|
| 1 | 12 | `false` | Non-zero |
| 2 | 3 | `false` | Non-zero |
| 3 | 0 | `true` | Zero |
| 4 | 1 | `false` | Non-zero |
| 5 | 0 | `true` | Zero |

After `stable_partition()` rearranges the reversed range:

```text
Reversed range: [0, 0, 12, 3, 1]
```

When viewed in the original direction, the final array becomes:

```text
[1, 3, 12, 0, 0]
```

### Complete Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(
            nums.rbegin(),
            nums.rend(),
            logical_not<int>()
        );
    }
};
```

**Time Complexity:** `O(n)` 

**Auxiliary Space:** `O(n)` 

---

## 6. Snowball Technique — In-Place Shifting

**Approach:** Maintain a variable `snowBallSize` that counts the number of zeroes encountered so far. When a non-zero element appears after those zeroes, move it backward by the number of accumulated zeroes

Then, run a loop with `i` from `0` to `n - 1`. The pointer `i` checks every element of the array one by one.

- If `nums[i] == 0`, increment `snowBallSize` because we have encountered another zero.
- If `nums[i] != 0` and `snowBallSize > 0`, store the current element in `t`.
- Set `nums[i] = 0` to place a zero at the current position.
- Move the saved element to `nums[i - snowBallSize]`, shifting it left past the accumulated zeroes.
- The loop then increments `i` and continues checking the next element.

We continue this process until `i` reaches the end of the array. In this way, all non-zero elements are moved to the beginning while maintaining their original relative order, and all zeroes are pushed to the end.

Initially, `snowBallSize = 0` and `i = 0`.

| Step | `i` | `nums[i]` | `snowBallSize` | Action | Array after action |
|---:|---:|---:|---:|---|---|
| 1 | 0 | 0 | 1 | Count the zero | `[0, 1, 0, 3, 12]` |
| 2 | 1 | 1 | 1 | Move `1` to index `1 - 1 = 0` | `[1, 0, 0, 3, 12]` |
| 3 | 2 | 0 | 2 | Count the zero | `[1, 0, 0, 3, 12]` |
| 4 | 3 | 3 | 2 | Move `3` to index `3 - 2 = 1` | `[1, 3, 0, 0, 12]` |
| 5 | 4 | 12 | 2 | Move `12` to index `4 - 2 = 2` | `[1, 3, 12, 0, 0]` |
### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int snowBallSize = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                snowBallSize++;
            }
            else if (snowBallSize > 0) {
                int t = nums[i];
                nums[i] = 0;
                nums[i - snowBallSize] = t;
            }
        }
    }
};
```

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`

---

## 7. Two-Pass — Overwrite Non-Zero Elements

**Approach:** Traverse the array once to copy all non-zero elements to the beginning. Then traverse the remaining positions and fill them with zeroes.

**Logic:**

First, initialize `i = 0`. This pointer represents the position where the next non-zero element should be placed.

Then, run a loop with `j` from `0` to `n - 1`. The pointer `j` checks every element of the array one by one.

If `nums[j] != 0`, copy `nums[j]` to `nums[i]` and increment `i`. If `nums[j] == 0`, skip the element and continue moving `j` forward.

We continue this process until `j` reaches the end of the array. All non-zero elements are moved to the beginning while maintaining their original relative order.

Finally, use a `while` loop to fill the remaining positions with zeroes until the end of the array.

### Dry Run

**Input:**

```cpp
nums = {0, 1, 0, 3, 12};
```

**Pass 1: Copy Non-Zero Elements**

Initially, `i = 0`. The pointer `j` traverses the array and copies each non-zero element to the position pointed to by `i`.

| Step | `j` | `nums[j]` | Action | Array after action | `i` |
|---:|---:|---:|---|---|---:|
| 1 | 0 | 0 | Skip zero | `[0, 1, 0, 3, 12]` | 0 |
| 2 | 1 | 1 | Copy `1` to `nums[0]` | `[1, 1, 0, 3, 12]` | 1 |
| 3 | 2 | 0 | Skip zero | `[1, 1, 0, 3, 12]` | 1 |
| 4 | 3 | 3 | Copy `3` to `nums[1]` | `[1, 3, 0, 3, 12]` | 2 |
| 5 | 4 | 12 | Copy `12` to `nums[2]` | `[1, 3, 12, 3, 12]` | 3 |

After the first pass, all non-zero elements occupy the first three positions. The remaining positions still contain old values.

**Pass 2: Fill Remaining Positions with Zeroes**

At the end of the first pass, `i = 3`. Since the array size is `5`, the `while` loop fills indices `3` and `4` with zeroes.

| Step | `i` | Action | Array after action |
|---:|---:|---|---|
| 1 | 3 | Set `nums[3] = 0` | `[1, 3, 12, 0, 12]` |
| 2 | 4 | Set `nums[4] = 0` | `[1, 3, 12, 0, 0]` |

**Final Array:**

```text
[1, 3, 12, 0, 0]
```

### Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        // Copy all non-zero elements to the beginning
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                i++;
            }
        }

        // Fill the remaining positions with zeros
        while (i < nums.size()) {
            nums[i] = 0;
            i++;
        }
    }
};
```

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please <b>⬆️ upvote and leave a comment!</b> 💬

  <img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">