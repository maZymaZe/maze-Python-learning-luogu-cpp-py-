class Solution {
   public:
    int n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    void ff(vector<vector<char>>& grid, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (grid[nx][ny] == '1')
                grid[nx][ny] = '2', ff(grid, nx, ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1')
                    ff(grid, i, j), ans++;
            }
        }
        return ans;
    }
};