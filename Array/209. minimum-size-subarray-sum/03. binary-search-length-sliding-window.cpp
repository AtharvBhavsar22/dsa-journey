#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        int minLen = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 0;
            bool found = false;

            for (int i = 0; i < mid; i++) {
                sum += nums[i];
            }

            if (sum >= target) {
                found = true;
            }

            for (int i = mid; i < n && !found; i++) {
                sum += nums[i];
                sum -= nums[i - mid];
                if (sum >= target) {
                    found = true;
                }
            }

            if (found) {
                minLen = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minLen;
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
