class Solution {
   public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[2][2005] = {0};
        int l = piles.size();
        for (int i = 0; i < l; i++) {
            int tot = 0, pl = piles[i].size();
            for (int m = 0; m <= k; m++) {
                dp[i & 1][m] = dp[(i & 1) ^ 1][m];
            }
            for (int j = 0; j < pl; j++) {
                tot += piles[i][j];
                for (int m = j + 1; m <= k; m++) {
                    dp[i & 1][m] =
                        max(dp[(i & 1) ^ 1][m - j - 1] + tot, dp[i & 1][m]);
                }
            }
        }
        return dp[(l & 1) ^ 1][k];
    }
};