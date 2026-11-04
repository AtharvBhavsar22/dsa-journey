#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> freq;
        vector<int> ans;

        // Step 1: Count the frequency of each element
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 2: Find elements whose frequency is greater than n / 3
        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (it->second > n / 3) {
                ans.push_back(it->first);
            }
        }

        // Step 3: Return all majority elements
        return ans;
    }
};
