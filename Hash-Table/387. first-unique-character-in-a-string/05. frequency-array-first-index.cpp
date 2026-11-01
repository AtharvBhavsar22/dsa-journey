#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
        int firstIndex[26];

        fill(firstIndex, firstIndex + 26, -1);

        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';

            freq[index]++;

            if (firstIndex[index] == -1) {
                firstIndex[index] = i;
            }
        }

        int result = s.length();

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                result = min(result, firstIndex[i]);
            }
        }

        return result == s.length() ? -1 : result;
    }
};
