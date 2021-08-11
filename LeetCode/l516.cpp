class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int l = s.size(), ans = 0;
        if (l == 0)
            return 0;
        vector<vector<int>> dp(l + 1, vector<int>(l + 1));
        for (int i = 0; i < l; i++) {
            dp[i][i] = 1;
            ans = 1;
        }
        for (int i = 0; i < l - 1; i++) {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = 2, ans = 2;
            else
                dp[i][i + 1] = 1;
        }
        for (int len = 3; len <= l; len++) {
            for (int op = 0; op + len - 1 < l; op++) {
                if (s[op] == s[op + len - 1])
                    dp[op][op + len - 1] =
                        max(dp[op][op + len - 1], dp[op + 1][op + len - 2] + 2);
                dp[op][op + len - 1] =
                    max(dp[op][op + len - 1], dp[op + 1][op + len - 1]);
                dp[op][op + len - 1] =
                    max(dp[op][op + len - 1], dp[op][op + len - 2]);
            }
        }
        return dp[0][l - 1];
    }
};