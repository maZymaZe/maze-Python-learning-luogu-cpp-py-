class Solution {
   public:
    void ff(vector<vector<int>>& mp, int x, int y) {
        int n = mp.size(), m = mp[0].size();
        mp[x][y] = 1;
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (mp[nx][ny] == 0) {
                    mp[nx][ny] = 1;
                    ff(mp, nx, ny);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0)
                ff(grid, i, 0);
            if (grid[i][m - 1] == 0)
                ff(grid, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 0)
                ff(grid, 0, i);
            if (grid[n - 1][i] == 0)
                ff(grid, n - 1, i);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0) {
                    ans++;
                    ff(grid, i, j);
                }
            }
        }
        return ans;
    }
};