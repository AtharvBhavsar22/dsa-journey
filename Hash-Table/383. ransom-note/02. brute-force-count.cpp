class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        if (n > m) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            char ch = ransomNote[i];

            int required = count(ransomNote.begin(), ransomNote.end(), ch);
            int available = count(magazine.begin(), magazine.end(), ch);

            if (required > available) {
                return false;
            }
        }

        return true;
    }
};
