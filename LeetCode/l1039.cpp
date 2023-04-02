class Solution {
   public:
    vector<vector<int>> dp;
    int n;
    vector<int> v;
    int dfs(int l, int r) {
        if (l + 2 > r)
            return 0;
        if (dp[l][r])
            return dp[l][r];
        if (l + 2 == r) {
            return dp[l][r] = v[l] * v[l + 1] * v[r];
        }
        dp[l][r] = 0x3f3f3f3f;
        for (int i = l + 1; i < r; i++) {
            dp[l][r] =
                min(dp[l][r], v[l] * v[r] * v[i] + dfs(l, i) + dfs(i, r));
        }
        return dp[l][r];
    }
    int minScoreTriangulation(vector<int>& values) {
        v = values;
        n = values.size();
        dp = vector<vector<int>>(n, vector<int>(n));
        return dfs(0, n - 1);
    }
};