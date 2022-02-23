class Solution {
   public:
    int n, m;
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<int> ans(m);
        int x, y, z;
        for (int i = 0; i < m; i++) {
            x = 0, y = i, z = 0;
            while (x != n - 1 || z != 1) {
                if (z == 0) {
                    if (grid[x][y] == 1) {
                        if (y + 1 < m && grid[x][y + 1] == 1) {
                            y++, z = 1;
                        } else
                            break;
                    } else {
                        if (y > 0 && grid[x][y - 1] == -1) {
                            y--, z = 1;
                        } else
                            break;
                    }
                } else {
                    z = 0, x++;
                }
            }
            if (x == n - 1 && z == 1) {
                ans[i] = y;
            } else
                ans[i] = -1;
        }
        return ans;
    }
};