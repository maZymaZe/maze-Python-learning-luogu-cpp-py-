class Solution {
   public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        for (int i = 0; i < n; i++)
            time[i]++;
        vector<int> dp(n + 10, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n; j > 0; j--) {
                dp[j] = min(dp[j], ((j - time[i] >= 0) ? dp[j - time[i]] : 0) +
                                       cost[i]);
            }
        }
        return dp[n];
    }
};