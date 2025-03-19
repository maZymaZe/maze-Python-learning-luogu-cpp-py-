class Solution {
   public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(1);
        ans[0].push_back(nums[0]);
        int cur = 0, l = nums.size();
        for (int i = 1; i < l; i++) {
            if (nums[i] == nums[i - 1]) {
                cur++;
                if (cur == ans.size())
                    ans.resize(cur + 1);
            } else
                cur = 0;
            ans[cur].push_back(nums[i]);
        }
        return ans;
    }
};