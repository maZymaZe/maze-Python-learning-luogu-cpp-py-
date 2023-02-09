class Solution {
   public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[16][6][2] = {0}, MOD = 1e9 + 7;
        for (int i = 0; i < 6; i++) {
            dp[1][i][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 6; j++) {
                dp[1][j][i & 1] = 0;
                for (int k = 0; k < 6; k++) {
                    if (j == k)
                        continue;
                    for (int l = 1; l <= 15; l++) {
                        dp[1][j][i & 1] += dp[l][k][(i & 1) ^ 1];
                        dp[1][j][i & 1] %= MOD;
                    }
                }
            }
            for (int j = 0; j < 6; j++) {
                for (int t = 2; t <= rollMax[j]; t++) {
                    dp[t][j][i & 1] = dp[t - 1][j][(i & 1) ^ 1];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 1; j <= rollMax[i]; j++) {
                ans += dp[j][i][n & 1];
                ans %= MOD;
            }
        }
        return ans;
    }
};