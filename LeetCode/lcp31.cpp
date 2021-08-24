class Solution {
   public:
    int dp[52][52][2][2][2] = {0}, ok[55][55][2] = {0};
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    bool escapeMaze(vector<vector<string>>& maze) {
        int time = maze.size(), n = maze[0].size(), m = maze[0][0].size();
        dp[0][0][0][0][0] = dp[0][0][0][1][1] = dp[0][0][1][0][0] =
            dp[0][0][1][1][1] = 1;
        ok[0][0][0] = ok[0][0][1] = 1;
        for (int i = 1; i < time; i++) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    dp[x][y][i & 1][1][1] = 0;
                    dp[x][y][i & 1][0][1] = 0;
                    dp[x][y][i & 1][1][0] = 0;
                    dp[x][y][i & 1][0][0] = 0;

                    if (maze[i][x][y] == '.') {
                        dp[x][y][i & 1][1][1] |= dp[x][y][(i & 1) ^ 1][1][1];
                        dp[x][y][i & 1][0][1] |= dp[x][y][(i & 1) ^ 1][0][1];
                        dp[x][y][i & 1][1][0] |= dp[x][y][(i & 1) ^ 1][1][0];
                        dp[x][y][i & 1][0][0] |= dp[x][y][(i & 1) ^ 1][0][0];
                        for (int d = 0; d < 4; d++) {
                            int px = x + dx[d], py = y + dy[d];
                            if (px < 0 || py < 0 || px >= n || py >= m)
                                continue;
                            dp[x][y][i & 1][1][1] |=
                                dp[px][py][(i & 1) ^ 1][1][1];
                            dp[x][y][i & 1][1][0] |=
                                dp[px][py][(i & 1) ^ 1][1][0];
                            dp[x][y][i & 1][0][1] |=
                                dp[px][py][(i & 1) ^ 1][0][1];
                            dp[x][y][i & 1][0][0] |=
                                dp[px][py][(i & 1) ^ 1][0][0];
                        }
                    } else {
                        dp[x][y][i & 1][1][1] = 0;
                        dp[x][y][i & 1][0][1] |= ok[x][y][1];
                        dp[x][y][i & 1][1][0] |= dp[x][y][(i & 1) ^ 1][1][1];
                        dp[x][y][i & 1][0][0] |=
                            (dp[x][y][(i & 1) ^ 1][0][1] || ok[x][y][0]);
                        for (int d = 0; d < 4; d++) {
                            int px = x + dx[d], py = y + dy[d];
                            if (px < 0 || py < 0 || px >= n || py >= m)
                                continue;

                            dp[x][y][i & 1][1][0] |=
                                dp[px][py][(i & 1) ^ 1][1][1];
                            dp[x][y][i & 1][0][1] |= ok[px][py][1];
                            dp[x][y][i & 1][0][0] |=
                                (ok[px][py][0] ||
                                 dp[px][py][(i & 1) ^ 1][0][1]);
                        }
                    }
                }
            }
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    ok[x][y][0] |= dp[x][y][i & 1][1][0];
                    ok[x][y][1] |= dp[x][y][i & 1][1][1];
                }
            }
        }
        return dp[n - 1][m - 1][0][0][0] || dp[n - 1][m - 1][0][0][1] ||
               dp[n - 1][m - 1][0][1][0] || dp[n - 1][m - 1][0][1][1] ||
               dp[n - 1][m - 1][1][0][0] || dp[n - 1][m - 1][1][0][1] ||
               dp[n - 1][m - 1][1][1][0] || dp[n - 1][m - 1][1][1][1];
    }
};