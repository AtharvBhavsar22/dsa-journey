#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
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

    cout << "Removed elements: " << val << endl;
    cout << "Remaining count: " << k << endl;
    cout << "Array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
