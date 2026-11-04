#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Step 1: Find majority candidates in the given range
    vector<int> divide(vector<int>& nums, int left, int right) {

        // Step 2: Base case - only one element remains
        if (left == right) {
            return {nums[left]};
        }

        // Step 3: Divide the array into two halves
        int mid = left + (right - left) / 2;

        vector<int> leftMajority = divide(nums, left, mid);
        vector<int> rightMajority = divide(nums, mid + 1, right);

        // Step 4: Combine unique candidates from both halves
        vector<int> candidates;

        for (int num : leftMajority) {
            candidates.push_back(num);
        }

        for (int num : rightMajority) {
            bool exists = false;

            for (int candidate : candidates) {
                if (candidate == num) {
                    exists = true;
                    break;
                }
            }

            if (!exists) {
                candidates.push_back(num);
            }
        }

        // Step 5: Count each candidate in the current range
        vector<int> ans;
        int n = right - left + 1;

        for (int candidate : candidates) {
            int count = 0;

            for (int i = left; i <= right; i++) {
                if (nums[i] == candidate) {
                    count++;
                }
            }

            // Step 6: Keep candidates appearing more than n / 3 times
            if (count > n / 3) {
                ans.push_back(candidate);
            }
        }

        return ans;
    }

    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) {
            return {};
        }

        return divide(nums, 0, n - 1);
    }
};
