class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n));
        int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1},
            dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        if (n == 1)
            return 1;
        queue<int> qx, qy, qz;
        qx.push(0), qy.push(0), qz.push(1);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front(), z = qz.front();
            qx.pop(), qy.pop(), qz.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0) {
                    if (nx == n - 1 && ny == n - 1)
                        return z + 1;
                    qx.push(nx), qy.push(ny), qz.push(z + 1);
                }
            }
        }
        return -1;
    }
};