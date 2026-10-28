class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;

        for (int i = 0; i < s.length(); i++) {
            mapS[s[i]]++;
        }

        for (int i = 0; i < t.length(); i++) {
            mapT[t[i]]++;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (mapS[c] != mapT[c]) {
                return false;
            }
        }

        return true;
    }
};
