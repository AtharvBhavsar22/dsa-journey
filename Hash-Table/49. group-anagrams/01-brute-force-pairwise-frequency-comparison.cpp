#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<bool> grouped(n, false);
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (grouped[i]) {
                continue;
            }

            vector<string> group;
            group.push_back(strs[i]);
            grouped[i] = true;

            for (int j = i + 1; j < n; j++) {
                if (grouped[j]) {
                    continue;
                }

                if (strs[i].length() != strs[j].length()) {
                    continue;
                }

                int freq[26] = {0};

                for (int k = 0; k < strs[i].length(); k++) {
                    freq[strs[i][k] - 'a']++;
                    freq[strs[j][k] - 'a']--;
                }

                bool isAnagram = true;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] != 0) {
                        isAnagram = false;
                        break;
                    }
                }

                if (isAnagram) {
                    group.push_back(strs[j]);
                    grouped[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
