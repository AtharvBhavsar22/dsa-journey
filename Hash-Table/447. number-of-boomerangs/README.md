# 447. Number of Boomerangs

**LeetCode Problem:** [Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/)  
**Difficulty:** Medium  
**Topics:** Array, Hash Table, Math, Geometry

Explored multiple approaches, from brute force to optimized solutions, along with alternative LeetCode solutions.

Kept everything short and simple. Have a look, learn along, and give it a try yourself!

---

## Understanding the Problem

A **boomerang** consists of three different points `(i, j, k)` where the distance between `i` and `j` must be equal to the distance between `i` and `k`.

Here, `i` is the **reference point**, and `j` and `k` are the other two points that must be equally distant from it.

For example, consider these three points:

```text
        B (2, 0)

A (0, 0)       C (0, 2)
```

If we select A as the reference point:

- Distance between A and B = 2
- Distance between A and C = 2

Both distances are equal, so `(A, B, C)` is a valid boomerang.

Since the order matters, `(A, C, B)` is also a valid boomerang. Therefore, we get **2 boomerangs** using A as the reference point.

We can also select B or C as the reference point and check whether the other two points are equally distant from it. Thus, every point gets a chance to act as the reference point, and multiple boomerangs can be formed.

**Distance Formula:**

To calculate the distance between two points, we use the Euclidean distance formula:


d = sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}


Since we only need to compare distances, we can ignore the square root and compare squared distances directly:


d^2 = (x_1-x_2)^2 + (y_1-y_2)^2


Our task is to count all possible ordered boomerangs formed by the given points.

A **reference point** is the point from which we calculate the distances to the other two points. We can select any of the three points as the reference point.

Consider these three points:

```text
        B (2, 0)

A (0, 0)       C (0, 2)
```

We use the Euclidean distance formula to calculate the distance between two points:


d = \sqrt{(x_1-x_2)^2+(y_1-y_2)^2}


**1. Taking A `(0, 0)` as the reference point**

The other two points are B `(2, 0)` and C `(0, 2)`.

| Distance | Calculation | Result |
|---|---|---:|
| A → B | sqrt{(2-0)^2+(0-0)^2} | 2 |
| A → C | sqrt{(0-0)^2+(2-0)^2} | 2 |

Both distances are equal, so we get 2 boomerangs: `(A, B, C)` and `(A, C, B)`.

**2. Taking B `(2, 0)` as the reference point**

The other two points are A `(0, 0)` and C `(0, 2)`.

| Distance | Calculation | Result |
|---|---|---:|
| B → A | sqrt{(0-2)^2+(0-0)^2} | 2 |
| B → C | sqrt{(0-2)^2+(2-0)^2} | sqrt{8} |

Both distances are different, so no boomerang is formed with B as the reference point.

**3. Taking C `(0, 2)` as the reference point**

The other two points are A `(0, 0)` and B `(2, 0)`.

| Distance | Calculation | Result |
|---|---|---:|
| C → A | sqrt{(0-0)^2+(0-2)^2} | 2 |
| C → B | \(\sqrt{(2-0)^2+(0-2)^2} | sqrt{8} |

Both distances are different, so no boomerang is formed with C as the reference point.

**Final Count:**

| Reference Point | Valid Boomerangs |
|---|---:|
| A | 2 |
| B | 0 |
| C | 0 |
| **Total** | **2** |

This is why we consider every point as a reference point. For each reference point, we check whether any two other points are equally distant from it and count all possible ordered pairs.

---

## 1. Hash Map – Distance Frequency Counting

**Approach:**


Select each point as the **reference point** by iterating through the `points` array using `i`. For every reference point, calculate its distance from all the other points.

Create an `unordered_map<int, int> freq` to store the frequency of squared distances.
  - **Key:** Squared distance from the reference point.
  - **Value:** Number of points having that squared distance.

- Iterate through all points using `j` and skip the reference point itself when `i == j`, because a point cannot form a boomerang with itself.

Calculate the horizontal and vertical differences between the two points:
  - `dx = points[i][0] - points[j][0]`
  - `dy = points[i][1] - points[j][1]`

Calculate the squared distance using `dx * dx + dy * dy`. We use squared distance instead of actual Euclidean distance because comparing squared distances is sufficient to determine whether two points are equally distant.

Update the frequency map using `freq[dist]++`. If multiple points have the same squared distance from the reference point, their frequencies increase under the same key.

Once all distances are stored, iterate through the frequency map. For every distance, retrieve its frequency using `it->second` and store it in `count`.

If a distance occurs `count` times, we can form `count * (count - 1)` ordered pairs:
  - We have `count` choices for selecting the first point.
  - After selecting the first point, we have `count - 1` choices for selecting a different second point.
  - Both orders are counted because a boomerang is an ordered tuple `(i, j, k)`.

- Add the total ordered pairs for that distance to `ans` using `ans += count * (count - 1)`.

Repeat the entire process for every point as the reference point and finally return `ans`, which contains the total number of boomerangs.

## Code

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        int ans = 0;

        // Select each point as the reference point
        for (int i = 0; i < n; i++) {

            // Store the frequency of squared distances
            unordered_map<int, int> freq;

            // Calculate distances from the reference point
            for (int j = 0; j < n; j++) {

                // Skip the reference point itself
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                // Calculate squared distance
                int dist = dx * dx + dy * dy;

                // Increase frequency of this distance
                freq[dist]++;
            }

            // Count ordered pairs for each distance
            for (auto it = freq.begin(); it != freq.end(); it++) {

                int count = it->second;

                ans += count * (count - 1);
            }
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n²)`

**Space Complexity:** `O(n)`

---

## 2. Sorting – Distance Grouping

**Approach:**

Select each point as the **reference point** by iterating through the `points` array using `i`. For every reference point, calculate its distance from all the other points.

Create a `vector<int> distances` to store the squared distances from the current reference point to every other point.

Iterate through all points using `j` and skip the reference point itself when `i == j`, because a point cannot form a boomerang with itself.

Calculate the horizontal and vertical differences between the two points:
  - `dx = points[i][0] - points[j][0]`
  - `dy = points[i][1] - points[j][1]`

Calculate the squared distance using `dx * dx + dy * dy` and insert it into the `distances` vector using `push_back()`.

After calculating all distances, sort the vector using `sort(distances.begin(), distances.end())`. Sorting places equal distances next to each other, making it easier to group points having the same distance from the reference point.

Initialize `count = 1` to keep track of the number of consecutive equal distances in the sorted vector.

Traverse the sorted distances starting from index `1` and compare the current distance with the previous distance:

If both distances are equal, increment `count` because another point has the same distance.

If they are different, the previous group of equal distances is complete. Add `count * (count - 1)` to `ans` to count all possible ordered pairs from that group, then reset `count = 1` for the new group.

After the loop finishes, process the last group separately using `ans += count * (count - 1)`, because there is no next element to trigger the group-ending condition.

Repeat the entire process for every point as the reference point and finally return `ans`, which contains the total number of boomerangs.

## Code 

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int n = points.size();
        int ans = 0;

        // Select each point as the reference point
        for (int i = 0; i < n; i++) {

            vector<int> distances;

            // Calculate distances from the reference point
            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                int dist = dx * dx + dy * dy;

                distances.push_back(dist);
            }

            // Sort all calculated distances
            sort(distances.begin(), distances.end());

            // Count consecutive equal distances
            int count = 1;

            for (int j = 1; j < distances.size(); j++) {

                if (distances[j] == distances[j - 1]) {
                    count++;
                }
                else {
                    ans += count * (count - 1);
                    count = 1;
                }
            }

            // Process the last group
            ans += count * (count - 1);
        }

        return ans;
    }
};
```

**Time Complexity:** `O(n² log n) `

**Space Complexity:** `O(n)` 

---

Thank you for taking the time to read this. Hope you find it helpful and enjoy exploring the approaches. ❤️

If you found it helpful, please **⬆️ upvote and leave a comment!** 💬

<img src="https://assets.leetcode.com/users/images/5ce11bf6-0db9-4239-bbb9-dfe5d76443f3_1666346629.9681695.gif" alt="LeetCode GIF" width="400">