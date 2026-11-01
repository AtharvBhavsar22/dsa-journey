class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();

        for (int i = 0; i < n; i++) {
            size_t pos = magazine.find(ransomNote[i]);

            if (pos == string::npos) {
                return false;
            }

            magazine.erase(pos, 1);
        }

        return true;
    }
};
