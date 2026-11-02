#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        vector<string> sortedStrs(n);

        for (int i = 0; i < n; i++) {
            sortedStrs[i] = strs[i];
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
        }

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
                if (!grouped[j] && sortedStrs[i] == sortedStrs[j]) {
                    group.push_back(strs[j]);
                    grouped[j] = true;
                }
            }

            result.push_back(group);
        }

        return result;
    }
};
