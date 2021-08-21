class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int l = costs.size();
        if (!l)
            return 0;
        int dp[3][2] = {0};
        dp[0][0] = costs[0][0], dp[1][0] = costs[0][1], dp[2][0] = costs[0][2];
        for (int i = 1; i < l; i++) {
            dp[0][i & 1] =
                min(dp[1][(i & 1) ^ 1], dp[2][(i & 1) ^ 1]) + costs[i][0];
            dp[1][i & 1] =
                min(dp[0][(i & 1) ^ 1], dp[2][(i & 1) ^ 1]) + costs[i][1];
            dp[2][i & 1] =
                min(dp[1][(i & 1) ^ 1], dp[0][(i & 1) ^ 1]) + costs[i][2];
        }
        return min(min(dp[0][(l - 1) & 1], dp[1][(l - 1) & 1]),
                   dp[2][(l - 1) & 1]);
    }
};