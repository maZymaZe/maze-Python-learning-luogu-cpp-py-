class Solution {
   public:
    int dp[100009][5][5][5];
    int maxGroupNumber(vector<int>& tiles) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0][0][1] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    for (int l = 0; l < 5; l++) {
                        if (dp[i - 1][j][k][l] == -1)
                            continue;
                        if (tiles[i] == tiles[i - 1]) {
                            dp[i][j][k][l] =
                                max(dp[i][j][k][l], dp[i - 1][j][k][l]);
                            if (l != 4) {
                                dp[i][j][k][l + 1] =
                                    max(dp[i][j][k][l + 1], dp[i - 1][j][k][l]);
                            }
                            if (l + 1 >= 3) {
                                dp[i][j][k][l - 2] = max(
                                    dp[i][j][k][l - 2], dp[i - 1][j][k][l] + 1);
                            }
                            if (min(l + 1, min(j, k)) >= 1) {
                                dp[i][j - 1][k - 1][l] =
                                    max(dp[i][j - 1][k - 1][l],
                                        dp[i - 1][j][k][l] + 1);
                            }
                        } else if (tiles[i - 1] + 1 == tiles[i]) {
                            dp[i][k][l][1] =
                                max(dp[i][k][l][1], dp[i - 1][j][k][l]);
                            if (min(k, l) >= 1) {
                                dp[i][k - 1][l - 1][0] =
                                    max(dp[i][k - 1][l - 1][0],
                                        dp[i - 1][j][k][l] + 1);
                            }
                        } else if (tiles[i - 1] + 2 == tiles[i]) {
                            dp[i][l][0][1] =
                                max(dp[i][l][0][1], dp[i - 1][j][k][l]);
                        } else {
                            dp[i][0][0][1] =
                                max(dp[i][0][0][1], dp[i - 1][j][k][l]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    ans = max(ans, dp[n - 1][i][j][k]);
                }
            }
        }
        return ans;
    }
};