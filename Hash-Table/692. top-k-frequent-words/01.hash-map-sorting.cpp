#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Step 1: Count frequencies
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        // Step 2: Store words and frequencies
        vector<pair<string, int>> freq;

        for (auto entry : mp) {
            freq.push_back({entry.first, entry.second});
        }

        // Step 3: Sort by frequency and lexicographical order
        sort(freq.begin(), freq.end(),
             [](const pair<string, int>& a,
                const pair<string, int>& b) {

                 if (a.second == b.second) {
                     return a.first < b.first;
                 }

                 return a.second > b.second;
             });

        // Step 4: Collect the first k words
        vector<string> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }

        return ans;
    }
};
