class Solution {
   public:
    vector<vector<int>> e;
    vector<int> fa, np;
    vector<long long> dp0, dp1;
    long long ans;
    void dfs(int cur, int fa) {
        long long tot0 = 0, tot1 = 0;
        for (int i : e[cur]) {
            if (i != fa) {
                dfs(i, cur);
                if (np[cur]) {
                    ans += dp0[i] * tot1 + dp1[i] * (tot0 + 1);
                } else {
                    ans += dp0[i] * (tot0 + 1);
                }
                tot0 += dp0[i];
                tot1 += dp1[i];
            }
        }
        if (np[cur]) {
            dp0[cur] = 1 + tot0;
            dp1[cur] = tot1;
        } else {
            dp0[cur] = 0;
            dp1[cur] = 1 + tot0;
        }
    }
    long long countPaths(int n, vector<vector<int>>& edges) {
        np.resize(n + 1);
        np[1] = 1;
        dp0.resize(n + 1);
        dp1.resize(n + 1);
        ans = 0;
        for (int i = 2; i <= n; i++) {
            if (!np[i]) {
                for (int j = 2 * i; j <= n; j += i)
                    np[j] = 1;
            }
        }
        e.resize(n + 1);
        for (const auto& eg : edges) {
            e[eg[0]].push_back(eg[1]);
            e[eg[1]].push_back(eg[0]);
        }
        dfs(1, 0);
        return ans;
    }
};