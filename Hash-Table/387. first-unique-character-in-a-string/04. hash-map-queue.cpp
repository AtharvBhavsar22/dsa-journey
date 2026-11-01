#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        queue<pair<char, int>> q;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
            q.push({s[i], i});

            while (!q.empty() && freq[q.front().first] > 1) {
                q.pop();
            }
        }

        if (q.empty()) {
            return -1;
        }

        return q.front().second;
    }
};
