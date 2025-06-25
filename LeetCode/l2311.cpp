class Solution {
   public:
    int longestSubsequence(string s, int k) {
        long long dp[1002][1002] = {0};
        memset(dp, 0x3f, sizeof(dp));
        int l = s.size();
        dp[0][0] = 0;
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j)
                    dp[i][j] =
                        min(dp[i][j], (dp[i - 1][j - 1] << 1) + s[i - 1] - '0');
            }
        }
        for (int j = l; j >= 0; j--) {
            if (dp[l][j] <= k) {
                return j;
            }
        }
        return -1;
    }
};