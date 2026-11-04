#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        int lastPattern[26] = {0};
        unordered_map<string, int> lastWord;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            int ch = pattern[i] - 'a';

            // Check whether both were last seen at the same index
            if (lastPattern[ch] != lastWord[word]) {
                return false;
            }

            // Update last seen indices
            lastPattern[ch] = i + 1;
            lastWord[word] = i + 1;
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
