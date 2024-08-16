class Solution {
   public:
    int n, m, INF = (1 << 20) - 1;
    vector<unordered_map<int, int>> dp;
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size(), m = andValues.size();
        dp.resize(n * m);
        int res = dfs(0, 0, INF, nums, andValues);
        return res < INF ? res : -1;
    }
    int dfs(int i, int j, int cur, vector<int>& nums, vector<int>& andValues) {
        if (i == n && j == m)
            return 0;
        if (i == n || j == m)
            return INF;
        int key = i * m + j;
        if (dp[key].count(cur))
            return dp[key][cur];
        cur &= nums[i];
        if ((cur & andValues[j]) < andValues[j])
            return INF;
        int res = dfs(i + 1, j, cur, nums, andValues);
        if (cur == andValues[j]) {
            res = min(res, dfs(i + 1, j + 1, INF, nums, andValues)+nums[i]);
        }
        dp[key][cur] = res;
        return res;
    }
};