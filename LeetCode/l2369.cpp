class Solution {
   public:
    bool validPartition(vector<int>& nums) {
        int l = nums.size();
        vector<int> dp(l + 1);
        dp[0] = 1;
        for (int i = 1; i < l; i++) {
            int ok = 0;
            if (i > 1 && dp[i - 2]) {
                if (nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                    ok |= 1;
                if (nums[i] == nums[i - 1] + 1 &&
                    nums[i - 1] == nums[i - 2] + 1)
                    ok |= 1;
            }
            if (dp[i - 1] && nums[i - 1] == nums[i])
                ok |= 1;
            dp[i + 1] = ok;
        }
        return dp[l];
    }
};