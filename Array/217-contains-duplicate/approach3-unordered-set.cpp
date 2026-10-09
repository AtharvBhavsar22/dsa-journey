// LeetCode 217: Contains Duplicate
// Approach: Unordered Set
// Time Complexity: O(n) average
// Space Complexity: O(n)

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        // Check each element in the array.
        for (int x : nums) {

            // If x already exists, a duplicate is found.
            if (seen.count(x)) {
                return true;
            }

            // Store x to track previously seen elements.
            seen.insert(x);
        }

        // No duplicates were found.
        return false;
    }
};