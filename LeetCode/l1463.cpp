class Solution {
   public:
    int cherryPickup(vector<vector<int>>& grid) {
        int dp[80][80][80] = {0};
        memset(dp, -1, sizeof(dp));
        int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1},
            dy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};
        int n = grid.size(), m = grid[0].size();
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = j + 1; k < m; k++) {
                    for (int l = 0; l < 9; l++) {
                        int px = j + dx[l], py = k + dy[l];
                        if (px >= py || px < 0 || py >= m)
                            continue;
                        if (dp[i - 1][px][py] != -1) {
                            dp[i][j][k] =
                                max(dp[i][j][k], dp[i - 1][px][py] +
                                                     grid[i][j] + grid[i][k]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++)
                ans = max(ans, dp[n - 1][i][j]);
        }
        return ans;
    }
};