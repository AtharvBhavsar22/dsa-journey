#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto entry : mp) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> ans;

        for (int i = freq.size() - 1; i >= 1; i--) {
            for (int num : freq[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
