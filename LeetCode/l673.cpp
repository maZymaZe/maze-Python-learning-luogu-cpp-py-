class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n), c(n);
        dp[0] = 1, c[0] = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1, c[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 == dp[i]) {
                        c[i] += c[j];
                    } else if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        c[i] = c[j];
                    }
                }
            }
        }
        int mx = -1;
        for (int i = 0; i < n; i++)
            mx = max(mx, dp[i]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (dp[i] == mx)
                ans += c[i];
        return ans;
    }
};