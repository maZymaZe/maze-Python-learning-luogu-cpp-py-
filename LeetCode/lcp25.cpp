class Solution {
   public:
    const long long MOD = 1e9 + 7;
    long long C(int x, int y) {
        long long ret = 1;
        for (int i = 0; i < y; i++)
            ret *= (x - i);
        for (int i = 1; i <= y; i++)
            ret /= i;
        return ret;
    }
    int keyboard(int k, int n) {
        long long dp[200][30] = {0};
        for (int i = 0; i <= 26; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 26; j++) {
                for (int l = 0; l <= k; l++) {
                    if (i >= l)
                        dp[i][j] += dp[i - l][j - 1] * C(i, l), dp[i][j] %= MOD;
                }
            }
        }
        return dp[n][26];
    }
};