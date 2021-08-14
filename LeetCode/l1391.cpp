class Solution {
   public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<int> qx, qy;
        vector<vector<int>> vis(n, vector<int>(m));
        qx.push(0), qy.push(0);
        while (!qx.empty()) {
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            if (x < 0 || y < 0 || x >= n || y >= m)
                continue;
            if (vis[x][y])
                continue;
            vis[x][y] = true;
            if (grid[x][y] == 1) {
                if ((y > 0) && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 ||
                                grid[x][y - 1] == 1))
                    qx.push(x), qy.push(y - 1);
                if (y < m - 1 && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 ||
                                  grid[x][y + 1] == 1))
                    qx.push(x), qy.push(y + 1);
            } else if (grid[x][y] == 2) {
                if (x > 0 && (grid[x - 1][y] == 4 || grid[x - 1][y] == 3 ||
                              grid[x - 1][y] == 2))
                    qx.push(x - 1), qy.push(y);
                if (x < n - 1 && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 ||
                                  grid[x + 1][y] == 2))
                    qx.push(x + 1), qy.push(y);
            } else if (grid[x][y] == 3) {
                if (x < n - 1 && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 ||
                                  grid[x + 1][y] == 2))
                    qx.push(x + 1), qy.push(y);
                if (y > 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 ||
                              grid[x][y - 1] == 1))
                    qx.push(x), qy.push(y - 1);
            } else if (grid[x][y] == 4) {
                if (y < m - 1 && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 ||
                                  grid[x][y + 1] == 1))
                    qx.push(x), qy.push(y + 1);
                qx.push(x), qy.push(y + 1);
                if (x < n - 1 && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 ||
                                  grid[x + 1][y] == 2))
                    qx.push(x + 1), qy.push(y);
            } else if (grid[x][y] == 5) {
                if (x > 0 && (grid[x - 1][y] == 4 || grid[x - 1][y] == 3 ||
                              grid[x - 1][y] == 2))
                    qx.push(x - 1), qy.push(y);
                if (y > 0 && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 ||
                              grid[x][y - 1] == 1))
                    qx.push(x), qy.push(y - 1);
            } else if (grid[x][y] == 6) {
                if (x > 0 && (grid[x - 1][y] == 4 || grid[x - 1][y] == 3 ||
                              grid[x - 1][y] == 2))
                    qx.push(x - 1), qy.push(y);
                if (y < m - 1 && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 ||
                                  grid[x][y + 1] == 1))
                    qx.push(x), qy.push(y + 1);
            }
        }
        return vis[n - 1][m - 1];
    }
};