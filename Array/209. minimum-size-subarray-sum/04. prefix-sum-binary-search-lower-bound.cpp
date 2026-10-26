#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int minLen = n + 1;
        for (int i = 0; i < n; i++) {
            long long required = prefix[i] + target;
            auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), required);

            if (it != prefix.end()) {
                int j = it - prefix.begin();
                minLen = min(minLen, j - i);
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
};

int main() {
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    Solution solution;
    cout << "Minimum Subarray Length: "
         << solution.minSubArrayLen(target, nums) << endl;
    return 0;
}
