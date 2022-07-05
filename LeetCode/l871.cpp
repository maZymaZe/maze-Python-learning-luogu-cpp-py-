class Solution {
   public:
    int minRefuelStops(int target,
                       int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        dp[0][0] = startFuel + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                long long lf = dp[i][j] - (stations[i][0] -
                                           (i > 0 ? stations[i - 1][0] : 0));
                if (lf > 0) {
                    dp[i + 1][j + 1] = lf + stations[i][1];
                    dp[i + 1][j] = max(dp[i + 1][j], lf);
                }
            }
        }
        long long ld;
        if (n == 0)
            ld = target;
        else
            ld = target - stations[n - 1][0];
        for (int j = 0; j <= n; j++) {
            if (dp[n][j] - ld > 0) {
                return j;
            }
        }
        return -1;
    }
};