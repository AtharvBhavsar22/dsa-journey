#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        // Step 1: Traverse through each element
        for (int i = 0; i < n; i++) {

            // Step 2: Skip elements that have already been processed
            bool visited = false;

            for (int k = 0; k < i; k++) {
                if (nums[k] == nums[i]) {
                    visited = true;
                    break;
                }
            }

            if (visited) {
                continue;
            }

            // Step 3: Initialize count with 1 for the current element
            int count = 1;

            // Step 4: Count occurrences of the current element
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Step 5: Check whether the current element is a majority
            if (count > n / 3) {
                ans.push_back(nums[i]);
            }
        }

        // Step 6: Return all majority elements
        return ans;
    }
};
