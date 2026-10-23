// Problem: 1929. Concatenation of Array
// Approach 3: STL insert()
// Time Complexity: O(n) | Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    // Test Case 1
    // Input: nums = [1, 2, 1]
    // Expected Output: [1, 2, 1, 1, 2, 1]

    vector<int> nums = {1, 2, 1};

    Solution solution;
    vector<int> ans = solution.getConcatenation(nums);

    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}