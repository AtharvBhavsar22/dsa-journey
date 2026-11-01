class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        vector<bool> used(m, false);

        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < m; j++) {
                if (magazine[j] == ransomNote[i] && !used[j]) {
                    used[j] = true;
                    found = true;
                    break;
                }
            }

            if (!found) {
                return false;
            }
        }

        return true;
    }
};
