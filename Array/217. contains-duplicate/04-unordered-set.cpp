
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        // Check whether the element already exists
        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            // Insert the element
            seen.insert(x);
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    cout << boolalpha << sol.containsDuplicate(nums);

    return 0;
}
