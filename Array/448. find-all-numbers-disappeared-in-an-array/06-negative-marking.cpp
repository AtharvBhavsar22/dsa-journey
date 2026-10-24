#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        // Mark the index corresponding to each number
        for (auto c : nums) {

            nums[abs(c) - 1] = -abs(nums[abs(c) - 1]);
        }

        // Positive elements indicate missing numbers
        for (int i = 0; i < n; i++) {

            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> ans = sol.findDisappearedNumbers(nums);

    cout << "Missing Numbers: ";

    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}