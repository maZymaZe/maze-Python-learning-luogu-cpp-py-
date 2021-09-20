class Solution {
   public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mx = 0;
                if (i)
                    mx = max(grid[i - 1][j], mx);
                if (j)
                    mx = max(grid[i][j - 1], mx);
                grid[i][j] += mx;
            }
        }
        return grid[n - 1][m - 1];
    }
};