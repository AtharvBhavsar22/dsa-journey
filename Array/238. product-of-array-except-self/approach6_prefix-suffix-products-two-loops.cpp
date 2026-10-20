// Problem: 238. Product of Array Except Self
// Approach 6: Prefix and Suffix Products Using Two Loops
// Time Complexity: O(n)
// Auxiliary Space: O(1), excluding the output array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> products(n, 1);

        // Store each left-side product directly in the output array.
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            products[i] = prefix;
            prefix *= nums[i];
        }

        // Multiply each stored left-side product by its right-side product.
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            products[i] *= suffix;
            suffix *= nums[i];
        }

        return products;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);

    cout << "Product Except Self: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
