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

        // Step 2: Create a min-heap based on frequency
        auto cmp = [](const pair<int, string>& a,
                      const pair<int, string>& b) {

            if (a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        };

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            decltype(cmp)
        > pq(cmp);

        // Step 3: Insert words and frequencies
        for (auto entry : mp) {
            pq.push({entry.second, entry.first});

            // Keep only k elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 4: Extract the words
        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Step 5: Reverse to get the required order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
