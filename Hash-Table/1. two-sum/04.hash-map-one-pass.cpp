#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        // Step 1: Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Step 2: Calculate the required complement
            int complement = target - nums[i];

            // Step 3: Check whether the complement exists
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Step 4: Store the current number and its index
            mp[nums[i]] = i;
        }

        return {};
    }
};
