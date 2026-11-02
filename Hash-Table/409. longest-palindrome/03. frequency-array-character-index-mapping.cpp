#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int freq[52] = {0};

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                freq[s[i] - 'a']++;
            }
            else {
                freq[s[i] - 'A' + 26]++;
            }
        }

        int ans = 0;
        bool hasOdd = false;

        for (int i = 0; i < 52; i++) {
            if (freq[i] % 2 == 0) {
                ans += freq[i];
            }
            else {
                ans += freq[i] - 1;
                hasOdd = true;
            }
        }

        if (hasOdd) {
            ans++;
        }

        return ans;
    }
};
