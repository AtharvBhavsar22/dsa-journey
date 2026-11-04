#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        // Step 1: Store numbers with their original indices
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Step 2: Sort based on numbers
        sort(arr.begin(), arr.end());

        // Step 3: Initialize two pointers
        int left = 0;
        int right = n - 1;

        // Step 4: Find the required pair
        while (left < right) {

            int sum = arr[left].first + arr[right].first;

            if (sum == target) {
                return {arr[left].second, arr[right].second};
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return {};
    }
};
