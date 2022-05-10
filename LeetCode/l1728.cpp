class Solution {
   public:
    int cj, mj, n, m, cx, cy, mx, my, fx, fy, K = 1000;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int mp[10][10] = {0};
    int dp[4100][1002] = {0};
    int ms(int x, int y, int p, int q) {
        return (x << 9) | (y << 6) | (p << 3) | q;
    }
    int dfs(int x, int y, int p, int q, int k) {
        int st = ms(x, y, p, q);
        if (k == K - 1)
            return dp[st][k] = 1;
        if (x == p && y == q)
            return dp[st][k] = 1;
        if (x == fx && y == fy)
            return dp[st][k] = 0;
        if (p == fx && q == fy)
            return dp[st][k] = 1;
        if (dp[st][k] != -1)
            return dp[st][k];
        if (k & 1) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= cj; j++) {
                    int np = p + dx[i] * j, nq = q + dy[i] * j;
                    if (np < 0 || nq < 0 || np >= n || nq >= m)
                        break;
                    if (mp[np][nq])
                        break;
                    if (dfs(x, y, np, nq, k + 1) == 1)
                        return dp[st][k] = 1;
                }
            }
            return dp[st][k] = 0;
        } else {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j <= mj; j++) {
                    int nx = x + dx[i] * j, ny = y + dy[i] * j;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        break;
                    if (mp[nx][ny])
                        break;
                    if (dfs(nx, ny, p, q, k + 1) == 0)
                        return dp[st][k] = 0;
                }
            }
            return dp[st][k] = 1;
        }
        return -1;
    }
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        cj = catJump, mj = mouseJump;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'C')
                    cx = i, cy = j;
                if (grid[i][j] == 'F')
                    fx = i, fy = j;
                if (grid[i][j] == 'M')
                    mx = i, my = j;
                if (grid[i][j] == '#')
                    mp[i][j] = 1;
            }
        }
        return dfs(mx, my, cx, cy, 0) == 0;
    }
};