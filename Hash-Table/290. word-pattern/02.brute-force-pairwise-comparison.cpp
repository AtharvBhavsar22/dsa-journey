#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        stringstream ss(s);
        string word;

        // Step 1: Extract all words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Check the number of words
        if (words.size() != pattern.length()) {
            return false;
        }

        // Step 3: Compare every pair of positions
        for (int i = 0; i < pattern.length(); i++) {

            for (int j = i + 1; j < pattern.length(); j++) {

                if ((pattern[i] == pattern[j]) != (words[i] == words[j])) {
                    return false;
                }
            }
        }

        return true;
    }
};
