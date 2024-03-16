class Solution {
   public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j][i & 1] = 0;
                if (j && grid[j][i] > grid[j - 1][i - 1] &&
                    (i == 1 || dp[j - 1][(i & 1) ^ 1])) {
                    dp[j][i & 1] =
                        max(dp[j][i & 1], dp[j - 1][(i & 1) ^ 1] + 1);
                }
                if (grid[j][i] > grid[j][i - 1] &&
                    (i == 1 || dp[j][(i & 1) ^ 1])) {
                    dp[j][i & 1] = max(dp[j][i & 1], dp[j][(i & 1) ^ 1] + 1);
                }
                if (j + 1 < n && grid[j][i] > grid[j + 1][i - 1] &&
                    (i == 1 || dp[j + 1][(i & 1) ^ 1])) {
                    dp[j][i & 1] =
                        max(dp[j][i & 1], dp[j + 1][(i & 1) ^ 1] + 1);
                }
                ans = max(ans, dp[j][i & 1]);
            }
        }
        return ans;
    }
};