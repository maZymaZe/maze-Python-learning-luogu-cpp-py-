class Solution {
   public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n + 1,0x3f3f3f3f));
        for(int i=1;i<=n;i++){
            for (int j = 1; j + i - 1 <= n; j++) {
                for (int k = j; k <= j + i - 1; k++) {
                    if (i == 1)
                        dp[j][j + i - 1] = 0;
                    else {
                        dp[j][j + i - 1] = min(
                            dp[j][j + i - 1],
                            k + max((j < k - 1) ? dp[j][k - 1] : 0,
                                    (k + 1 < j + i - 1) ? dp[k + 1][j + i - 1]
                                                        : 0));
                    }
                }
            }
        }
        return dp[1][n];
    }
};