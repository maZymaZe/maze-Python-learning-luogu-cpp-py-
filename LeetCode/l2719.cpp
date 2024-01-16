class Solution {
   public:
    long long dp[24][240] = {0}, MOD = 1e9 + 7;
    long long query(string num, int min_sum, int max_sum) {
        int l = num.size(), ps = 0;
        long long tot = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < num[i] - '0'; j++) {
                if (ps + j > max_sum)
                    continue;
                int lf = min(max_sum - ps - j, 239);
                int rg = min(239, max(0, min_sum - ps - j));
                tot += (dp[l - i - 1][lf] -
                        ((rg == 0) ? 0 : dp[l - i - 1][rg - 1]));
                tot = (tot + MOD) % MOD;
            }
            ps += (num[i] - '0');
        }
        if (ps >= min_sum && ps <= max_sum)
            tot = (tot + 1) % MOD;
        return tot;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        dp[0][0] = 1;
        for (int i = 1; i < 24; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 240; k++) {
                    if (j + k < 240) {
                        dp[i][j + k] += dp[i - 1][k];
                        dp[i][j + k] %= MOD;
                    }
                }
            }
        }
        for (int i = 0; i < 24; i++) {
            for (int k = 1; k < 240; k++) {
                dp[i][k] += dp[i][k - 1];
                dp[i][k] %= MOD;
            }
        }
        long long t2, t3;
        t2 = query(num1, min_sum, max_sum), t3 = query(num2, min_sum, max_sum);
        int tt = 0;
        for (char c : num1) {
            tt += c - '0';
        }
        if (tt <= max_sum && tt >= min_sum)
            t3++;
        return (t3 - t2 + MOD) % MOD;
    }
};