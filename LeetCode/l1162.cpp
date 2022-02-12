class Solution {
   public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), ans = 0, dx[4] = {0, 0, 1, -1},
            dy[4] = {1, -1, 0, 0};
        queue<int> x, y, z;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    x.push(i), y.push(j), z.push(0);
                }
            }
        }
        if (x.size() == 0 || x.size() == n * n)
            return -1;
        while (!x.empty()) {
            int tx = x.front(), ty = y.front(), tz = z.front();
            x.pop(), y.pop(), z.pop();
            ans = max(ans, tz);
            for (int i = 0; i < 4; i++) {
                int nx = tx + dx[i], ny = ty + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        x.push(nx), y.push(ny), z.push(tz + 1);
                    }
                }
            }
        }
        return ans;
    }
};