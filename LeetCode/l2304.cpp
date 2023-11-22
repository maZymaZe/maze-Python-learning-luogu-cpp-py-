class Solution {
   public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 0x3f3f3f3f));
        for (int i = 0; i < m; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[(i & 1)][j] = 0x3f3f3f3f;
                for (int k = 0; k < m; k++) {
                    dp[i & 1][j] =
                        min(dp[i & 1][j], dp[(i & 1) ^ 1][k] +
                                              moveCost[grid[i - 1][k]][j] +
                                              grid[i][j]);
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < m; i++) {
            ans = min(ans, dp[(n - 1) & 1][i]);
        }
        return ans;
    }
};