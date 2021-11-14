class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m + 1);
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            dp[i] = dp[i - 1] + grid[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            dp[1] += grid[i][0];
            for (int j = 2; j <= m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j - 1];
            }
        }
        return dp[m];
    }
};