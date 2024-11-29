class Solution {
   public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size(), MOD = 1e9 + 7;
        int dp[2][1002] = {0};
        int ps[1003] = {0};
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            int o = ((i & 1) ^ 1), c = (i & 1);
            memset(ps, 0, sizeof(ps));
            for (int j = 1; j <= 1001; j++) {
                ps[j] += ps[j - 1];
                ps[j] %= MOD;
                ps[j] += dp[o][j - 1];
                ps[j] %= MOD;
            }
            memset(dp[c], 0, sizeof(dp[c]));
            int d = max(0, nums[i] - nums[i - 1]);
            for (int j = d; j <= nums[i]; j++) {
                if (j == 0)
                    dp[c][j] = dp[o][j - d];
                else {
                    dp[c][j] = (dp[c][j - 1] + dp[o][j - d]) % MOD;
                }
            }
        }
        int pa = ((n - 1) & 1);
        int ans = 0;
        for (int i = 0; i <= nums[n - 1]; i++) {
            ans += dp[pa][i];
            ans %= MOD;
        }
        return ans;
    }
};