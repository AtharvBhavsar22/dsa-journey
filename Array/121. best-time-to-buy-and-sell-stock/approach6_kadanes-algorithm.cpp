// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 6: Kadane's Algorithm using consecutive price differences.
// Time Complexity: O(n)
// Auxiliary Space: O(1)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int currentSum = 0;
        int maxSum = 0;

        // Calculate consecutive price differences.
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i - 1];

            // Extend the current section or discard a negative total.
            currentSum = max(0, currentSum + diff);

            // Store the maximum accumulated profit found so far.
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;

    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}
