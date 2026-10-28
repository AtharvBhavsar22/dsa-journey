class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length() || i < t.length(); i++) {
            if (i < s.length()) {
                freq[s[i]]++;
            }

            if (i < t.length()) {
                freq[t[i]]--;
            }
        }

        for (auto entry : freq) {
            if (entry.second != 0) {
                return false;
            }
        }

        return true;
    }
};
