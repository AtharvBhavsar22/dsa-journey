#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int mapST[128];
        int mapTS[128];

        fill(mapST, mapST + 128, -1);
        fill(mapTS, mapTS + 128, -1);

        for (int i = 0; i < s.length(); i++) {

            int ch1 = s[i];
            int ch2 = t[i];

            if (mapST[ch1] != -1 && mapST[ch1] != ch2) {
                return false;
            }

            if (mapTS[ch2] != -1 && mapTS[ch2] != ch1) {
                return false;
            }

            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }

        return true;
    }
};
