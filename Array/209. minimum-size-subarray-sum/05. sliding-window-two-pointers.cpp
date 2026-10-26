#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = n + 1;
        int left = 0;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
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
