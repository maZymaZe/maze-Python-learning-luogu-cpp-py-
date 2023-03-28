class Solution {
   public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            dp[i][m] = n - i;
        }
        for (int i = 0; i < m; ++i) {
            dp[n][i] = m - i;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        string res;
        int t1 = 0, t2 = 0;
        while (t1 < n && t2 < m) {
            if (str1[t1] == str2[t2]) {
                res += str1[t1];
                ++t1;
                ++t2;
            } else if (dp[t1 + 1][t2] == dp[t1][t2] - 1) {
                res += str1[t1];
                ++t1;
            } else if (dp[t1][t2 + 1] == dp[t1][t2] - 1) {
                res += str2[t2];
                ++t2;
            }
        }
        if (t1 < n) {
            res += str1.substr(t1);
        } else if (t2 < m) {
            res += str2.substr(t2);
        }
        return res;
    }
};
