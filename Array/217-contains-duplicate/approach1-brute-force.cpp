// LeetCode 217: Contains Duplicate
// Approach: Brute Force (Nested Loops)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Compare each element with all subsequent elements.
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {

                // Return true if a duplicate pair is found.
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        // Return false if all elements are distinct.
        return false;
    }
};