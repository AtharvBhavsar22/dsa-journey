#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                // Shift remaining elements to the left.
                for (int j = i + 1; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }

                // Decrease logical size and check this index again.
                n--;
                i--;
            }
        }

        return n;
    }
};

int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "Unique elements: " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
