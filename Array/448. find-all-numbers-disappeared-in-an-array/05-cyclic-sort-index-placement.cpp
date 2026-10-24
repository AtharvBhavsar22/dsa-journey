class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;

        for(auto& c : nums) {

            while(nums[c-1] != c) {
                swap(c, nums[c-1]);
            }
        }

        for(int i = 1; i <= size(nums); i++) {

            if(i != nums[i-1]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
