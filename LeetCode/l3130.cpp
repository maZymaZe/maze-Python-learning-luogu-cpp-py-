class Solution {
   public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1)),
            dp1(zero + 1, vector<int>(one + 1));
        int MOD = 1e9 + 7;
        limit++;
        for (int i = 1; i <= zero && i < limit; i++)
            dp0[i][0] = 1;
        for (int i = 1; i <= one && i < limit; i++)
            dp1[0][i] = 1;
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                dp0[i][j] += dp0[i - 1][j];
                dp0[i][j] %= MOD;
                if (i - limit >= 0) {
                    dp0[i][j] += MOD - dp1[i - limit][j], dp0[i][j] %= MOD;
                }

                dp0[i][j] += dp1[i - 1][j];
                dp0[i][j] %= MOD;

                dp1[i][j] += dp1[i][j - 1];
                dp1[i][j] %= MOD;
                if (j - limit >= 0) {
                    dp1[i][j] += MOD - dp0[i][j - limit], dp1[i][j] %= MOD;
                }

                dp1[i][j] += dp0[i][j - 1];
                dp1[i][j] %= MOD;
            }
        }
        return (dp0[zero][one] + dp1[zero][one]) % MOD;
    }
};