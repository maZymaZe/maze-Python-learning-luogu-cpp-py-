class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int dp[3002][2] = {0};
        target += 1500;
        if (nums[0])
            dp[1500 + nums[0]][0] = dp[1500 - nums[0]][0] = 1;
        else
            dp[1500 + nums[0]][0] = 2;
        int l = nums.size();
        for (int i = 1; i < l; i++) {
            for (int j = 0; j <= 3000; j++) {
                dp[j][i & 1] = 0;
                if (j + nums[i] <= 3000)
                    dp[j][i & 1] += dp[j + nums[i]][(i & 1) ^ 1];
                if (j - nums[i] >= 0)
                    dp[j][i & 1] += dp[j - nums[i]][(i & 1) ^ 1];
            }
        }
        return dp[target][(l - 1) & 1];
    }
};