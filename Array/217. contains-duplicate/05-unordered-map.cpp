
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        // Check whether the element already exists
        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            // Mark the element as present
            seen[x] = 1;
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

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        // Check whether the element already exists
        for (int x : nums) {
            if (seen.count(x)) {
                return true;
            }

            // Mark the element as present
            seen[x] = 1;
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
