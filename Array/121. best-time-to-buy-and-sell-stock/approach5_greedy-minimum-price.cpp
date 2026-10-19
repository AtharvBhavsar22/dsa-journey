// LeetCode 121: Best Time to Buy and Sell Stock
// Approach 5: Greedy — track the minimum price seen so far.
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

        int minPrice = prices[0];
        int maxProfit = 0;

        // Traverse the prices once, starting from the second day.
        for (int i = 1; i < n; i++) {

            // Calculate profit using the lowest earlier price.
            int currentProfit = prices[i] - minPrice;

            // Update maximum profit before considering today's price as a new minimum.
            if (currentProfit > maxProfit) {
                maxProfit = currentProfit;
            }

            // Update the minimum buying price for later days.
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
        }

        return maxProfit;
    }
};

// ==================== LOCAL TESTING ====================

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;

    cout << "Maximum Profit: " << solution.maxProfit(prices) << endl;
    return 0;
}
