#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int snowballSize = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                snowballSize++;
            } else if (snowballSize > 0) {
                nums[i - snowballSize] = nums[i];
                nums[i] = 0;
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
