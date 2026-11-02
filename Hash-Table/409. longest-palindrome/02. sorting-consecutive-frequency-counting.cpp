#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        sort(s.begin(), s.end());

        int n = s.length();
        int ans = 0;
        bool hasOdd = false;

        for (int i = 0; i < n;) {
            int count = 0;
            char ch = s[i];

            while (i < n && s[i] == ch) {
                count++;
                i++;
            }

            if (count % 2 == 0) {
                ans += count;
            }
            else {
                ans += count - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
