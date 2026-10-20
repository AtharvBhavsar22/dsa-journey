// Problem: 238. Product of Array Except Self
// Approach 4: Suffix Array and Prefix Running Product
// Time Complexity: O(n)
// Auxiliary Space: O(n) for the suffix array, excluding output

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> suffix(n, 1);
        vector<int> answer(n, 1);

        // suffix[i] is the product of all elements strictly to the right.
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Walk forward, accumulating the product strictly to the left.
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            answer[i] = prefix * suffix[i];
            prefix *= nums[i];
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
