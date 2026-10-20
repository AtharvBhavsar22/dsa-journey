// Problem: 238. Product of Array Except Self
// Approach 1: Brute Force
// Time Complexity: O(n^2)
// Auxiliary Space: O(1), excluding the output array
// This straightforward method recomputes each answer from all other elements,
// making it inefficient for large arrays.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> answer(n, 1);

        for (int i = 0; i < n; ++i) {
            int product = 1;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    product *= nums[j];
                }
            }
            answer[i] = product;
        }

        return answer;
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
