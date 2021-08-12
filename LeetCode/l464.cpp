class Solution {
   public:
    vector<bool> dp, vis;
    int n, m;

    bool dfs(int x) {
        if (vis[x])
            return dp[x];
        int ps = 0;
        for (int i = 0; i < n; i++) {
            if (((1 << i) & x)) {
                ps += (i + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (((1 << i) & x) == 0) {
                if (ps + (i + 1) >= m) {
                    vis[x] = 1;
                    return dp[x] = true;
                }
                if (!dfs(x | (1 << i))) {
                    vis[x] = 1;
                    return dp[x] = true;
                }
            }
        }
        vis[x] = true;
        return dp[x] = 0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal == 0)
            return true;

        if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;

        int l = 1 << maxChoosableInteger;

        n = maxChoosableInteger, m = desiredTotal;
        dp.resize(l);
        vis.resize(l);
        return dfs(0);
    }
};