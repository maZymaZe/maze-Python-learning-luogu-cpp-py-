class Solution {
   public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = n; j > 0; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] > INT_MAX ? 0 : dp[j - 1] + dp[j];
                }
            }
        }
        return dp[n];
    }
};