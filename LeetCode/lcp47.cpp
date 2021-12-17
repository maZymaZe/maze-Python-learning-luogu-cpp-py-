class Solution {
   public:
    int securityCheck(vector<int>& capacities, int k) {
        int dp[50000] = {0}, MOD = 1e9 + 7;
        dp[0] = 1;
        int l = capacities.size();
        for (int i = 0; i < l; i++) {
            for (int j = 40000; j >= capacities[i] - 1; j--) {
                (dp[j] += dp[j - capacities[i] + 1]) %= MOD;
            }
        }
        return dp[k];
    }
};