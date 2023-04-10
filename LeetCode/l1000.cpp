class Solution {
   public:
    int mergeStones(vector<int>& stones, int k) {
        const int INF = 0x3f3f3f3f;
        int l = stones.size();
        if (((l - 1) % (k - 1) != 0))
            return -1;
        vector<vector<int>> dp(l, vector<int>(l, INF));
        vector<int> ps(l + 1);
        for (int i = 0; i < l; i++) {
            ps[i + 1] = ps[i] + stones[i];
            dp[i][i] = 0;
        }
        for (int len = 2; len <= l; len++) {
            for (int i = 0; i + len - 1 < l; i++) {
                int r = i + len - 1;
                for (int j = i; j < r; j += (k - 1)) {
                    dp[i][r] = min(dp[i][r], dp[i][j] + dp[j + 1][r]);
                }
                if ((r - i) % (k - 1) == 0)
                    dp[i][r] += ps[r + 1] - ps[i];
            }
        }
        return dp[0][l - 1];
    }
};