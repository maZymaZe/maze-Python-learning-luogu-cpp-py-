class Solution {
   public:
    int minCost(int maxTime,
                vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size(), l = edges.size(), INF = 0x3f3f3f3f;
        vector<vector<int>> dp(maxTime + 1, vector<int>(n, INF));
        dp[0][0] = passingFees[0];
        for (int i = 1; i <= maxTime; i++) {
            for (int j = 0; j < n; j++)
                dp[i][j] = dp[i - 1][j];
            for (int j = 0; j < l; j++) {
                if (i >= edges[j][2]) {
                    dp[i][edges[j][1]] = min(dp[i][edges[j][1]],
                                             dp[i - edges[j][2]][edges[j][0]] +
                                                 passingFees[edges[j][1]]);
                    dp[i][edges[j][0]] = min(dp[i][edges[j][0]],
                                             dp[i - edges[j][2]][edges[j][1]] +
                                                 passingFees[edges[j][0]]);
                }
            }
        }
        if (dp[maxTime][n - 1] >= INF)
            return -1;
        return dp[maxTime][n - 1];
    }
};