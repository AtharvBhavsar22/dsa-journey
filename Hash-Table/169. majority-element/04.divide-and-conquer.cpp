#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Step 1: Find the majority candidate in a range
    int divide(vector<int>& nums, int left, int right) {

        // Step 2: Base case
        if (left == right) {
            return nums[left];
        }

        // Step 3: Divide the array into two halves
        int mid = left + (right - left) / 2;

        int leftMajority = divide(nums, left, mid);
        int rightMajority = divide(nums, mid + 1, right);

        // Step 4: Check whether both candidates are equal
        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        // Step 5: Count occurrences of both candidates
        int leftCount = 0;
        int rightCount = 0;

        for (int i = left; i <= right; i++) {

            if (nums[i] == leftMajority) {
                leftCount++;
            }

            if (nums[i] == rightMajority) {
                rightCount++;
            }
        }

        // Step 6: Return the candidate with higher frequency
        return (leftCount > rightCount)
            ? leftMajority
            : rightMajority;
    }

    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        return divide(nums, 0, n - 1);
    }
};
