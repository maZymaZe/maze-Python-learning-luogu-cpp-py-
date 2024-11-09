class NeighborSum {
   public:
    vector<int> x, y;
    int n;
    vector<vector<int>> cp;
    int d1x[4] = {1, 0, 0, -1}, d1y[4] = {0, 1, -1, 0};
    int d2x[4] = {1, 1, -1, -1}, d2y[4] = {1, -1, 1, -1};

    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        cp = grid;
        x.resize(n * n);
        y.resize(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[grid[i][j]] = i, y[grid[i][j]] = j;
            }
        }
    }

    int adjacentSum(int value) {
        int p = x[value], q = y[value];
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nx = p + d1x[i], ny = q + d1y[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                ans += cp[nx][ny];
        }
        return ans;
    }

    int diagonalSum(int value) {
        int p = x[value], q = y[value];
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int nx = p + d2x[i], ny = q + d2y[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                ans += cp[nx][ny];
        }
        return ans;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */