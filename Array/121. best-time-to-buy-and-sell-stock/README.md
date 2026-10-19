# LeetCode 121 — Best Time to Buy and Sell Stock

**A collection of C++ solutions, progressing from brute force to optimized greedy and Kadane's algorithm.**

<p align="center">
  <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">
    <img src="https://img.shields.io/badge/LeetCode-121%20Best%20Time%20to%20Buy%20and%20Sell%20Stock-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 121" />
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge" alt="Difficulty: Easy" />
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="Language: C++" />
  <img src="https://img.shields.io/badge/Topic-Arrays%20%7C%20Greedy-7C3AED?style=for-the-badge" alt="Topics: Arrays and Greedy" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Optimal%20Time-O(n)-orange?style=for-the-badge" alt="Optimal Time: O(n)" />
  <img src="https://img.shields.io/badge/Auxiliary%20Space-O(1)-blue?style=for-the-badge" alt="Auxiliary Space: O(1)" />
</p>

---

## Table of Contents

- [Problem Statement](#problem-statement)
- [Examples](#examples)
- [Constraints](#constraints)
- [Understanding the Problem](#understanding-the-problem)
- [Solution Overview](#solution-overview)
- [Approach 1: Brute Force](#approach-1--brute-force)
- [Approach 2: max_element()](#approach-2--max_element)
- [Approach 3: Suffix Maximum Array](#approach-3--suffix-maximum-array)
- [Approach 4: Prefix Minimum Array](#approach-4--prefix-minimum-array)
- [Approach 5: Greedy — Track Minimum Price](#approach-5--greedy-track-minimum-price)
- [Approach 6: Kadane's Algorithm](#approach-6--kadanes-algorithm)
- [Complexity Comparison](#complexity-comparison)

- [Final Takeaway](#final-takeaway)

---

## Problem Statement

You are given an array `prices`, where `prices[i]` represents the stock price on day `i`.

Choose one day to buy a stock and a different day in the future to sell it. Return the maximum profit possible. If no profitable transaction is possible, return `0`.

**Profit Formula:**

```text
Profit = Selling Price - Buying Price
```

The buying day must always come before the selling day.

## Examples

### Example 1

**Input:**

```text
prices = [7, 1, 5, 3, 6, 4]
```

**Output:**

```text
5
```

**Explanation:** Buy at price `1` and sell later at price `6`.

```text
Profit = 6 - 1 = 5
```

### Example 2

**Input:**

```text
prices = [7, 6, 4, 3, 1]
```

**Output:**

```text
0
```

**Explanation:** Prices keep decreasing, so no profitable transaction is possible.

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

**What the constraints tell us:**

- The array can contain up to `100,000` prices, making an `O(n²)` approach inefficient for large inputs.
- Each price is between `0` and `10,000`.
- We must buy before selling.
- If every possible transaction results in a loss, the answer must remain `0`.

---

## Understanding the Problem

My goal is to find the best buying and selling combination while ensuring that the buying day comes first.

For the input:

```text
prices = [7, 1, 5, 3, 6, 4]
```

| Day (Index) | Stock Price |
|---:|---:|
| 0 | 7 |
| 1 | 1 |
| 2 | 5 |
| 3 | 3 |
| 4 | 6 |
| 5 | 4 |

The best transaction is:

- **Buying day:** Index `1`, price `1`.
- **Selling day:** Index `4`, price `6`.
- **Maximum profit:** `6 - 1 = 5`.

The challenge is to find this profit without checking every possible pair unnecessarily.

---

## Solution Overview

| No. | Approach | Time Complexity | Auxiliary Space |
|---:|---|---|---|
| 1 | Brute Force | `O(n²)` | `O(1)` |
| 2 | `max_element()` | `O(n²)` | `O(1)` |
| 3 | Suffix Maximum Array | `O(n)` | `O(n)` |
| 4 | Prefix Minimum Array | `O(n)` | `O(n)` |
| 5 | Greedy — Minimum Price | `O(n)` | `O(1)` |
| 6 | Kadane's Algorithm | `O(n)` | `O(1)` |

---

## Approach 1 — Brute Force

**Time Complexity:** `O(n²)`  
**Auxiliary Space:** `O(1)`

### 1.1 Initial Intuition

My first thought is to check every possible combination of buying and selling days.

For each buying day `i`, I check every later selling day `j`. I calculate the profit and keep the maximum value found. I initialize `profit = 0` because the answer should never be negative.

### 1.2 My Approach

1. Store the array length in `n` and initialize `profit = 0`.
2. Use an outer loop to select each possible buying day.
3. Use an inner loop to examine every later selling day.
4. Calculate `currentProfit = prices[j] - prices[i]`.
5. Update `profit` if `currentProfit` is greater.
6. Return `profit` after checking every valid pair.

### 1.3 C++ Implementation

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int currentProfit = prices[j] - prices[i];

                if (currentProfit > profit) {
                    profit = currentProfit;
                }
            }
        }

        return profit;
    }
};
```

### 1.4 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

| Buying Price | Selling Price | Current Profit | Maximum Profit |
|---:|---:|---:|---:|
| 7 | 1 | -6 | 0 |
| 7 | 5 | -2 | 0 |
| 7 | 6 | -1 | 0 |
| 1 | 5 | 4 | 4 |
| 1 | 6 | 5 | 5 |
| 5 | 6 | 1 | 5 |
| 3 | 6 | 3 | 5 |
| 6 | 4 | -2 | 5 |

The algorithm checks every valid buying-and-selling pair. The best transaction is buying at `1` and selling at `6`.

**Final Answer:** `5`

### 1.5 Complexity Analysis

#### ⏱️ Time Complexity: `O(n²)`

The total number of valid buying-and-selling pairs is:

```text
(n - 1) + (n - 2) + ... + 1 = n * (n - 1) / 2
```

- The outer loop selects each possible buying day.
- The inner loop checks every day after the buying day as a selling day.
- The number of pairs grows quadratically with the array size.

For `n = 100,000`, the algorithm checks `4,999,950,000` pairs in the worst case.

Therefore, the overall time complexity is **`O(n²)`**.

#### 💾 Auxiliary Space: `O(1)`

- The algorithm uses a constant number of variables to store the array length, loop indices, current profit, and maximum profit.
- No additional array or data structure is created.

Therefore, the auxiliary space complexity is **`O(1)`**.

### 1.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Outer loop | `O(n)` iterations | `O(1)` |
| Inner loop | `O(n)` per outer iteration | `O(1)` |
| Overall algorithm | `O(n²)` | `O(1)` auxiliary |

---

## Approach 2 — `max_element()`

**Time Complexity:** `O(n²)`  
**Auxiliary Space:** `O(1)`

### 2.1 Initial Intuition

Instead of calculating the profit for every possible pair, I can find the maximum future selling price for each buying day.

For example, if I buy at `1`, the future prices are `[5, 3, 6, 4]`. The maximum future price is `6`, giving a profit of `5`.

### 2.2 My Approach

1. Initialize `profit = 0`.
2. Select each possible buying day using an outer loop.
3. Use `max_element()` to find the highest price after the buying day.
4. Calculate the profit using that maximum future price.
5. Update the maximum profit.
6. Return the final answer.

### 2.3 Understanding `max_element()`

The C++ STL function `max_element()` is available in the `<algorithm>` header. It returns an iterator pointing to the largest element in the specified range.

```cpp
int maxPrice = *max_element(
    prices.begin() + i + 1,
    prices.end()
);
```

- `prices.begin() + i + 1` starts the search after the buying day.
- `prices.end()` marks the end of the range.
- `*` dereferences the iterator to obtain the actual price.

### 2.4 C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;

        for (int i = 0; i < n - 1; i++) {
            int maxPrice = *max_element(
                prices.begin() + i + 1,
                prices.end()
            );

            int currentProfit = maxPrice - prices[i];

            if (currentProfit > profit) {
                profit = currentProfit;
            }
        }

        return profit;
    }
};
```

### 2.5 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

| Buying Index | Buying Price | Future Prices | Maximum Future Price | Current Profit | Maximum Profit |
|---:|---:|---|---:|---:|---:|
| 0 | 7 | `[1, 5, 3, 6, 4]` | 6 | -1 | 0 |
| 1 | 1 | `[5, 3, 6, 4]` | 6 | 5 | 5 |
| 2 | 5 | `[3, 6, 4]` | 6 | 1 | 5 |
| 3 | 3 | `[6, 4]` | 6 | 3 | 5 |
| 4 | 6 | `[4]` | 4 | -2 | 5 |

**Final Answer:** `5`

### 2.6 Complexity Analysis

#### ⏱️ Time Complexity: `O(n²)`

- The outer loop considers each possible buying day.
- For every buying day, `max_element()` scans the remaining prices to find the maximum selling price.
- The total number of scanned elements grows quadratically.

Therefore, the overall time complexity is **`O(n²)`**.

#### 💾 Auxiliary Space: `O(1)`

- `max_element()` operates on the existing vector.
- The algorithm uses only a constant number of additional variables.
- No additional array is created.

Therefore, the auxiliary space complexity is **`O(1)`**.

### 2.7 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Outer loop | `O(n)` iterations | `O(1)` |
| `max_element()` | `O(n)` per call | `O(1)` auxiliary |
| Overall algorithm | `O(n²)` | `O(1)` auxiliary |

---

## Approach 3 — Suffix Maximum Array

**Time Complexity:** `O(n)`  
**Auxiliary Space:** `O(n)`

### 3.1 Initial Intuition

Approach 2 repeatedly searches the future prices. I can avoid this by calculating and storing the maximum price from each index to the end of the array.

This is called a **suffix maximum array**.

For each buying day, the suffix maximum tells me the highest price available from that index onward. I must still ensure that the selling day comes after the buying day.

### 3.2 My Approach

1. Create a `suffixMax` array of size `n`.
2. Set the last suffix maximum to the last stock price.
3. Traverse the prices from right to left.
4. At each index, store the maximum of the current price and the next suffix maximum.
5. For each buying day, calculate the profit using the maximum price strictly after that day.
6. Update and return the maximum profit.

### 3.3 C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> suffixMax(n);

        suffixMax[n - 1] = prices[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(prices[i], suffixMax[i + 1]);
        }

        int profit = 0;

        for (int i = 0; i < n - 1; i++) {
            int currentProfit = suffixMax[i + 1] - prices[i];

            if (currentProfit > profit) {
                profit = currentProfit;
            }
        }

        return profit;
    }
};
```

### 3.4 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

The suffix maximum array is built from right to left.

| Index | Price | Suffix Maximum |
|---:|---:|---:|
| 5 | 4 | 4 |
| 4 | 6 | 6 |
| 3 | 3 | 6 |
| 2 | 5 | 6 |
| 1 | 1 | 6 |
| 0 | 7 | 7 |

Result: `suffixMax = [7, 6, 6, 6, 6, 4]`

Now calculate the best profit for each buying day:

| Buying Index | Buying Price | Maximum Future Price | Profit |
|---:|---:|---:|---:|
| 0 | 7 | 6 | -1 |
| 1 | 1 | 6 | 5 |
| 2 | 5 | 6 | 1 |
| 3 | 3 | 6 | 3 |
| 4 | 6 | 4 | -2 |

**Final Answer:** `5`

### 3.5 Complexity Analysis

#### ⏱️ Time Complexity: `O(n)`

- The first loop builds the suffix maximum array in `O(n)` time.
- The second loop calculates the maximum possible profit in `O(n)` time.
- Each element is processed a constant number of times.

Therefore, the overall time complexity is **`O(n)`**.

#### 💾 Auxiliary Space: `O(n)`

- The suffix maximum array stores the maximum price from each index to the end.
- It contains `n` elements and requires `O(n)` additional space.

Therefore, the auxiliary space complexity is **`O(n)`**.

### 3.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Build suffix maximum array | `O(n)` | `O(n)` |
| Calculate maximum profit | `O(n)` | `O(1)` auxiliary |
| Overall algorithm | `O(n)` | `O(n)` auxiliary |

---

## Approach 4 — Prefix Minimum Array

**Time Complexity:** `O(n)`  
**Auxiliary Space:** `O(n)`

### 4.1 Initial Intuition

Instead of looking forward to find the best selling price, I can look backward at the prices already encountered.

For each day, I store the minimum stock price seen from the beginning up to that day. When considering a selling day, the prefix minimum tells me the lowest price available before it.

### 4.2 My Approach

1. Create a `prefixMin` array of size `n`.
2. Store the first price in `prefixMin[0]`.
3. Traverse from left to right, storing the minimum of the current price and the previous prefix minimum.
4. For each selling day, calculate profit using the minimum price before that day.
5. Update the maximum profit and return it.

### 4.3 C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n);

        prefixMin[0] = prices[0];

        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prices[i], prefixMin[i - 1]);
        }

        int profit = 0;

        for (int i = 1; i < n; i++) {
            int currentProfit = prices[i] - prefixMin[i - 1];

            if (currentProfit > profit) {
                profit = currentProfit;
            }
        }

        return profit;
    }
};
```

### 4.4 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

| Index | Price | Prefix Minimum |
|---:|---:|---:|
| 0 | 7 | 7 |
| 1 | 1 | 1 |
| 2 | 5 | 1 |
| 3 | 3 | 1 |
| 4 | 6 | 1 |
| 5 | 4 | 1 |

Now calculate profit for each selling day using the minimum price before it.

| Selling Index | Selling Price | Minimum Earlier Price | Profit |
|---:|---:|---:|---:|
| 1 | 1 | 7 | -6 |
| 2 | 5 | 1 | 4 |
| 3 | 3 | 1 | 2 |
| 4 | 6 | 1 | 5 |
| 5 | 4 | 1 | 3 |

**Final Answer:** `5`

### 4.5 Complexity Analysis

#### ⏱️ Time Complexity: `O(n)`

- The first loop builds the prefix minimum array in `O(n)` time.
- The second loop calculates the profit for each possible selling day in `O(n)` time.
- Each element is processed a constant number of times.

Therefore, the overall time complexity is **`O(n)`**.

#### 💾 Auxiliary Space: `O(n)`

- The prefix minimum array stores the minimum price encountered from the beginning up to each index.
- It contains `n` elements and requires `O(n)` additional space.

Therefore, the auxiliary space complexity is **`O(n)`**.

### 4.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Build prefix minimum array | `O(n)` | `O(n)` |
| Calculate maximum profit | `O(n)` | `O(1)` auxiliary |
| Overall algorithm | `O(n)` | `O(n)` auxiliary |

---

## Approach 5 — Greedy: Track Minimum Price

**Time Complexity:** `O(n)`  
**Auxiliary Space:** `O(1)`

### 5.1 Initial Intuition

Approaches 3 and 4 use extra arrays to store information. However, I only need two pieces of information at any moment:

- The minimum stock price seen so far.
- The maximum profit found so far.

As I traverse the array, I treat the current price as a potential selling price. I calculate the profit using the minimum earlier price and update the answer if the profit is higher.

### 5.2 My Approach

1. Initialize `minPrice` with the first stock price.
2. Initialize `maxProfit = 0`.
3. Traverse the array from the second day onward.
4. Calculate the profit from selling at the current price: `prices[i] - minPrice`.
5. Update `maxProfit` if the current profit is greater.
6. Update `minPrice` if the current price is lower.
7. Return `maxProfit`.

### 5.3 C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int currentProfit = prices[i] - minPrice;

            maxProfit = max(maxProfit, currentProfit);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};
```

### 5.4 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

| Day | Price | Minimum Price Before/At Day | Current Profit | Maximum Profit |
|---:|---:|---:|---:|---:|
| 0 | 7 | 7 | — | 0 |
| 1 | 1 | 1 | -6 | 0 |
| 2 | 5 | 1 | 4 | 4 |
| 3 | 3 | 1 | 2 | 4 |
| 4 | 6 | 1 | 5 | 5 |
| 5 | 4 | 1 | 3 | 5 |

**Final Answer:** `5`

### 5.5 Complexity Analysis

#### ⏱️ Time Complexity: `O(n)`

- The algorithm traverses the prices array once.
- At each iteration, it updates the minimum buying price and calculates the possible profit.
- Each iteration performs constant-time operations.

Therefore, the overall time complexity is **`O(n)`**.

#### 💾 Auxiliary Space: `O(1)`

- The algorithm uses only a constant number of variables to track the minimum price and maximum profit.
- No additional array or data structure is created.

Therefore, the auxiliary space complexity is **`O(1)`**.

### 5.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Traverse prices array | `O(n)` | `O(1)` |
| Update minimum price | `O(1)` per iteration | `O(1)` |
| Calculate maximum profit | `O(1)` per iteration | `O(1)` |
| Overall algorithm | `O(n)` | `O(1)` auxiliary |

### 5.7 Why Is This Greedy?

At each day, the algorithm uses the lowest price seen previously as the best buying candidate and checks whether selling today produces a better profit.

It does not need to remember every previous price because the minimum price is sufficient to calculate the best profit for the current selling day.

---

## Approach 6 — Kadane's Algorithm

**Time Complexity:** `O(n)`  
**Auxiliary Space:** `O(1)`

### 6.1 Initial Intuition

The stock problem can also be represented as an array of consecutive price differences.

For example:

```text
Prices:       [7, 1, 5, 3, 6, 4]
Differences:    -6, 4, -2, 3, -2
```

A buying-and-selling transaction corresponds to the sum of consecutive price differences between the buying and selling days.

Therefore, the maximum stock profit is equivalent to finding the maximum subarray sum of the difference array. Kadane's algorithm solves this efficiently.

### 6.2 My Approach

1. Initialize `currentSum = 0` and `maxProfit = 0`.
2. Traverse the prices starting from index `1`.
3. Calculate the daily difference: `prices[i] - prices[i - 1]`.
4. Add the difference to `currentSum`.
5. Reset `currentSum` to `0` if it becomes negative.
6. Update `maxProfit` with the largest `currentSum`.
7. Return `maxProfit`.

### 6.3 C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentSum = 0;
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int difference = prices[i] - prices[i - 1];

            currentSum = max(0, currentSum + difference);
            maxProfit = max(maxProfit, currentSum);
        }

        return maxProfit;
    }
};
```

### 6.4 Dry Run

Input: `prices = [7, 1, 5, 3, 6, 4]`

Differences: `[-6, 4, -2, 3, -2]`

| Difference | Current Sum | Maximum Profit |
|---:|---:|---:|
| -6 | 0 | 0 |
| 4 | 4 | 4 |
| -2 | 2 | 4 |
| 3 | 5 | 5 |
| -2 | 3 | 5 |

**Final Answer:** `5`

The maximum contiguous sum is `4 + (-2) + 3 = 5`, which represents buying at `1` and selling at `6`.

### 6.5 Complexity Analysis

#### ⏱️ Time Complexity: `O(n)`

- The algorithm traverses the prices array once, starting from the second element.
- At each iteration, it calculates the price difference and updates the current sum and maximum profit.
- Each iteration performs constant-time operations.

Therefore, the overall time complexity is **`O(n)`**.

#### 💾 Auxiliary Space: `O(1)`

- The algorithm uses only a constant number of variables to track the current sum, maximum profit, and price difference.
- No separate difference array is created.

Therefore, the auxiliary space complexity is **`O(1)`**.

### 6.6 Complexity Summary

| Operation | Time Complexity | Space |
|---|---|---|
| Calculate price difference | `O(1)` per iteration | `O(1)` |
| Update current sum | `O(1)` per iteration | `O(1)` |
| Update maximum profit | `O(1)` per iteration | `O(1)` |
| Overall algorithm | `O(n)` | `O(1)` auxiliary |

---

## Complexity Comparison

| No. | Approach | Main Idea | Time Complexity | Auxiliary Space |
|---:|---|---|---|---|
| 1 | Brute Force | Check every valid buying-selling pair. | `O(n²)` | `O(1)` |
| 2 | `max_element()` | Find the maximum future price for each buying day. | `O(n²)` | `O(1)` |
| 3 | Suffix Maximum Array | Precompute the maximum future price at every index. | `O(n)` | `O(n)` |
| 4 | Prefix Minimum Array | Precompute the minimum earlier price at every index. | `O(n)` | `O(n)` |
| 5 | Greedy — Minimum Price | Track the minimum price and maximum profit in one pass. | `O(n)` | `O(1)` |
| 6 | Kadane's Algorithm | Find the maximum subarray sum of price differences. | `O(n)` | `O(1)` |

---

## Final Takeaway

The **Kadane's Algorithm** approach is the best choice in this collection because it achieves **`O(n)` time complexity and `O(1)` auxiliary space**, providing optimal time and memory efficiency.

It calculates the maximum profit in a single traversal without creating any additional array, making it an efficient solution for this problem.

---


<p align="center">
  <a href="https://leetcode.com/problems/best-time-to-buy-and-sell-stock/">
    <img src="https://img.shields.io/badge/LeetCode-121%20Best%20Time%20to%20Buy%20and%20Sell%20Stock-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode 121: Best Time to Buy and Sell Stock" />
  </a>
</p>

<p align="center">
  <b>🚀 Keep Practising. Understand the Logic. Optimize Your Code.</b>
</p>

<p align="center">
  Every problem has a story. Every solution has a different approach.
</p>

<p align="center">
  <i>Thanks for watching… I mean, reading. 🍿</i>
</p>

<p align="center">
  <b>Until the next problem, keep debugging your plot. 🎥💻</b>
</p>

<p align="center">
  <strong>𝗔𝘁𝗵𝗿𝘃𝘃</strong>
</p>
<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQE7T0OUmKq2v1MjWaWE0Skud6CUGncLiQHApHWLK7QeA&s=10" 
       alt="Can you please upvote? Please!" 
       width="300">
</p>

