struct PACK {
    int sx, sy, bx, by;
};
class Solution {
   public:
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        int dp[21][21][21][21] = {0}, vis[21][21][21][21] = {0};
        int sx, sy, bx, by, tx, ty;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S')
                    sx = i, sy = j;
                else if (grid[i][j] == 'B')
                    bx = i, by = j;
                else if (grid[i][j] == 'T')
                    tx = i, ty = j;
            }
        }
        deque<PACK> q;
        q.push_back({sx, sy, bx, by});
        vis[sx][sy][bx][by] = 1;
        while (!q.empty()) {
            PACK p = q.front();
            q.pop_front();
            sx = p.sx, sy = p.sy, bx = p.bx, by = p.by;
            int v = dp[sx][sy][bx][by];
            for (int i = 0; i < 4; i++) {
                int nx = sx + dx[i], ny = sy + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] != '#') {
                    if (nx == bx && ny == by) {
                        int nbx = bx + dx[i], nby = by + dy[i];
                        if (nbx >= 0 && nby >= 0 && nbx < n && nby < m &&
                            grid[nbx][nby] != '#') {
                            if (nbx == tx && nby == ty) {
                                return v + 1;
                            }
                            if (!vis[nx][ny][nbx][nby]) {
                                vis[nx][ny][nbx][nby] = 1;
                                dp[nx][ny][nbx][nby] = v + 1;
                                q.push_back({nx, ny, nbx, nby});
                            }
                        }
                    } else {
                        if (!vis[nx][ny][bx][by]) {
                            vis[nx][ny][bx][by] = 1;
                            dp[nx][ny][bx][by] = v;
                            q.push_front({nx, ny, bx, by});
                        }
                    }
                }
            }
        }
        return -1;
    }
};