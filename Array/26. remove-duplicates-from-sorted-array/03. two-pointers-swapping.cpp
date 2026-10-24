
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        for (int j = 1; j < n; j++) {

            if (nums[i] != nums[j]) {

                // Swap the next unique element into its correct position
                swap(nums[i + 1], nums[j]);

                // Move to the next unique position
                i++;
            }
        }

        return i + 1;
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
