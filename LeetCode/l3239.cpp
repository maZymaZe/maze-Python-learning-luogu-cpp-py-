class Solution {
   public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                c1 += (grid[i][j] != grid[i][m - 1 - j]);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                c2 += (grid[i][j] != grid[n - 1 - i][j]);
            }
        }
        return min(c1, c2);
    }
};