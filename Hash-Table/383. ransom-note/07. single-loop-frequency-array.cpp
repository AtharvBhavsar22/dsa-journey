class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        if (n > m) {
            return false;
        }

        int freq[26] = {0};

        for (int i = 0; i < m; i++) {
            freq[magazine[i] - 'a']++;

            if (i < n) {
                freq[ransomNote[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] < 0) {
                return false;
            }
        }

        return true;
    }
};
