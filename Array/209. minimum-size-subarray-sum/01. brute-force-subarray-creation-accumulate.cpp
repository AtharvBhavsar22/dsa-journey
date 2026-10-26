#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> subarray(nums.begin() + i, nums.begin() + j + 1);
                long long sum = accumulate(subarray.begin(), subarray.end(), 0LL);

                if (sum >= target) {
                    minLen = min(minLen, j - i + 1);
                }
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
