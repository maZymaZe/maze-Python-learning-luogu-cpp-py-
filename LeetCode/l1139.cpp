class Solution {
   public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> w, a(n, vector<int>(m));
        w = a;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i)
                    w[i][j] = (grid[i][j] == 1);
                else {
                    if (grid[i][j] == 1)
                        w[i][j] = w[i - 1][j] + 1;
                    else
                        w[i][j] = 0;
                }
                if (!j)
                    a[i][j] = (grid[i][j] == 1);
                else {
                    if (grid[i][j] == 1)
                        a[i][j] = a[i][j - 1] + 1;
                    else
                        a[i][j] = 0;
                }
            }
        }
        int me = min(n, m);
        for (int e = me; e > 0; e--) {
            for (int x = 0; x + e - 1 < n; x++) {
                for (int y = 0; y + e - 1 < m; y++) {
                    if (a[x][y + e - 1] >= e && w[x + e - 1][y] >= e &&
                        w[x + e - 1][y + e - 1] >= e &&
                        a[x + e - 1][y + e - 1] >= e) {
                        return e * e;
                    }
                }
            }
        }
        return 0;
    }
};