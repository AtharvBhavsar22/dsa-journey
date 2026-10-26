#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] != 0) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution solution;
    solution.moveZeroes(nums);

    cout << "Output: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
