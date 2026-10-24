#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            ans = ans ^ i;
        }

        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 0, 1};

    int result = sol.missingNumber(nums);

    cout << "Missing Number: " << result << endl;

    return 0;
}
