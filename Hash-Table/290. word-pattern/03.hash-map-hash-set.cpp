#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> mp;
        unordered_set<string> used;

        stringstream ss(s);
        string word;

        for (int i = 0; i < pattern.length(); i++) {

            if (!(ss >> word)) {
                return false;
            }

            char ch = pattern[i];

            // Check existing mapping
            if (mp.find(ch) != mp.end()) {

                if (mp[ch] != word) {
                    return false;
                }

            }
            else {

                // Check whether the word is already used
                if (used.find(word) != used.end()) {
                    return false;
                }

                // Store the mapping
                mp[ch] = word;
                used.insert(word);
            }
        }

        // Check for extra words
        if (ss >> word) {
            return false;
        }

        return true;
    }
};
