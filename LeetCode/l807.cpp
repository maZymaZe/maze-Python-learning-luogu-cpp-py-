class Solution {
   public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> mn(n), mm(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mn[i] = max(mn[i], grid[i][j]);
                mm[j] = max(mm[j], grid[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += min(mn[i], mm[j]) - grid[i][j];
            }
        }
        return ans;
    }
};