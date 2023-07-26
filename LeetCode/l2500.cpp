class Solution {
   public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& v : grid)
            sort(v.begin(), v.end());
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < m; i++) {
            int x = grid[0][i];
            for (int j = 0; j < n; j++) {
                x = max(x, grid[j][i]);
            }
            ans += x;
        }
        return ans;
    }
};