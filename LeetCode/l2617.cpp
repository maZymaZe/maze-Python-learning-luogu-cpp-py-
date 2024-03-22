class Solution {
   public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (n == 1 && m == 1)
            return 1;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        auto xWarp = dp;
        auto yWarp = dp;
        queue<int> qx, qy, qz;
        dp[0][0] = 0;
        qx.push(0), qy.push(0), qz.push(0);
        while (!qx.empty()) {
            int tx = qx.front(), ty = qy.front(), tz = qz.front();
            qx.pop(), qy.pop(), qz.pop();
            int k = grid[tx][ty];
            int mx = min(n - 1, tx + k);
            int my = min(m - 1, ty + k);
            for (int nx = tx + 1; nx <= mx; nx++) {
                int ny = ty, nz = tz + 1;
                if (xWarp[nx][ny] > 0) {
                    nx = xWarp[nx][ny];
                    if (nx > mx)
                        break;
                }
                if (dp[nx][ny] == -1) {
                    if (nx == n - 1 && ny == m - 1)
                        return nz + 1;
                    qx.push(nx), qy.push(ny), qz.push(nz);
                    dp[nx][ny] = nz;
                    xWarp[nx][ny] = mx;
                }
            }
            for (int ny = ty + 1; ny <= my; ny++) {
                int nx = tx, nz = tz + 1;
                if (yWarp[nx][ny] > 0) {
                    ny = yWarp[nx][ny];
                    if (ny > my)
                        break;
                }
                if (dp[nx][ny] == -1) {
                    if (nx == n - 1 && ny == m - 1)
                        return nz + 1;
                    qx.push(nx), qy.push(ny), qz.push(nz);
                    dp[nx][ny] = nz;
                    yWarp[nx][ny] = my;
                }
            }
        }
        return -1;
    }
};