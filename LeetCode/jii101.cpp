class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int l = nums.size(), tot = 0;
        for (int i = 0; i < l; i++)
            tot += nums[i];
        if (tot & 1)
            return false;
        tot >>= 1;
        vector<int> dp(tot + 1);
        dp[0] = 1;
        for (int i = 0; i < l; i++) {
            if (tot >= nums[i] && dp[tot - nums[i]])
                return true;
            for (int j = tot - 1; j >= nums[i]; j--) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return false;
    }
};