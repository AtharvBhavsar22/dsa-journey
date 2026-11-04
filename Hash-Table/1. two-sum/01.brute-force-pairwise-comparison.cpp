#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Step 1: Select the first element
        for (int i = 0; i < n; i++) {

            // Step 2: Check elements after the first element
            for (int j = i + 1; j < n; j++) {

                // Step 3: Check whether their sum equals target
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        // Step 4: Return an empty vector if no pair is found
        return {};
    }
};
