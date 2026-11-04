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

        // Step 2: Create buckets based on frequency
        vector<vector<string>> freq(words.size() + 1);

        // Step 3: Place words into their frequency buckets
        for (auto entry : mp) {
            freq[entry.second].push_back(entry.first);
        }

        // Step 4: Collect the k most frequent words
        vector<string> ans;

        for (int i = freq.size() - 1; i >= 1; i--) {

            // Step 5: Sort words alphabetically within each bucket
            sort(freq[i].begin(), freq[i].end());

            for (string word : freq[i]) {
                ans.push_back(word);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
