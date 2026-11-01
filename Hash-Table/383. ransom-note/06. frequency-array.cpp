class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        int freq[26] = {0};

        for (int i = 0; i < m; i++) {
            freq[magazine[i] - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            freq[ransomNote[i] - 'a']--;

            if (freq[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
