// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 4: Prefix Minimum Array.
// Time Complexity: O(n)
// Auxiliary Space: O(n)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ==================== LEETCODE SOLUTION ====================

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> prefixMin(n);
        prefixMin[0] = prices[0];

        // Build prefix minimum from left to right.
        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i - 1], prices[i]);
        }

        int profit = 0;

        // Use the minimum price from a day before the selling day.
        for (int i = 1; i < n; i++) {
            int currentProfit = prices[i] - prefixMin[i - 1];

            if (currentProfit > profit) {
                profit = currentProfit;
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
