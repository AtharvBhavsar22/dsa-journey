#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        // Sort the original array
        sort(begin(nums), end(nums));

        vector<int> ans;

        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // Binary search for the current number
            if (!binary_search(begin(nums), end(nums), i)) {
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