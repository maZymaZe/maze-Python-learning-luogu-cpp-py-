class Solution {
   public:
    int dp[2][201][201][2] = {0};
    int numberOfStableArrays(int zero, int one, int limit) {
        dp[1][1][1][0] = dp[1][1][1][1] = 1;
        int l = zero + one, MOD = 1e9 + 7, c[2] = {zero, one}, ans = 0;
        for (int i = 2; i <= l; i++) {
            int cur = (i & 1), pre = ((i & 1) ^ 1);
            memset(dp[cur], 0, sizeof(dp[cur]));
            for (int j = 0; j <= i && j <= 200; j++) {
                for (int k = 0; k <= i && k <= 200; k++) {
                    for (int p = 0; p < 2; p++) {
                        if (j + 1 <= c[p] && k + 1 <= limit)
                            dp[cur][j + 1][k + 1][p] =
                                (dp[cur][j + 1][k + 1][p] + dp[pre][j][k][p]) %
                                MOD;
                        if (i - j <= c[p ^ 1])
                            dp[cur][i - j][1][p ^ 1] =
                                (dp[cur][i - j][1][p ^ 1] + dp[pre][j][k][p]) %
                                MOD;
                    }
                }
            }
        }
        for (int i = 0; i <= 200; i++) {
            for (int j = 0; j <= 200; j++) {
                for (int k = 0; k < 2; k++) {
                    ans += dp[l & 1][i][j][k];
                    ans %= MOD;
                }
            }
        }
        return ans;
    }
};