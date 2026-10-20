// Problem: 238. Product of Array Except Self
// Approach 2: Separate Prefix and Suffix Arrays
// Time Complexity: O(n)
// Auxiliary Space: O(n) for the prefix and suffix arrays, excluding output
// The prefix array stores products to each index's left; the suffix array
// stores products to each index's right.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> answer(n, 1);

        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            answer[i] = prefix[i] * suffix[i];
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
