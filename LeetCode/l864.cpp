struct NODE {
    int x, y, k, s;
};
class Solution {
   public:
    int dp[32][32][65];
    int shortestPathAllKeys(vector<string>& grid) {
        memset(dp, -1, sizeof(dp));
        int ans = 0x3f3f3f3f;
        int n = grid.size(), m = grid[0].size(), sx, sy, tg = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    sx = i, sy = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    tg |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        dp[sx][sy][0] = 0;
        queue<NODE> q;
        q.push({sx, sy, 0, 0});
        const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            NODE h = q.front();
            q.pop();
            int x = h.x, y = h.y, k = h.k, s = h.s;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (grid[nx][ny] == '#')
                    continue;
                if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z' &&
                    (k & (1 << (grid[nx][ny] - 'A'))) == 0)
                    continue;
                int nk = k;
                if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                    nk |= (1 << (grid[nx][ny] - 'a'));
                }
                int ns = s + 1;
                if (dp[nx][ny][nk] == -1 || ns < dp[nx][ny][nk]) {
                    dp[nx][ny][nk] = ns;
                    if (nk == tg) {
                        ans = min(ans, ns);
                    }
                    q.push({nx, ny, nk, ns});
                }
            }
        }
        return (ans < 0x3f3f3f3f) ? ans : -1;
    }
};