class Solution {
   public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int l = arr.size();
        vector<int> dp(l + 1);
        for (int i = 1; i <= l; i++) {
            int p = arr[i - 1];
            for (int j = 1; j <= k && i - j >= 0; j++) {
                p = max(p, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + j * p);
            }
        }
        return dp[l];
    }
};