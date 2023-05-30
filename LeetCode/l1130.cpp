class Solution {
   public:
    vector<vector<int>> mx, v, dp;
    int len;
    int dfs(int l, int r) {
        if (l == r)
            return 0;
        if (v[l][r])
            return dp[l][r];
        long long tx = 0x3f3f3f3f3f3f3f3fll;
        for (int i = l; i < r; i++) {
            tx = min(tx, (long long)mx[l][i] * mx[i + 1][r] + dfs(l, i) +
                             dfs(i + 1, r));
        }
        v[l][r] = 1;
        dp[l][r] = tx;
        return dp[l][r];
    }
    int mctFromLeafValues(vector<int>& arr) {
        len = arr.size();
        mx.resize(len);
        v.resize(len);
        dp.resize(len);
        for (int i = 0; i < len; i++) {
            mx[i].resize(len);
            v[i].resize(len);
            dp[i].resize(len);
            mx[i][i] = arr[i];
            for (int j = i + 1; j < len; j++) {
                mx[i][j] = max(mx[i][j - 1], arr[j]);
            }
        }
        return dfs(0, len - 1);
    }
};