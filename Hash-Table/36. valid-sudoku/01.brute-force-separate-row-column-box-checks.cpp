#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check all rows
        for (int i = 0; i < 9; i++) {

            unordered_set<char> seen;

            for (int j = 0; j < 9; j++) {

                char ch = board[i][j];

                if (ch == '.') continue;

                if (seen.count(ch)) {
                    return false;
                }

                seen.insert(ch);
            }
        }

        // Check all columns
        for (int j = 0; j < 9; j++) {

            unordered_set<char> seen;

            for (int i = 0; i < 9; i++) {

                char ch = board[i][j];

                if (ch == '.') continue;

                if (seen.count(ch)) {
                    return false;
                }

                seen.insert(ch);
            }
        }

        // Check all 3 x 3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                unordered_set<char> seen;

                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {

                        char ch = board[r][c];

                        if (ch == '.') continue;

                        if (seen.count(ch)) {
                            return false;
                        }

                        seen.insert(ch);
                    }
                }
            }
        }

        return true;
    }
};
