class Solution {
   public:
    bool possibleToStamp(vector<vector<int>>& grid,
                         int stampHeight,
                         int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> sum(n + 2, vector<int>(m + 2));
        auto diff = sum;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                            grid[i - 1][j - 1];
            }
        }
        for (int i = 1; i + stampHeight - 1 <= n; i++) {
            for (int j = 1; j + stampWidth - 1 <= m; j++) {
                int nx = i + stampHeight - 1, ny = j + stampWidth - 1;
                if (sum[nx][ny] - sum[nx][j - 1] - sum[i - 1][ny] +
                        sum[i - 1][j - 1] ==
                    0) {
                    diff[i][j]++;
                    diff[i][ny + 1]--;
                    diff[nx + 1][j]--;
                    diff[nx + 1][ny + 1]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                diff[i][j] +=
                    diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
                if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
};