class Solution {
public:
    long long dp[100005][3][2]={0};
    const long long MOD=1e9+7;
    int checkRecord(int n) {
        dp[0][1][0]=dp[0][1][1]=dp[0][0][1]=dp[0][2][0]=dp[0][2][1]=0;dp[0][0][0]=1;
        for(int i=1;i<=n;i++){
            dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][2][0])%MOD;
            dp[i][0][1]=(dp[i-1][0][0]+dp[i-1][1][0]+dp[i-1][0][1]+dp[i-1][1][1]+dp[i-1][2][0]+dp[i-1][2][1])%MOD;
            dp[i][1][0]=dp[i-1][0][0];
            dp[i][1][1]=dp[i-1][0][1];
            dp[i][2][0]=dp[i-1][1][0];
            dp[i][2][1]=dp[i-1][1][1];
        }
        return (dp[n][0][0]+dp[n][1][0]+dp[n][1][1]+dp[n][0][1]+dp[n][2][0]+dp[n][2][1])%MOD;
    }
};