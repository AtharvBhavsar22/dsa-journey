
// Problem: 1470. Shuffle the Array
// Approach 2: Two Pointers
// Time Complexity: O(n) | Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int i = 0, j = n;

        // Pick one element from each half.
        while (i < n && j < nums.size()) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }

        return ans;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    // Test Case 1
    // Input: nums = [2, 5, 1, 3, 4, 7], n = 3
    // Expected Output: [2, 3, 5, 4, 1, 7]

    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    Solution solution;
    vector<int> ans = solution.shuffle(nums, n);

    // Print the shuffled array.
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
