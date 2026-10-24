# 26. Remove Duplicates from Sorted Array

Given a sorted integer array `nums`, remove the duplicates in-place so that each unique value appears once. Return `k`, the number of unique values. The first `k` elements of `nums` must contain the unique values in sorted order.

The examples use `nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}`. Each C++ file is a standalone program with its own `main()`.

## 1. Brute Force — Nested Loop Shifting

Whenever adjacent elements are equal, shift all later values one position to the left, decrease the logical size, and check the same index again.

**Output**

```text
Unique elements: 5
Array: 0 1 2 3 4
```

- **Time:** `O(n^2)`
- **Auxiliary space:** `O(1)`
- **Code:** [01. brute-force-nested-loop-shifting.cpp](./01.%20brute-force-nested-loop-shifting.cpp)

## 2. Two Pointers — Overwriting

Pointer `i` tracks the last unique element. Pointer `j` scans the sorted array; when it finds a different value, copy it into the next unique position. Return `i + 1`. This implementation also returns `0` for an empty vector.

**Output**

```text
Unique elements: 5
Array: 0 1 2 3 4
```

- **Time:** `O(n)`
- **Auxiliary space:** `O(1)`
- **Code:** [02. two-pointers-overwriting.cpp](./02.%20two-pointers-overwriting.cpp)

## 3. Two Pointers — Swapping

Pointer `i` tracks the last unique position and `j` scans for a different value. Swap each newly found unique value into the next position. This preserves the sorted unique prefix.

**Output**

```text
Unique elements: 5
Array: 0 1 2 3 4
```

- **Time:** `O(n)`
- **Auxiliary space:** `O(1)`
- **Code:** [03. two-pointers-swapping.cpp](./03.%20two-pointers-swapping.cpp)

## 4. Extra Array — Store Unique Elements

Store the first value, then append each value that differs from its predecessor. Copy the resulting unique values back into `nums` and return their count.

**Output**

```text
Unique elements: 5
Array: 0 1 2 3 4
```

- **Time:** `O(n)`
- **Auxiliary space:** `O(n)`
- **Code:** [04. extra-array-store-unique-elements.cpp](./04.%20extra-array-store-unique-elements.cpp)

## 5. STL — `unique()`

`std::unique()` moves consecutive duplicates to the end of the range and returns an iterator to the end of the unique prefix. Subtract `nums.begin()` to get the number of unique elements. The vector is not resized; only its first `k` elements are relevant.

**Output**

```text
Unique elements: 5
Array: 0 1 2 3 4
```

- **Time:** `O(n)`
- **Auxiliary space:** `O(1)`
- **Code:** [05. stl-unique.cpp](./05.%20stl-unique.cpp)
