class Solution {
   public:
    int dp[60][60][60] = {0}, vis[60][60][60] = {0}, MOD = 1e9 + 7;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, M, N;
    int dfs(int x, int y, int t) {
        if (vis[x][y][t])
            return dp[x][y][t];
        vis[x][y][t] = 1;
        if (t == 0)
            return dp[x][y][t] = 0;
        if (t == 1) {
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx == M || ny < 0 || ny == N)
                    cnt++;
            }
            return dp[x][y][t] = cnt;
        }
        long long tot = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx == M || ny < 0 || ny == N)
                continue;
            tot += dfs(nx, ny, t - 1);
            tot %= MOD;
        }
        return dp[x][y][t] = tot;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M = m, N = n;
        long long ans = 0;
        for (int i = 0; i <= maxMove; i++) {
            ans = ans + dfs(startRow, startColumn, i);
            ans %= MOD;
        }
        return ans;
    }
};