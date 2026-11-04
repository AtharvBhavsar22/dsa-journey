#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Traverse through each element
        for (int i = 0; i < n; i++) {

            // Step 2: Skip already processed elements
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

            // Step 3: Initialize frequency count
            int count = 1;

            // Step 4: Count remaining occurrences
            for (int j = i + 1; j < n; j++) {

                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // Step 5: Check majority condition
            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};
