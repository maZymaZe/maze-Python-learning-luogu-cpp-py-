class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> vn(n), vm(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j])
                    vn[i]++, vm[j]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] && (vn[i] > 1 || vm[j] > 1))
                    ans++;
            }
        }
        return ans;
    }
};