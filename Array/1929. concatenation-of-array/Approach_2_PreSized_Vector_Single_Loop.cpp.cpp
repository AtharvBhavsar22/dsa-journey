// Problem: 1929. Concatenation of Array
// Approach 2: Pre-sized Vector + Single Loop
// Time Complexity: O(n) | Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);

        // Copy each element into both halves of the answer.
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    // Test Case 1
    // Input:  nums = [1, 2, 1]
    // Expected Output: [1, 2, 1, 1, 2, 1]

    vector<int> nums = {1, 2, 1};

    Solution solution;
    vector<int> ans = solution.getConcatenation(nums);

    // Print the resulting array.
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}