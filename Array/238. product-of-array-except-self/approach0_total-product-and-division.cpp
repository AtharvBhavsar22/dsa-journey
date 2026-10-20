// Problem: 238. Product of Array Except Self
// Approach 0: Total Product and Division
// Time Complexity: O(n)
// Auxiliary Space: O(1), excluding the output array
// Note: This comparison approach uses division and does not meet the original
//       LeetCode problem's no-division requirement. The product must fit in
//       long long.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        long long totalProduct = 1;

        for (int num : nums) {
            if (num == 0) {
                ++zeroCount;
            } else {
                totalProduct *= num;
            }
        }

        vector<int> answer(nums.size(), 0);

        if (zeroCount > 1) {
            return answer;
        }

        if (zeroCount == 1) {
            for (size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    answer[i] = static_cast<int>(totalProduct);
                    break;
                }
            }
            return answer;
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            answer[i] = static_cast<int>(totalProduct / nums[i]);
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
