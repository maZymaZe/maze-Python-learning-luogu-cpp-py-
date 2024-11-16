class Solution {
   public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                int t = grid[i][j] + grid[i][m - 1 - j] + grid[n - 1 - i][j] +
                        grid[n - 1 - i][m - 1 - j];
                ans += min(4 - t, t);
            }
        }
        int c1 = 0, c2 = 0, c3 = 0;
        if (n % 2) {
            for (int i = 0; i < m / 2; i++) {
                int t = grid[n / 2][i] + grid[n / 2][m - 1 - i];
                c1 += min(2 - t, t);
                c3 += t;
            }
        }
        if (m % 2) {
            for (int i = 0; i < n / 2; i++) {
                int t = grid[i][m / 2] + grid[n - i - 1][m / 2];
                c1 += min(2 - t, t);
                c3 += t;
            }
        }
        if (n % 2 && m % 2) {
            ans += grid[n / 2][m / 2];
        }
        if (c1 == 0 && c2 == 0 && c3 % 4 == 2) {
            ans += 2;
        }
        return ans + c1 + c2;
    }
};