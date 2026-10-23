// Problem: 1929. Concatenation of Array
// Approach 1: Two-Pass Loops
// Time Complexity: O(n) | Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // First pass: Copy the original array.
        for (int i = 0; i < n; i++) {
            ans.push_back(nums[i]);
        }

        // Second pass: Append the array again if needed.
        if (ans.size() != 2 * n) {
            for (int i = 0; i < n; i++) {
                ans.push_back(nums[i]);
            }
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

    // Print the concatenated array.
    for (int num : ans) {
    cout << num << " ";
    }
    cout << endl;

    return 0;
}