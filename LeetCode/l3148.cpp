class Solution {
   public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = grid[0][1] - grid[0][0];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int t = grid[i][j], ma = -1e6;
                if (i + 1 < n)
                    ma = max(ma, grid[i + 1][j]);
                if (j + 1 < m)
                    ma = max(ma, grid[i][j + 1]);
                ans = max(ma - t, ans);
                ma = max(ma, t);
                grid[i][j] = ma;
            }
        }
        return ans;
    }
};