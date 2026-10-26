#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nextNonZero = 0;

        for (int current = 0; current < n; current++) {
            if (nums[current] != 0) {
                nums[nextNonZero] = nums[current];
                nextNonZero++;
            }
        }

        while (nextNonZero < n) {
            nums[nextNonZero] = 0;
            nextNonZero++;
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
