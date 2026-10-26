#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_set<int> st;

        // Store all numbers present in the array
        for (int num : nums) {
            st.insert(num);
        }

        vector<int> ans;

        int n = nums.size();

        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // If the number is not present in the set
            if (st.find(i) == st.end()) {
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