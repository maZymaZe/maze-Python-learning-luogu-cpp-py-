class Solution {
   public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        queue<int> qx, qy, qqx, qqy, qz;
        int f = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    qqx.push(i), qqy.push(j);
                    qx.push(i), qy.push(j), qz.push(0);
                    f = 1;
                    break;
                }
            }
            if (f == 1)
                break;
        }
        while (!qqx.empty()) {
            int x = qqx.front(), y = qqy.front();
            grid[x][y] = 2;
            qqx.pop(), qqy.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    qx.push(nx);
                    qy.push(ny);
                    qz.push(0);
                    qqx.push(nx);
                    qqy.push(ny);
                }
            }
        }
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), z = qz.front();
            grid[x][y] = 3;
            qx.pop(), qy.pop(), qz.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (grid[nx][ny] == 1) {
                    return z;
                } else if (grid[nx][ny] == 0) {
                    qx.push(nx), qy.push(ny), qz.push(z + 1);
                    grid[nx][ny] = 3;
                }
            }
        }
        return -1;
    }
};