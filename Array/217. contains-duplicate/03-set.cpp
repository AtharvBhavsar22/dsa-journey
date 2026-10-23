
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Store only unique elements
        set<int> uniqueNums(nums.begin(), nums.end());

        // Compare original size with unique size
        return nums.size() > uniqueNums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    cout << boolalpha << sol.containsDuplicate(nums);

    return 0;
}
