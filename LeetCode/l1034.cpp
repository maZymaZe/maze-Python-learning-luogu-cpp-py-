class Solution {
   public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    void ff(vector<vector<int>>& grid,
            int x,
            int y,
            int color,
            vector<vector<int>>& vis,
            vector<vector<int>>& grid2) {
        if (vis[x][y])
            return;
        vis[x][y] = 1;
        int n = grid.size(), m = grid[0].size();
        int c2 = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (grid[nx][ny] == grid[x][y]) {
                    ff(grid, nx, ny, color, vis, grid2);
                }
                if (grid2[nx][ny] == grid2[x][y]) {
                    c2++;
                }
            }
        }
        if (c2 != 4)
            grid[x][y] = color;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid,
                                    int row,
                                    int col,
                                    int color) {
        int n = grid.size(), m = grid[0].size();
        auto grid2 = grid;
        vector<vector<int>> vis(n, vector<int>(m));
        ff(grid, row, col, color, vis, grid2);
        return grid;
    }
};