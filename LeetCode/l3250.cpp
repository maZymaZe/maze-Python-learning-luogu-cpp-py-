class Solution {
   public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size(), MOD = 1e9 + 7;
        int dp[2][52][52] = {0};
        int ps[53][53] = {0};
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i][nums[0] - i] = 1;
        }
        for (int i = 1; i < n; i++) {
            int o = ((i & 1) ^ 1), c = (i & 1);
            memset(ps, 0, sizeof(ps));
            for (int j = 1; j <= 51; j++) {
                for (int k = 1; k <= 51; k++) {
                    ps[j][k] += ps[j - 1][k];
                    ps[j][k] %= MOD;
                    ps[j][k] += MOD - ps[j - 1][k - 1];
                    ps[j][k] %= MOD;
                    ps[j][k] += ps[j][k - 1];
                    ps[j][k] %= MOD;
                    ps[j][k] += dp[o][j - 1][k - 1];
                    ps[j][k] %= MOD;
                }
            }
            memset(dp[c], 0, sizeof(dp[c]));
            for (int j = 0; j <= nums[i]; j++) {
                int k = nums[i] - j;
                dp[c][j][k] += ps[51][k + 1];
                dp[c][j][k] %= MOD;
                dp[c][j][k] += MOD - ps[j][k + 1];
                dp[c][j][k] %= MOD;
            }
        }
        int pa = ((n - 1) & 1);
        int ans = 0;
        for (int i = 0; i <= nums[n - 1]; i++) {
            ans += dp[pa][i][nums[n - 1] - i];
            ans %= MOD;
        }
        return ans;
    }
};