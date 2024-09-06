class Solution {
   public:
    int l;
    vector<int> V;
    int dp[501][27][501];
    int fdp(int p, int k, int pv) {
        if (p == l)
            return 0;
        if (dp[p][k][pv] != -1)
            return dp[p][k][pv];
        int ans = 0;
        if (V[p] != pv) {
            if (k)
                ans = max(ans, fdp(p + 1, k - 1, V[p]) + 1);
            ans = max(ans, fdp(p + 1, k, pv));
        } else {
            ans = max(ans, fdp(p + 1, k, pv) + 1);
        }
        return dp[p][k][pv] = ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        l = nums.size();
        memset(dp, -1, sizeof(dp));
        auto v = nums;
        sort(v.begin(), v.end());
        auto te = unique(v.begin(), v.end());
        for (int i = 0; i < l; i++) {
            nums[i] = (lower_bound(v.begin(), te, nums[i]) - v.begin());
        }
        int mx = te - v.begin();
        V = nums;
        return fdp(0, k + 1, mx);
    }
};