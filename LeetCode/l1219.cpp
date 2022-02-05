class Solution {
   public:
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, ans = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int z) {
        int n = grid.size(), m = grid[0].size();
        ans = max(ans, z);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (grid[nx][ny]) {
                    int t = grid[nx][ny];
                    grid[nx][ny] = 0;
                    dfs(grid, nx, ny, z + t);
                    grid[nx][ny] = t;
                }
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    int t = grid[i][j];
                    grid[i][j] = 0;

                    dfs(grid, i, j, t);
                    grid[i][j] = t;
                }
            }
        }
        return ans;
    }
};