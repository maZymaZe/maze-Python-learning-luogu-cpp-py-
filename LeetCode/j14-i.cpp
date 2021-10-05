class Solution {
   public:
    int cuttingRope(int n) {
        int dp[60] = {0};
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j <= i - 1; j++) {
                dp[i] = max(dp[i], j * (i - j));
            }
            for (int j = 2; j <= i - 1; j++) {
                dp[i] = max(dp[i], dp[j] * (i - j));
            }
        }
        return dp[n];
    }
};