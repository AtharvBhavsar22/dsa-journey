#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int ans = 0;
        bool hasOdd = false;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (s[i] == s[j]) {
                    count++;
                }
            }

            bool alreadyProcessed = false;

            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    alreadyProcessed = true;
                    break;
                }
            }

            if (alreadyProcessed) {
                continue;
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
