209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimum length of a contiguous subarray whose sum is greater than or equal to target. Return 0 if no such subarray exists.

Each numbered C++ file is a standalone solution with a main() function that runs the sample input.

#	Approach	Time	Auxiliary space
01	Brute force — create each subarray and accumulate	O(n³)	O(n)
02	Brute force — prefix sums	O(n²)	O(n)
03	Binary search on length + sliding window	O(n log n)	O(1)
04	Prefix sums + lower_bound	O(n log n)	O(n)
05	Sliding window — two pointers	O(n)	O(1)
01. Brute Force — Subarray Creation + Accumulate
Generate every contiguous subarray by its start and end indices, copy it into a temporary vector, and use accumulate to calculate its sum. Track the shortest subarray whose sum reaches the target.

The repeated copying and summing take O(n³) time in total. The temporary subarray uses up to O(n) extra space.

02. Brute Force — Prefix Sum
Build a prefix-sum array so each subarray sum is calculated as prefix[end] - prefix[start] in constant time. Check every possible start and end pair, keeping the shortest valid length.

Building the prefix array takes O(n) time; checking all pairs takes O(n²). The prefix array uses O(n) extra space.

03. Binary Search on Length + Sliding Window
For a fixed length, scan all windows of that length using a sliding sum. If any window reaches the target, that length is feasible. Feasibility is monotonic for positive array values: if a length works, every longer length also works. Binary search for the smallest feasible length.

Each feasibility check takes O(n), and binary search performs O(log n) checks. The algorithm uses O(1) extra space.

04. Prefix Sum + Binary Search (lower_bound)
Build prefix sums, then for each starting index find the first prefix value at least prefix[start] + target using lower_bound. The difference between the two indices gives a valid subarray length.

Positive values make the prefix sums sorted, allowing binary search. This takes O(n log n) time and O(n) extra space.

05. Sliding Window — Two Pointers
Expand the window by moving the right pointer and adding each value to the sum. Whenever the sum reaches the target, record the window length and move the left pointer forward while the window remains valid.

Both pointers move forward at most n times, so the algorithm takes O(n) time and O(1) extra space.

The binary-search and sliding-window approaches rely on all values being positive, as guaranteed by the problem constraints.