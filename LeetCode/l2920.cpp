class Solution {
   public:
    vector<vector<int>> e;
    int vis[100004][15] = {0}, dp[100004][15] = {0}, K;
    vector<int> c;
    int dfs(int x, int fa, int t) {
        if (t > 14)
            return 0;
        if (vis[x][t])
            return dp[x][t];
        int tot1 = 0, tot2 = 0;
        int cur = c[x] >> t;
        tot1 += (cur - K);
        tot2 += cur / 2;
        for (int i : e[x]) {
            if (i != fa) {
                tot1 += dfs(i, x, t);
                tot2 += dfs(i, x, t + 1);
            }
        }
        vis[x][t] = 1;
        dp[x][t] = max(tot1, tot2);
        return dp[x][t];
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        e.resize(n);
        K = k;
        c = coins;
        for (const auto& v : edges) {
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
        }
        return dfs(0, -1, 0);
    }
};