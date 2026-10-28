class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int freq[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[static_cast<unsigned char>(s[i])]++;
            freq[static_cast<unsigned char>(t[i])]--;
        }

        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
