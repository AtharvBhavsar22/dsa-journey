#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        // Step 1: Create a frequency map
        unordered_map<int, int> freq;

        // Step 2: Count occurrences
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Step 3: Find the majority element
        for (auto it = freq.begin(); it != freq.end(); it++) {

            if (it->second > n / 2) {
                return it->first;
            }
        }

        return -1;
    }
};
