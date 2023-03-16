class Solution {
   public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ps;
        ps.push_back(0);
        for (auto i : nums) {
            ps.push_back(ps.back() + i);
        }
        vector<int> ans;
        for (auto i : queries) {
            auto it = upper_bound(ps.begin(), ps.end(), i);
            ans.push_back(it - ps.begin() - 1);
        }
        return ans;
    }
};