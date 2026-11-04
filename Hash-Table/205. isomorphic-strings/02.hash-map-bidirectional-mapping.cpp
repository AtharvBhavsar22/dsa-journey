#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            // Check forward mapping
            if (mp1.find(ch1) != mp1.end()) {
                if (mp1[ch1] != ch2) {
                    return false;
                }
            }

            // Check reverse mapping
            if (mp2.find(ch2) != mp2.end()) {
                if (mp2[ch2] != ch1) {
                    return false;
                }
            }

            // Store both mappings
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }

        return true;
    }
};
