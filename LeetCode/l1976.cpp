class Solution {
   public:
    int countPaths(int n, vector<vector<int>>& roads) {
        if (n == 1)
            return 1;
        vector<vector<long long>> f(n,
                                    vector<long long>(n, 0x3f3f3f3f3f3f3f3fll));
        vector<vector<long long>> c(n, vector<long long>(n, 0));
        const int MOD = 1e9 + 7;
        for (const auto& x : roads) {
            f[x[0]][x[1]] = x[2];
            f[x[1]][x[0]] = x[2];
            c[x[0]][x[1]] = c[x[1]][x[0]] = 1;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    long long dis = f[i][k] + f[k][j];
                    if (dis < f[i][j]) {
                        f[i][j] = dis;
                        c[i][j] = c[i][k] * c[k][j] % MOD;
                    } else if (dis == f[i][j]) {
                        c[i][j] = (c[i][j] + c[i][k] * c[k][j] % MOD) % MOD;
                    }
                }
            }
        }
        return c[0][n - 1];
    }
};