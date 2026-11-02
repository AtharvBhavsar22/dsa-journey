# 12. Integer to Roman

**LeetCode:** [12. Integer to Roman](https://leetcode.com/problems/integer-to-roman/)  
**Difficulty:** Medium  
**Topics:** Hash Table, Math, String

---

Explored multiple approaches, from place-value mapping to greedy solutions, along with alternative LeetCode solutions.

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

- `III` = 1 + 1 + 1 = 3
- `VI` = 5 + 1 = 6
- `XII` = 10 + 1 + 1 = 12
- `LVIII` = 50 + 5 + 1 + 1 + 1 = 58

### 3. Subtraction Rule

When a smaller Roman numeral appears before a larger Roman numeral, we subtract the smaller value from the larger value instead of adding them.

There are six specific combinations where subtraction is used:

| Combination | Calculation | Result |
|:---:|:---:|---:|
| IV | 5 - 1 | 4 |
| IX | 10 - 1 | 9 |
| XL | 50 - 10 | 40 |
| XC | 100 - 10 | 90 |
| CD | 500 - 100 | 400 |
| CM | 1000 - 100 | 900 |

### 4. Decimal Place Values

Every integer can be divided into four decimal places:

- Thousands
- Hundreds
- Tens
- Units

For example, `1994` can be broken down as:

| Decimal Place | Digit | Value |
|:---:|---:|---:|
| Thousands | 1 | 1000 |
| Hundreds | 9 | 900 |
| Tens | 9 | 90 |
| Units | 4 | 4 |

Therefore:

`1994 = 1000 + 900 + 90 + 4`

Its Roman representation is:

`M + CM + XC + IV = MCMXCIV`

### 5. Problem Statement

Given an integer `num`, convert it into its corresponding Roman numeral.

**Examples:**

| Input | Output |
|:---:|:---:|
| `num = 3749` | `"MMMDCCXLIX"` |
| `num = 58` | `"LVIII"` |
| `num = 1994` | `"MCMXCIV"` |

### 6. Constraints

- `1 <= num <= 3999`

---

## 1. Hash Map – Place Value Mapping

**Approach:**

First, store the Roman numeral representations of all possible non-zero place values in an `unordered_map`, using their integer values as keys and Roman numeral strings as values.

Initialize an array of divisors containing `1000`, `100`, `10`, and `1` to process each decimal place from thousands to units.

Initialize an `ans` string to maintain the final Roman numeral.

Then, traverse the divisors array.

- Divide `num` by the current divisor to extract the digit at that decimal place.
- Multiply the extracted digit by the divisor to obtain its actual place value.
- If the place value is not zero, retrieve its corresponding Roman representation from the map and append it to `ans`.
- Update `num` using the modulo operator to remove the already processed decimal place.

Continue until all four decimal places have been processed. Finally, return `ans`.

### Code

```cpp
class Solution {
public:
    string intToRoman(int num) {

        // Step 1: Store Roman representations for each place value
        unordered_map<int, string> roman = {
            // Thousands
            {1000, "M"}, {2000, "MM"}, {3000, "MMM"},

            // Hundreds
            {100, "C"}, {200, "CC"}, {300, "CCC"},
            {400, "CD"}, {500, "D"}, {600, "DC"},
            {700, "DCC"}, {800, "DCCC"}, {900, "CM"},

            // Tens
            {10, "X"}, {20, "XX"}, {30, "XXX"},
            {40, "XL"}, {50, "L"}, {60, "LX"},
            {70, "LXX"}, {80, "LXXX"}, {90, "XC"},

            // Units
            {1, "I"}, {2, "II"}, {3, "III"},
            {4, "IV"}, {5, "V"}, {6, "VI"},
            {7, "VII"}, {8, "VIII"}, {9, "IX"}
        };

        // Step 2: Store divisors for each decimal place
        int divisors[] = {1000, 100, 10, 1};

        // Step 3: Initialize the answer string
        string ans = "";

        // Step 4: Process each decimal place
        for (int i = 0; i < 4; i++) {

            int digit = num / divisors[i];

            int value = digit * divisors[i];

            // Step 5: Append the corresponding Roman representation
            if (value != 0) {
                ans += roman[value];
            }

            // Step 6: Remove the processed decimal place
            num %= divisors[i];
        }

        // Step 7: Return the final Roman numeral
        return ans;
    }
};
```

### Dry Run

**Input:** `num = 1994`

| Step | Divisor | Digit | Place Value | Roman Value | Answer |
|---:|---:|---:|---:|:---:|:---|
| 1 | 1000 | 1 | 1000 | M | M |
| 2 | 100 | 9 | 900 | CM | MCM |
| 3 | 10 | 9 | 90 | XC | MCMXC |
| 4 | 1 | 4 | 4 | IV | MCMXCIV |

**Output:** `MCMXCIV`

**Time Complexity:** `O(1)`

**Space Complexity:** `O(1)`

---

## 2. Array – Digit-by-Digit Mapping

**Approach:**

First, create four string arrays to store the Roman numeral representations for each decimal place: `ones`, `tens`, `hundreds`, and `thousands`.

Each array stores the Roman representation of digits from `0` to `9` (the thousands array stores values from `0` to `3`).

Initialize an `ans` string by extracting each decimal place from `num` and retrieving its corresponding Roman representation.

- `thousands[num / 1000]` retrieves the thousands representation.
- `hundreds[(num % 1000) / 100]` retrieves the hundreds representation.
- `tens[(num % 100) / 10]` retrieves the tens representation.
- `ones[num % 10]` retrieves the units representation.

Concatenate all four representations to obtain the final Roman numeral. Finally, return `ans`.

### Code

```cpp
class Solution {
public:
    string intToRoman(int num) {

        // Step 1: Store Roman representations for each decimal place
        string ones[] = {
            "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
        };

        string tens[] = {
            "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"
        };

        string hundreds[] = {
            "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"
        };

        string thousands[] = {
            "", "M", "MM", "MMM"
        };

        // Step 2: Extract each decimal place and concatenate its Roman value
        string ans = thousands[num / 1000]
                   + hundreds[(num % 1000) / 100]
                   + tens[(num % 100) / 10]
                   + ones[num % 10];

        // Step 3: Return the final Roman numeral
        return ans;
    }
};
```

### Dry Run

**Input:** `num = 1994`

| Decimal Place | Calculation | Array Lookup | Roman Value |
|:---:|:---:|:---:|:---:|
| Thousands | 1994 / 1000 = 1 | `thousands[1]` | M |
| Hundreds | (1994 % 1000) / 100 = 9 | `hundreds[9]` | CM |
| Tens | (1994 % 100) / 10 = 9 | `tens[9]` | XC |
| Units | 1994 % 10 = 4 | `ones[4]` | IV |

Concatenating the values:

`M + CM + XC + IV = MCMXCIV`

**Output:** `MCMXCIV`

**Time Complexity:** `O(1)` 

**Space Complexity:** `O(1)` 

---

## 3. Greedy – Largest Value First

**Approach:**

First, store the integer values and their corresponding Roman numeral representations in a vector of pairs, arranged in descending order.

Initialize an `ans` string to maintain the final Roman numeral.

Then, traverse the vector from largest to smallest.

At each position:

- Check whether the current integer value is less than or equal to `num`.
- If it is, append the corresponding Roman numeral to `ans`.
- Subtract the current integer value from `num`.
- Repeat this process while the current value can still be used.
- Move to the next smaller value when it no longer fits.

Continue until all Roman numeral values have been processed. Finally, return `ans`.

### Code

```cpp
class Solution {
public:
    string intToRoman(int num) {

        // Step 1: Store Roman values in descending order
        vector<pair<int, string>> storeIntRoman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string ans = "";

        // Step 2: Traverse through the values from largest to smallest
        for (auto it = storeIntRoman.begin(); it != storeIntRoman.end(); it++) {

            // Step 3: Use the current Roman value while it fits
            while (num >= it->first) {

                ans += it->second;

                num -= it->first;
            }
        }

        // Step 4: Return the final Roman numeral
        return ans;
    }
};
```

### Dry Run

**Input:** `num = 1994`

| Step | Roman Value | Integer Value | Remaining num | Answer |
|---:|:---:|---:|---:|:---|
| 1 | M | 1000 | 994 | M |
| 2 | CM | 900 | 94 | MCM |
| 3 | XC | 90 | 4 | MCMXC |
| 4 | IV | 4 | 0 | MCMXCIV |

The remaining Roman values are skipped because they are greater than the remaining `num`.

**Output:** `MCMXCIV`

**Time Complexity:** `O(1)`

**Space Complexity:** `O(1)`

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400" />
