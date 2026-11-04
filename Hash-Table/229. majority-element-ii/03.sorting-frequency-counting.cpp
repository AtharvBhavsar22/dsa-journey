#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Initialize frequency count
        int count = 1;

        // Step 3: Traverse the sorted array
        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1]) {
                count++;
            }
            else {

                // Step 4: Check frequency of the previous element
                if (count > n / 3) {
                    ans.push_back(nums[i - 1]);
                }

                // Step 5: Reset count for the new element
                count = 1;
            }
        }

        // Step 6: Check the frequency of the last element
        if (count > n / 3) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};
