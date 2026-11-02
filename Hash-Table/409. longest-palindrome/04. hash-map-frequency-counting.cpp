#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 == 0) {
                ans += it->second;
            }
            else {
                ans += it->second - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
