class Solution {
   public:
    vector<vector<long long>> dp, p, vis;
    long long dfs(int x, int y) {
        if (vis[x][y])
            return dp[x][y];
        vis[x][y] = 1;
        long long ans = 0;
        for (int i = 1; i < x; i++) {
            ans = max(ans, dfs(i, y) + dfs(x - i, y));
        }
        for (int i = 1; i < y; i++) {
            ans = max(ans, dfs(x, i) + dfs(x, y - i));
        }
        ans = max(ans, p[x][y]);
        return dp[x][y] = ans;
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vis = p = dp =
            vector<vector<long long>>(m + 1, vector<long long>(n + 1));
        for (auto& v : prices) {
            p[v[0]][v[1]] = v[2];
        }
        return dfs(m, n);
    }
};