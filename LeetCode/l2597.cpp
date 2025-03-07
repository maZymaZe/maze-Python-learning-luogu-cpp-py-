class Solution {
   public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int l = nums.size(), vis[1002] = {0}, ans = -1;
        function<void(int)> dfs = [&](int pos) {
            if (pos == l) {
                ans++;
                return;
            }
            dfs(pos + 1);
            if (nums[pos] + k <= 1000 && vis[nums[pos] + k])
                return;
            if (nums[pos] - k >= 0 && vis[nums[pos] - k])
                return;
            vis[nums[pos]]++;
            dfs(pos + 1);
            vis[nums[pos]]--;
        };
        dfs(0);
        return ans;
    }
};