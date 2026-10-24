#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Move consecutive duplicates to the end.
        auto newEnd = unique(nums.begin(), nums.end());

        // Return the number of unique elements in the prefix.
        return newEnd - nums.begin();
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
