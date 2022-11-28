class Solution {
   public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        double dp[120][120] = {0};
        int l = nums.size();
        vector<int> ps(l + 1);
        for (int i = 0; i < l; i++) {
            ps[i + 1] = ps[i] + nums[i];
            dp[i + 1][1] = 1.0 * ps[i + 1] / (i + 1);
        }
        for (int i = 1; i <= l; i++) {
            for (int s = 2; s <= k; s++) {
                for (int j = 1; j < i; j++) {
                    dp[i][s] =
                        max(dp[i][s],
                            dp[j][s - 1] + 1.0 * (ps[i] - ps[j]) / (i - j));
                }
            }
        }
        return dp[l][k];
    }
};