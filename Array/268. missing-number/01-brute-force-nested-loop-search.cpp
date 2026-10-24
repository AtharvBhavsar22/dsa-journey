#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            bool found = false;

            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 0, 1};

    int result = sol.missingNumber(nums);

    cout << "Missing Number: " << result << endl;

    return 0;
}
