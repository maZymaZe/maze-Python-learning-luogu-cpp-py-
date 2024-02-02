class Solution {
   public:
    int len;
    vector<vector<int>> dp, v;
    vector<int> ps;
    long long f(int l, int r) {
        if (l == r)
            return 0;
        if (v[l][r])
            return dp[l][r];
        v[l][r] = 1;
        dp[l][r] = max(ps[r + 1] - ps[l + 1] - f(l + 1, r),
                       ps[r] - ps[l] - f(l, r - 1));
        return dp[l][r];
    }
    int stoneGameVII(vector<int>& stones) {
        len = stones.size();
        v = dp = vector<vector<int>>(len, vector<int>(len));
        ps = vector<int>(len + 1);
        for (int i = 0; i < len; i++)
            ps[i + 1] = ps[i] + stones[i];
        return f(0, len - 1);
    }
};