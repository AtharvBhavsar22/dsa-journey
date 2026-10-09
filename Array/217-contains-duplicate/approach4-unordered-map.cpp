// LeetCode 217: Contains Duplicate
// Approach: Unordered Map
// Time Complexity: O(n) average
// Space Complexity: O(n)

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;

        // Check each element in the array.
        for (int x : nums) {

            // If x already exists in the map, a duplicate is found.
            if (seen.count(x)) {
                return true;
            }

            // Store x to track its occurrence.
            seen[x] = 1;
        }

        // No duplicates were found.
        return false;
    }
};