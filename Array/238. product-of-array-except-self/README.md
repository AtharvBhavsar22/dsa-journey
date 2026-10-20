# 238. Product of Array Except Self

In this post, I'll discuss different approaches to solving this problem, starting with the simplest solution and gradually optimizing it.

let's get started! 😊

## Approach Overview

| # | Approach | Time Complexity | Auxiliary Space |
|---|---|---|---|
| 0 | Total Product + Division | `O(n)` | `O(1)` |
| 1 | Brute Force | `O(n²)` | `O(1)` |
| 2 | Prefix & Suffix Arrays | `O(n)` | `O(n)` |
| 3 | Prefix Array + Running Suffix | `O(n)` | `O(n)` |
| 4 | Suffix Array + Running Prefix | `O(n)` | `O(n)` |
| 5 | Prefix & Suffix in One Loop | `O(n)` | `O(1)` |
| 6 | Prefix in Output + Running Suffix ⭐ | `O(n)` | `O(1)` |

---

## Approach 0 — Total Product + Division

The first idea that comes to mind is to calculate the product of the entire array once instead of multiplying all the elements separately for every index. Then, I can divide this total product by each element to get the product of all the remaining elements.

For example, if `nums = [1, 2, 3, 4]`, the total product is `24`. Dividing it by each element gives the answer `[24, 12, 8, 6]`.

The time complexity is `O(n)` because I traverse the array twice.

However, this approach fails if the array contains `0`, because we cannot divide by zero. Additionally, the problem explicitly states that division is not allowed.

Therefore, I need another way to calculate the products without using division.

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int product = 1;

        for (int num : nums)
            product *= num;

        for (int i = 0; i < n; i++)
            ans[i] = product / nums[i];

        return ans;
    }
};
```

---

## Approach 1 — Brute Force

The simplest approach is to loop through the complete array using an index `j` for every index `i`, multiplying all elements except when `i == j`. This ensures that I skip the current element while calculating its answer.

For example, if `nums = [1, 2, 3, 4]`, when `i = 0`, I multiply `2 × 3 × 4` to get `24`. When `i = 1`, I multiply `1 × 3 × 4` to get `12`. I repeat this for every index to build the answer array.

This approach directly follows the problem statement without using division or additional data structures. However, I traverse the array repeatedly, performing multiplications that could potentially be reused.

The time complexity is `O(n²)`, while the auxiliary space complexity is `O(1)`, excluding the output array.

To optimize this solution, I need to avoid repeating the same calculations.

**Time Complexity:** `O(n²)`

**Auxiliary Space:** `O(1)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int product = 1;

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                product *= nums[j];
            }

            ans[i] = product;
        }

        return ans;
    }
};
```

---

## Approach 2 — Prefix & Suffix Arrays

Instead of calculating the product of all other elements separately for every index, I can divide it into two parts: the product of elements to the left (**prefix**) and the product of elements to the right (**suffix**).

I can store these products in two separate arrays, `prefix` and `suffix`.

For `nums = [1, 2, 3, 4]`, the prefix array is `[1, 1, 2, 6]`, while the suffix array is `[24, 12, 4, 1]`. The first prefix and last suffix values are initialized to `1` because there are no elements before the first index or after the last index.

For every index `i`, I calculate `ans[i] = prefix[i] * suffix[i]`. Together, these products include every element except `nums[i]`.

The time complexity is `O(n)`, but the auxiliary space complexity is also `O(n)` because I use two additional arrays, excluding the output array.

Can I avoid storing both arrays and calculate the suffix product using a running variable instead?

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(n)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
};
```

---

## Approach 3 — Prefix Array + Running Suffix

In the previous approach, I stored both prefix and suffix products in separate arrays. However, I do not need to store every suffix product because I can calculate it while traversing the array from right to left.

First, I calculate the prefix array as before. Then, I initialize `suffix` to `1` and traverse the array backward.

At each index, I multiply `prefix[i]` by the current suffix product and store the result in `ans[i]`. Then, I update `suffix` by multiplying it by `nums[i]`.

For `nums = [1, 2, 3, 4]`, the prefix array is `[1, 1, 2, 6]`. At index `3`, the answer is `6 × 1 = 6`. After updating the suffix to `4`, the answer at index `2` becomes `2 × 4 = 8`. I continue until every answer is calculated.

The time complexity remains `O(n)`, while auxiliary space is `O(n)` because the prefix array is still required.

Now, I can reverse this idea by storing suffix products and calculating prefix products dynamically.

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(n)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = prefix[i] * suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
```

---

## Approach 4 — Suffix Array + Running Prefix

This approach reverses the previous one by storing suffix products and calculating prefix products dynamically.

First, I create a suffix array containing the product of all elements to the right of each index. Then, I traverse from left to right using a `prefix` variable initialized to `1`.

At every index, I multiply the current prefix product by the stored suffix product to calculate the answer. Then, I update `prefix` by multiplying it by the current element.

For `nums = [1, 2, 3, 4]`, the suffix array is `[24, 12, 4, 1]`. At index `0`, the answer is `1 × 24 = 24`. At index `1`, it becomes `1 × 12 = 12`, after which the prefix is updated to `2`.

The time complexity is `O(n)`, and the auxiliary space complexity is `O(n)` because I still need the suffix array.

Can I eliminate the extra array by calculating prefix and suffix products simultaneously?

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(n)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n, 1);
        vector<int> ans(n);

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix * suffix[i];
            prefix *= nums[i];
        }

        return ans;
    }
};
```

---

## Approach 5 — Prefix & Suffix in One Loop

Instead of storing prefix or suffix products in separate arrays, I can maintain two running variables: `prefix` and `suffix`.

I traverse the array from both ends simultaneously. During each iteration, I multiply the answer at the current left index by the prefix product and the corresponding right index by the suffix product.

For `nums = [1, 2, 3, 4]`, the first iteration processes index `0` from the left and index `3` from the right. Both contribute `1` initially, after which I update the running products and move inward.

This builds both contributions directly in the output array without additional arrays. The time complexity is `O(n)`, and auxiliary space is `O(1)`, excluding the output array.

However, processing both directions simultaneously can be slightly harder to follow. Another approach achieves the same complexity using two straightforward traversals.

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] *= prefix;
            prefix *= nums[i];

            ans[n - 1 - i] *= suffix;
            suffix *= nums[n - 1 - i];
        }

        return ans;
    }
};
```

---

## Approach 6 — Prefix in Output + Running Suffix ⭐

This is the approach I would prefer because it is efficient and easy to understand once the prefix and suffix concepts are clear.

Instead of creating a separate prefix array, I use the output array to store prefix products. I initialize `prefix` to `1` and traverse from left to right, storing the current prefix in `ans[i]` before updating it with `nums[i]`.

Next, I initialize `suffix` to `1` and traverse backward. At each index, I multiply the stored prefix product by the running suffix product to calculate the answer, then update `suffix` using the current element.

For `nums = [1, 2, 3, 4]`, the first traversal produces `[1, 1, 2, 6]`. The reverse traversal combines these prefix products with suffix products to produce `[24, 12, 8, 6]`.

The time complexity is `O(n)`, and auxiliary space is `O(1)`, excluding the output array. This approach avoids division, handles zeros naturally, and requires no separate prefix or suffix arrays.

Therefore, it achieves the required time complexity with constant auxiliary space.

**Time Complexity:** `O(n)`

**Auxiliary Space:** `O(1)`, excluding the output array.

**Below is the C++ code for this approach.**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int prefix = 1;

        for (int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};
```

---



My preferred solution is **Approach 6 — Prefix in Output + Running Suffix**, which achieves `O(n)` time and `O(1)` auxiliary space, excluding the output array, without using division.

 I hope this post helps you understand the different approaches and how to optimize a solution step by step.

**Thank you for giving your time in reading this post.** 😊

<p align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQE7T0OUmKq2v1MjWaWE0Skud6CUGncLiQHApHWLK7QeA&s=10" 
       alt="Can you please upvote? Please!" 
       width="300">
</p>

