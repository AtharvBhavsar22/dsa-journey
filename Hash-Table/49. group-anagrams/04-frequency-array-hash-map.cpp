#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            int freq[26] = {0};

            for (char ch : strs[i]) {
                freq[ch - 'a']++;
            }

            string key = "";

            for (int j = 0; j < 26; j++) {
                key += to_string(freq[j]) + "#";
            }

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for (auto it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
