class Solution {
   public:
    string stoneGameIII(vector<int>& stoneValue) {
        int l = stoneValue.size();
        vector<int> tot(l+1), dp(l+1);
        tot[l - 1] = stoneValue[l - 1];
        for (int i = l - 2; i >= 0; i--) {
            tot[i] = tot[i + 1] + stoneValue[i];
        }
        dp[l - 1] = stoneValue[l - 1];
        for (int i = l - 2; i >= 0; i--) {
            dp[i] = stoneValue[i] + tot[i + 1] - dp[i + 1];
            if (i + 2 <= l) {
                dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] -
                                       dp[i + 2] + tot[i + 2]);
            }
            if (i + 3 <= l) {
                dp[i] =
                    max(dp[i], stoneValue[i] + stoneValue[i + 1] +
                                   stoneValue[i + 2] - dp[i + 3] + tot[i + 3]);
            }
        }
        if (dp[0] > tot[0]-dp[0])
            return "Alice";
        if (dp[0] == tot[0]-dp[0])
            return "Tie";
        return "Bob";
    }
};