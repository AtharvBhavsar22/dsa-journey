# 13. Roman to Integer

**LeetCode:** [13. Roman to Integer](https://leetcode.com/problems/roman-to-integer/)  
**Difficulty:** Easy  
**Topics:** String, Hash Table

---

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## Problem Understanding

Roman numerals are represented using seven different symbols, each having a specific integer value.

### 1. Roman Numeral Symbols and Values

| Symbol | Integer Value |
|:---:|---:|
| I | 1 |
| V | 5 |
| X | 10 |
| L | 50 |
| C | 100 |
| D | 500 |
| M | 1000 |

### 2. Addition Rule

Roman numerals are usually written from largest to smallest, from left to right. When a smaller or equal value appears after a larger value, we add their values to obtain the final integer.

**Examples:**

- `II` = 1 + 1 = 2
- `XII` = 10 + 1 + 1 = 12
- `XXVII` = 10 + 10 + 5 + 1 + 1 = 27
- `LVIII` = 50 + 5 + 1 + 1 + 1 = 58

### 3. Subtraction Rule

However, there are some exceptions where a smaller Roman numeral appears before a larger Roman numeral. In these cases, we subtract the smaller value from the larger value instead of adding them.

For example, 4 is not written as `IIII`. Instead, it is written as `IV`, where 1 comes before 5, so we subtract 1 from 5 to get 4.

Similarly, 9 is written as `IX`, where 1 is subtracted from 10.

There are six specific combinations where subtraction is used:

| Smaller Symbol | Larger Symbol | Combination | Calculation | Result |
|:---:|:---:|:---:|:---:|---:|
| I | V | IV | 5 - 1 | 4 |
| I | X | IX | 10 - 1 | 9 |
| X | L | XL | 50 - 10 | 40 |
| X | C | XC | 100 - 10 | 90 |
| C | D | CD | 500 - 100 | 400 |
| C | M | CM | 1000 - 100 | 900 |


---

## 1. Left to Right – Subtract Current

**Approach:**

First, store all seven Roman numeral symbols and their corresponding integer values in an `unordered_map`.

Initialize an `ans` variable to maintain the final integer value. Then, traverse the Roman numeral string from left to right.

At each position, compare the current Roman numeral's value with the next Roman numeral's value.

- If the current value is smaller than the next value, subtract the current value from `ans`.
- Otherwise, add the current value to `ans`.

Continue this process until the entire string is traversed. Finally, return `ans`.



### Code

```cpp
class Solution {
public:
    int romanToInt(string s) {

        // Step 1: Store Roman numeral symbols and their corresponding integer values
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Step 2: Initialize a variable to maintain the final integer value
        int ans = 0;

        // Step 3: Traverse the string from left to right
        for (int i = 0; i < s.length(); i++) {

            // Step 4: Compare the current character with the next character
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {

                // Subtract the current value if it is smaller than the next value
                ans -= roman[s[i]];
            }
            else {

                // Add the current value otherwise
                ans += roman[s[i]];
            }
        }

        // Step 5: Return the final integer value
        return ans;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1)`

---

## 2. Right to Left – Previous Value

**Approach:**

First, store all seven Roman numeral symbols and their corresponding integer values in an `unordered_map`.

Initialize an `ans` variable to maintain the final integer value and a `prev` variable with `0` to store the value of the previously processed Roman numeral.

Then, traverse the Roman numeral string from right to left.

At each position, retrieve the current Roman numeral's integer value and compare it with the `prev` value.

- If the current value is smaller than the previous value, subtract the current value from `ans`.
- Otherwise, add the current value to `ans`.

After processing each character, update `prev` with the current value so that it can be used for comparison in the next iteration.

Continue this process until the entire string is traversed. Finally, return `ans`.

### Code

```cpp
class Solution {
public:
    int romanToInt(string s) {

        // Step 1: Store Roman numeral symbols and their corresponding integer values
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Step 2: Initialize variables to maintain the answer and previous value
        int ans = 0;
        int prev = 0;

        // Step 3: Traverse the string from right to left
        for (int i = s.length() - 1; i >= 0; i--) {

            // Step 4: Get the integer value of the current Roman numeral
            int curr = roman[s[i]];

            // Step 5: Subtract if the current value is smaller than the previous value
            if (curr < prev) {
                ans -= curr;
            }
            else {
                ans += curr;
            }

            // Step 6: Update the previous value
            prev = curr;
        }

        // Step 7: Return the final integer value
        return ans;
    }
};
```

**Time Complexity:** `O(n)`

**Space Complexity:** `O(1) `

---

## 3. Left to Right – Pair Processing

**Approach:**

First, store all seven Roman numeral symbols and their corresponding integer values in an `unordered_map`.

Initialize an `ans` variable to maintain the final integer value. Then, traverse the Roman numeral string from left to right.

At each position, compare the current Roman numeral's value with the next Roman numeral's value to check whether they form a subtraction pair.

- If the current value is smaller than the next value, subtract the current value from the next value and add their difference directly to `ans`.
- After processing the pair, increment `i` to skip the next character because it has already been included in the calculation.
- Otherwise, add the current value directly to `ans`.

Continue this process until the entire string is traversed. Finally, return `ans`.

### Code

```cpp
class Solution {
public:
    int romanToInt(string s) {

        // Step 1: Store Roman numeral symbols and their corresponding integer values
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        // Step 2: Initialize the answer variable
        int ans = 0;

        // Step 3: Traverse the string from left to right
        for (int i = 0; i < s.length(); i++) {

            // Step 4: Check whether the current and next characters form a subtraction pair
            if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {

                // Subtract the current value from the next value
                ans += roman[s[i + 1]] - roman[s[i]];

                // Skip the next character because it has already been processed
                i++;
            }
            else {

                // Add the current value otherwise
                ans += roman[s[i]];
            }
        }

        // Step 5: Return the final integer value
        return ans;
    }
};
```


**Time Complexity:** `O(n)`

**Space Complexity:** `O(1) `

---


Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">

