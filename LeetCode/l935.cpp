class Solution {
   public:
    int knightDialer(int n) {
        const int MOD = 1e9 + 7;
        int dp[2][10] = {0};
        for (int i = 0; i < 10; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            int x = (i & 1);
            int y = (x ^ 1);
            dp[x][0] = (dp[y][4] + dp[y][6]) % MOD;
            dp[x][1] = (dp[y][6] + dp[y][8]) % MOD;
            dp[x][2] = (dp[y][7] + dp[y][9]) % MOD;
            dp[x][3] = (dp[y][4] + dp[y][8]) % MOD;
            dp[x][4] = ((dp[y][3] + dp[y][9]) % MOD + dp[y][0]) % MOD;
            dp[x][5] = 0;
            dp[x][6] = ((dp[y][1] + dp[y][7]) % MOD + dp[y][0]) % MOD;
            dp[x][7] = (dp[y][2] + dp[y][6]) % MOD;
            dp[x][8] = (dp[y][1] + dp[y][3]) % MOD;
            dp[x][9] = (dp[y][2] + dp[y][4]) % MOD;
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += dp[n & 1][i];
            ans %= MOD;
        }
        return ans;
    }
};