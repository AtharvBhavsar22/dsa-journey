// Problem: 238. Product of Array Except Self
// Approach 3: Prefix Array and Suffix Running Product
// Time Complexity: O(n)
// Auxiliary Space: O(n) for the prefix array, excluding output

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> prefix(n, 1);
        vector<int> answer(n, 1);

        // prefix[i] is the product of all elements strictly to the left.
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Walk backward, accumulating the product strictly to the right.
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] = prefix[i] * suffix;
            suffix *= nums[i];
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
