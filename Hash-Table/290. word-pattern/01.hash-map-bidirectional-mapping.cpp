#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            char ch = pattern[i];

            // Check forward mapping
            if (mp1.find(ch) != mp1.end()) {
                if (mp1[ch] != word) {
                    return false;
                }
            }

            // Check reverse mapping
            if (mp2.find(word) != mp2.end()) {
                if (mp2[word] != ch) {
                    return false;
                }
            }

            // Store both mappings
            mp1[ch] = word;
            mp2[word] = ch;
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
