class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]--;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }

        return true;
    }
};
