class Solution {
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1);
        dp[n] = 0;
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1],
                        dp[min(n, i + questions[i][1] + 1)] + questions[i][0]);
        }
        return dp[0];
    }
};