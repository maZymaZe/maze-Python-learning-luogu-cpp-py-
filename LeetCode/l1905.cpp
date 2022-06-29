class Solution {
   public:
    int n, m, ans = 0, suc, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    void ff(vector<vector<int>>& g1, vector<vector<int>>& g2, int x, int y) {
        g2[x][y] = 0;
        if (g1[x][y] == 0)
            suc = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (g2[nx][ny] == 1) {
                    g2[nx][ny] = 0;
                    ff(g1, g2, nx, ny);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    suc = 1;
                    ff(grid1, grid2, i, j);
                    ans += suc;
                }
            }
        }
        return ans;
    }
};