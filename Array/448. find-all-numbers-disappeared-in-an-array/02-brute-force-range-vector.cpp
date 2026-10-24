class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> notSeen;
        vector<int> range;

        for (int i = 1; i <= n; i++) {
            range.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (find(nums.begin(), nums.end(), range[i]) == nums.end()) {
                notSeen.push_back(range[i]);
            }
        }

        return notSeen;
    }
};
