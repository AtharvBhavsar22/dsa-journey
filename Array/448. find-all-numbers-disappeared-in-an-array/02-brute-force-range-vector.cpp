#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        vector<int> notSeen;
        vector<int> range;

        // Create a range vector from 1 to n
        for (int i = 1; i <= n; i++) {
            range.push_back(i);
        }

        // Search each expected number in the original array
        for (int i = 0; i < n; i++) {

            if (find(nums.begin(), nums.end(), range[i]) == nums.end()) {
                notSeen.push_back(range[i]);
            }
        }

        return notSeen;
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