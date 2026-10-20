// Problem: 238. Product of Array Except Self
// Approach 5: Prefix and Suffix Products in One Loop
// Time Complexity: O(n)
// Auxiliary Space: O(1), excluding the output array

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> answer(n, 1);

        int prefix = 1;
        int suffix = 1;

        // Combine the left and right passes by processing mirrored positions.
        for (int i = 0; i < n; ++i) {
            answer[i] *= prefix;
            prefix *= nums[i];

            answer[n - 1 - i] *= suffix;
            suffix *= nums[n - 1 - i];
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
