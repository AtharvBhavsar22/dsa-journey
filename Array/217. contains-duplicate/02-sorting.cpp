
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Sort elements so duplicates become adjacent
        sort(nums.begin(), nums.end());

        // Check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    cout << boolalpha << sol.containsDuplicate(nums);

    return 0;
}
