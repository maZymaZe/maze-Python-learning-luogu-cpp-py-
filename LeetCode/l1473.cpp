class Solution {
   public:
    int dp[102][102][22] = {0};
    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int m,
                int n,
                int target) {
        memset(dp, 0x3f, sizeof(dp));
        if (houses[0]) {
            dp[0][1][houses[0]-1] = 0;
        } else {
            for (int i = 0; i < n; i++) {
                dp[0][1][i] = cost[0][i];
            }
        }
        for (int i = 1; i < m; i++) {
            if (houses[i]) {
                for (int j = 1; j <= target; j++) {
                    for (int k = 0; k < n; k++) {
                        if (k + 1 == houses[i]) {
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                        } else {
                            dp[i][j][houses[i] - 1] = min(
                                dp[i][j][houses[i] - 1], dp[i - 1][j - 1][k]);
                        }
                    }
                }
            } else {
                for (int j = 1; j <= target; j++) {
                    for (int k = 0; k < n; k++) {
                        for (int l = 0; l < n; l++) {
                            if (k == l) {
                                dp[i][j][k] = min(dp[i][j][k],
                                                  dp[i - 1][j][k] + cost[i][k]);
                            } else {
                                dp[i][j][k] =
                                    min(dp[i][j][k],
                                        dp[i - 1][j - 1][l] + cost[i][k]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[m - 1][target][i]);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};