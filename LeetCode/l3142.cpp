class Solution {
   public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != grid[i - 1][j])
                    return false;
            }
        }
        for (int j = 1; j < m; j++) {
            if (grid[0][j] == grid[0][j - 1])
                return false;
        }
        return true;
    }
};