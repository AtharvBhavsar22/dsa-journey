#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < s.length(); i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            if (mp.find(ch1) != mp.end()) {

                if (mp[ch1] != ch2) {
                    return false;
                }

            }
            else {

                if (used.find(ch2) != used.end()) {
                    return false;
                }

                mp[ch1] = ch2;
                used.insert(ch2);
            }
        }

        return true;
    }
};
