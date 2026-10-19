// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 1: Brute Force — check every buy/sell pair.
// Time Complexity: O(n^2)
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
        int profit = 0;

        // Try every buying day.
        for (int i = 0; i < n - 1; i++) {

            // Try every selling day after the buying day.
            for (int j = i + 1; j < n; j++) {
                int currentProfit = prices[j] - prices[i];

                // Keep the largest profit found so far.
                if (currentProfit > profit) {
                    profit = currentProfit;
                }
            }
        }

        return profit;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;

    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}
