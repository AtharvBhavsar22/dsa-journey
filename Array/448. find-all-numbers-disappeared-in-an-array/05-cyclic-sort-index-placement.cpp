#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;

        // Place every number at its correct index
        for (auto& c : nums) {

            while (nums[c - 1] != c) {
                swap(c, nums[c - 1]);
            }
        }

        // Find numbers that are missing
        for (int i = 1; i <= size(nums); i++) {

            if (i != nums[i - 1]) {
                ans.push_back(i);
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