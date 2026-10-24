#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> range(n + 1);

        for (int i = 0; i <= n; i++) {
            range[i] = i;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != range[i]) {
                return range[i];
            }
        }

        return n;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 0, 1};

    int result = sol.missingNumber(nums);

    cout << "Missing Number: " << result << endl;

    return 0;
}
