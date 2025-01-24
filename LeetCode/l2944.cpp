class Solution {
   public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size(), ans = 0x3f3f3f3f;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = prices[0];
        if (n <= 2)
            return dp[1];
        for (int i = 2; i <= n; i++) {
            int mi = 0x3f3f3f3f;
            for (int j = i - 1; j >= 1; j--) {
                if (j + j < i - 1)
                    break;
                mi = min(mi, dp[j]);
            }
            dp[i] = mi + prices[i - 1];
            if (i + i >= n)
                ans = min(ans, dp[i]);
        }
        return ans;
    }
};