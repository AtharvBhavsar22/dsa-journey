class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<int> ans;

        for (int i = 1; i <= n; i++) {

            if (!binary_search(begin(nums), end(nums), i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
