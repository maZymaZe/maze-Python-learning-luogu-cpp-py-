class Solution {
   public:
    int tg, l;
    vector<int> tn;
    vector<vector<int>> dp, vis;
    int dfs(int p, int q) {
        if (p >= q)
            return 0;
        if (vis[p][q])
            return dp[p][q];
        vis[p][q] = 1;
        int ans = 0;
        if (tn[p] + tn[p + 1] == tg)
            ans = max(ans, 1 + dfs(p + 2, q));
        if (tn[q] + tn[q - 1] == tg)
            ans = max(ans, 1 + dfs(p, q - 2));
        if (tn[p] + tn[q] == tg)
            ans = max(ans, 1 + dfs(p + 1, q - 1));
        return dp[p][q] = ans;
    }
    int maxOperations(vector<int>& nums) {
        tn = nums;
        int ans = 1;
        l = nums.size();
        tg = nums[0] + nums[1];
        dp = vis = vector<vector<int>>(l, vector<int>(l));
        ans = max(ans, 1 + dfs(2, l - 1));
        tg = nums[0] + nums[l - 1];
        dp = vis = vector<vector<int>>(l, vector<int>(l));
        ans = max(ans, 1 + dfs(1, l - 2));
        dp = vis = vector<vector<int>>(l, vector<int>(l));
        tg = nums[l - 1] + nums[l - 2];
        ans = max(ans, 1 + dfs(0, l - 3));
        return ans;
    }
};