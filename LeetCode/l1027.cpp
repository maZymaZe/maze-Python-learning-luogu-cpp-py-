class Solution {
   public:
    int longestArithSeqLength(vector<int>& nums) {
        int dp[1050][1050] = {0}, l = nums.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][(nums[i] - nums[j]) + 500] =
                    max(dp[i][(nums[i] - nums[j]) + 500],
                        dp[j][(nums[i] - nums[j]) + 500] + 1);
                ans = max(ans, dp[i][(nums[i] - nums[j]) + 500]);
            }
        }
        return ans + 1;
    }
};