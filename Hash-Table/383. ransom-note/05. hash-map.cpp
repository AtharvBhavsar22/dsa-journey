class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> freq;

        int n = ransomNote.length();
        int m = magazine.length();

        for (int i = 0; i < m; i++) {
            freq[magazine[i]]++;
        }

        for (int i = 0; i < n; i++) {
            freq[ransomNote[i]]--;

            if (freq[ransomNote[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};
