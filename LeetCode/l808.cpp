class Solution {
   public:
    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        dp[0][0] = 0.5;
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1.0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] =
                    (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
                     dp[max(0, i - 2)][max(0, j - 2)] +
                     dp[max(0, i - 1)][max(0, j - 3)]) /
                    4.0;
            }
        }
        return dp[n][n];
    }
};
