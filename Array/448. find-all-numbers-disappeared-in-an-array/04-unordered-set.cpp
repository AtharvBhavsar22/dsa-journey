class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        vector<int> ans;

        int n = nums.size();

        for (int i = 1; i <= n; i++) {

            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
