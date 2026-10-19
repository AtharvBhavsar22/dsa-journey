// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 3: Suffix Maximum Array.
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

        vector<int> suffixMax(n);
        suffixMax[n - 1] = prices[n - 1];

        // Build suffix maximum from right to left.
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(prices[i], suffixMax[i + 1]);
        }

        int profit = 0;

        // Use the best available future selling price for each buy day.
        for (int i = 0; i < n - 1; i++) {
            int currentProfit = suffixMax[i + 1] - prices[i];

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
