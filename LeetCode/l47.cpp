class Solution {
   public:
    int l;
    vector<int> vis;
    vector<vector<int>> ans;
    vector<int> perm;
    void backtrack(vector<int>& nums, int idx) {
        if (idx == l) {
            ans.emplace_back(perm);
            return;
        }
        for (int i = 0; i < l; i++) {
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(nums, idx + 1);
            vis[i] = 0;
            perm.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        l = nums.size();

        vis.permize(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};