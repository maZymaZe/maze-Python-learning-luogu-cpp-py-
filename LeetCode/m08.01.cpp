class Solution {
public:
    int waysToStep(int n) {
        vector<long long> dp(n+6);
        const long long MOD=1e9+7;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++){
            dp[i] =(dp[i-1]+dp[i-2]+dp[i-3])%MOD;
        } 
        return dp[n];
    }
};