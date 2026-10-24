class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans;

        for (int i = 1; i <= n; i++) {

            if (find(begin(nums), end(nums), i) == end(nums)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
