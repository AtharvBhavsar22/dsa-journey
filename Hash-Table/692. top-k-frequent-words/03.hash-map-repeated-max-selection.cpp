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

        vector<string> ans;

        // Step 2: Find the maximum frequency k times
        for (int i = 0; i < k; i++) {

            int maxFreq = 0;
            string maxWord = "";

            // Step 3: Find the word with the highest frequency
            for (auto& entry : mp) {
                if (entry.second > maxFreq ||
                    (entry.second == maxFreq && entry.first < maxWord)) {

                    maxFreq = entry.second;
                    maxWord = entry.first;
                }
            }

            // Step 4: Add the word to the answer
            ans.push_back(maxWord);

            // Step 5: Remove it to avoid selecting it again
            mp.erase(maxWord);
        }

        return ans;
    }
};
