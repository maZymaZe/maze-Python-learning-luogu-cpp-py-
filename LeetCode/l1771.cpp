class Solution {
   public:
    int longestPalindrome(string word1, string word2) {
        string w = word1 + word2;
        int l1 = word1.length(), l2 = word2.length(), l = w.length();
        vector<vector<int> > dp(l, vector<int>(l));
        int res = w[l1] == w[l1 - 1] ? 2 : 0;
        for (int i = 0; i < l; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < l - 1; i++) {
            dp[i][i + 1] = w[i] == w[i + 1] ? 2 : 1;
        }
        for (int k = 2; k < l; k++) {
            for (int i = 0; i + k < l; i++) {
                int j = i + k;
                if (w[j] == w[i]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (i < l1 && j >= l1)
                        res = max(res, dp[i][j]);
                } else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return res;
    }
};