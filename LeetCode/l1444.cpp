class Solution {
   public:
    int dp[55][55][11] = {0}, vis[55][55][11] = {0};
    int n, m, MOD = 1e9 + 7;
    int dfs(vector<string>& pizza, int x, int y, int rk) {
        if (vis[x][y][rk])
            return dp[x][y][rk];
        vis[x][y][rk] = 1;
        if (rk == 1) {
            int ha = 0;
            for (int i = x; i < n; i++) {
                for (int j = y; j < m; j++) {
                    if (pizza[i][j] == 'A') {
                        ha = 1;
                        break;
                    }
                }
                if (ha)
                    break;
            }
            dp[x][y][rk] = ha;
            return ha;
        }
        int uha = 0;
        int ans = 0;
        for (int i = x; i < n - 1; i++) {
            for (int j = y; j < m && !uha; j++) {
                if (pizza[i][j] == 'A')
                    uha = 1;
            }
            if (uha)
                ans = (ans + dfs(pizza, i + 1, y, rk - 1)) % MOD;
        }
        int lha = 0;
        for (int j = y; j < m - 1; j++) {
            for (int i = x; i < n && !lha; i++) {
                if (pizza[i][j] == 'A') {
                    lha = 1;
                }
            }
            if (lha)
                ans = (ans + dfs(pizza, x, j + 1, rk - 1)) % MOD;
        }
        return dp[x][y][rk] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        n = pizza.size(), m = pizza[0].size();
        return dfs(pizza, 0, 0, k);
    }
};