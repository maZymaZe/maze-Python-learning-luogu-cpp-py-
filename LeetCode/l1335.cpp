class Solution {
   public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int l = jobDifficulty.size();
        if (d > l)
            return -1;
        vector<vector<int>> ma(l, vector<int>(l));
        for (int i = 0; i < l; i++)
            ma[i][i] = jobDifficulty[i];
        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                ma[i][j] = max(ma[i][j - 1], jobDifficulty[j]);
            }
        }
        vector<int> dp(l + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < d; i++) {
            for (int j = l - d + i + 1; j > i; j--) {
                dp[j] = 0x3f3f3f3f;
                for (int k = j - 1; k >= i; k--) {
                    dp[j] = min(dp[j], dp[k] + ma[k][j - 1]);
                }
            }
        }
        return dp[l];
    }
};