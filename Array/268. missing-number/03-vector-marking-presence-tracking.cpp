#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        vector<int> v(n + 1, -1);

        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]] = nums[i];
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == -1) {
                return i;
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 0, 1};

    int result = sol.missingNumber(nums);

    cout << "Missing Number: " << result << endl;

    return 0;
}
