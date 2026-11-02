#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int maxFreq = 0;
            int maxNum = 0;

            for (auto& entry : mp) {
                if (entry.second > maxFreq) {
                    maxFreq = entry.second;
                    maxNum = entry.first;
                }
            }

            ans.push_back(maxNum);
            mp.erase(maxNum);
        }

        return ans;
    }
};
