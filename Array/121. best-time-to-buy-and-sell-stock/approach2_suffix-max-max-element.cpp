// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 2: Suffix Maximum using max_element().
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

        for (int i = 0; i < n - 1; i++) {

            // Search future days for the best selling price.
            int maxPrice = *max_element(
                prices.begin() + i + 1,
                prices.end()
            );

            int currentProfit = maxPrice - prices[i];

            // Keep the largest profit found so far.
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
