class Solution {
   public:
    int n, m;
    int ti(int x, int y) { return x * m + y; }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int bs = ti(i, j) + k;
                bs %= (n * m);
                ans[bs / m][bs % m] = grid[i][j];
            }
        }
        return ans;
    }
};