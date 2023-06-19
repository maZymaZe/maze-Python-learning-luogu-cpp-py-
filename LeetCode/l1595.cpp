class Solution {
   public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size(), INF = 0x3f3f3f3f;
        int ss = (1 << m);
        vector<vector<int>> dp(n + 1, vector<int>(ss, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < ss; s++) {
                for (int k = 0; k < m; k++) {
                    if ((s & (1 << k)) == 0)
                        continue;
                    dp[i][s] =
                        min(dp[i][s], dp[i][s ^ (1 << k)] + cost[i - 1][k]);
                    dp[i][s] = min(dp[i][s], dp[i - 1][s] + cost[i - 1][k]);
                    dp[i][s] =
                        min(dp[i][s], dp[i - 1][s ^ (1 << k)] + cost[i - 1][k]);
                }
            }
        }
        return dp[n][ss - 1];
    }
};