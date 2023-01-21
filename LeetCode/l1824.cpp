class Solution {
   public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[2][3] = {0};
        dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 1;
        int l = obstacles.size();
        for (int i = 1; i < l; i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) {
                    dp[i & 1][j] = 0x3f3f3f3f;
                } else {
                    dp[i & 1][j] = dp[(i & 1) ^ 1][j];
                }
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) {
                    continue;
                } else {
                    for (int k = 0; k < 3; k++) {
                        dp[i & 1][j] =
                            min(dp[i & 1][j], dp[(i & 1)][k] + (k != j));
                    }
                }
            }
        }
        l--;
        return min({dp[l & 1][0], dp[l & 1][1], dp[l & 1][2]});
    }
};