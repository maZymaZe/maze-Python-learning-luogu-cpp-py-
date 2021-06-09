class Solution {
   public:
    int profitableSchemes(int n,
                          int minProfit,
                          vector<int>& group,
                          vector<int>& profit) {
        int l = group.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(100 + 10));
        const long long MOD = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 0; i < l; i++) {
            for (int k = n; k >=0 ; k--) {
                for (int j = 101; j >= 0; j--) {
                    if (k >= group[i]) {
                        if (j != 101) {
                            if (j >= profit[i])
                                (dp[k][j] += dp[k - group[i]][j - profit[i]]) %=
                                    MOD;
                        } else {
                            for (int m = 101 - profit[i]; m <= 101; m++) {
                                (dp[k][101] += dp[k - group[i]][m]) %= MOD;
                            }
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = minProfit; i <= 101; i++)
            for(int j=0;j<=n; j++)
            (ans += dp[j][i]) %= MOD;
        return ans;
    }
};