
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (nums[i] == val) {

                // Shift remaining elements to the left
                for (int j = i; j < n - 1; j++) {
                    nums[j] = nums[j + 1];
                }

                // Decrease the logical size
                n--;

                // Check the current index again
                i--;
            }
        }

        return n;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    Solution obj;

    int k = obj.removeElement(nums, val);

    cout << "Removed Element: " << val << endl;
    cout << "Remaining Count: " << k << endl;

    cout << "Array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}
