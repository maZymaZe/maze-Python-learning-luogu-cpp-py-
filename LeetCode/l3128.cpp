class Solution {
   public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> nc(n), mc(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                nc[i] += grid[i][j];
                mc[j] += grid[i][j];
            }
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    ans += (nc[i] - 1) * (mc[j] - 1);
        return ans;
    }
};