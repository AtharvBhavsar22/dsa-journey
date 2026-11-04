#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // Step 1: Initialize two candidates and their counts
        int candidate1 = 0, candidate2 = 0;
        int count1 = 0, count2 = 0;

        // Step 2: Find two potential majority candidates
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == candidate1) {
                count1++;
            }
            else if (nums[i] == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 3: Reset counts to verify actual frequencies
        count1 = 0;
        count2 = 0;

        // Step 4: Count the actual occurrences of both candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
        }

        // Step 5: Store candidates appearing more than n / 3 times
        vector<int> ans;
        int n = nums.size();

        if (count1 > n / 3) {
            ans.push_back(candidate1);
        }

        if (count2 > n / 3) {
            ans.push_back(candidate2);
        }

        // Step 6: Return the majority elements
        return ans;
    }
};
