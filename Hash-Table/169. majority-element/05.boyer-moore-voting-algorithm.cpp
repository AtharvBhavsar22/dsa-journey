#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Step 1: Initialize candidate and count
        int candidate = 0;
        int count = 0;

        // Step 2: Traverse the array
        for (int i = 0; i < nums.size(); i++) {

            // Step 3: Select a new candidate if count becomes zero
            if (count == 0) {
                candidate = nums[i];
            }

            // Step 4: Increase or decrease the vote count
            if (nums[i] == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        // Step 5: Return the majority element
        return candidate;
    }
};
