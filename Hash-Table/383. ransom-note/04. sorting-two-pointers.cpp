class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.length();
        int m = magazine.length();

        if (n > m) {
            return false;
        }

        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());

        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            if (ransomNote[i] == magazine[j]) {
                i++;
                j++;
            }
            else if (ransomNote[i] > magazine[j]) {
                j++;
            }
            else {
                return false;
            }
        }

        return i == n;
    }
};
