class Solution {
   public:
    int surfaceArea(vector<vector<int>>& grid) {
        const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int n = grid.size();
        int a = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    a+=2;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        int nv = 0;
                        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                            nv = grid[nx][ny];
                        }
                        a += max(grid[i][j] - nv, 0);
                    }
                }
            }
        }

        return a;
    }
};