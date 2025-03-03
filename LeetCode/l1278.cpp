class Solution {
   public:
    int palindromePartition(string s, int k) {
        int l = s.size();
        vector<vector<int>> f1(l, vector<int>(l));
        for (int i = 0; i < l; i++) {
            for (int j = i; j < l; j++) {
                int x = 0, y = 0;
                while (i + y <= j - y) {
                    if (s[i + y] != s[j - y])
                        x++;
                    y++;
                }
                f1[i][j] = x;
            }
        }
        vector<vector<int>> dp(2, vector<int>(l, 0x3f3f3f3f));
        for (int i = 0; i < l; i++) {
            dp[1][i] = f1[0][i];
        }
        for (int i = 2; i <= k; i++) {
            for (int j = i - 1; j < l; j++) {
                dp[i & 1][j] = 0x3f3f3f3f;
                for (int t = 0; t < j; t++) {
                    dp[i & 1][j] =
                        min(dp[i & 1][j], dp[(i & 1) ^ 1][t] + f1[t + 1][j]);
                }
            }
        }
        return dp[k & 1][l - 1];
    }
};