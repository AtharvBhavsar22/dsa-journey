
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;

        // Mark elements not equal to val
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                nums[i] = nums[i] * -1;
                count++;
            }
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Restore the marked elements
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * -1;
        }

        return count;
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
