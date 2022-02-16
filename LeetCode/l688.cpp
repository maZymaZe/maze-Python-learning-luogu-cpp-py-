
class Solution {
   public:
    int nn;
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1},
        dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
    double dp[25][25][101] = {0};
    double dfs(int x, int y, int z) {
        if (z == 0) {
            return 1;
        }
        if (dp[x][y][z] > 1e-6)
            return dp[x][y][z];
        double tot = 0;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < nn && ny < nn) {
                tot += dfs(nx, ny, z - 1) / 8;
            }
        }
        dp[x][y][z] = tot;
        return tot;
    }
    double knightProbability(int n, int k, int row, int column) {
        nn = n;
        return dfs(row, column, k);
    }
};