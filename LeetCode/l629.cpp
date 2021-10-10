class Solution {
   public:
    int dp[1002][1002], s[1002][1002];
    int MOD = 1e9 + 7;

    int kInversePairs(int n, int k) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 1) {
                    if (j == 0)
                        dp[i][j] = 1, s[i][j] = 1;
                    else
                        s[i][j] = s[i][j - 1] + dp[i][j];
                } else {
                    if (j == 0)
                        dp[i][j] = 1, s[i][j] = 1;
                    else {
                        if (j <= (i * (i - 1) / 2)) {
                            dp[i][j] = s[i - 1][j] -
                                       (j - i >= 0 ? s[i - 1][j - i] : 0);
                        } else
                            dp[i][j] = 0;
                        dp[i][j] %= MOD;
                        dp[i][j] += MOD;
                        dp[i][j] %= MOD;
                        s[i][j] = s[i][j - 1] + dp[i][j];
                        s[i][j] %= MOD;
                    }
                }
            }
        }
        return dp[n][k];
    }
};