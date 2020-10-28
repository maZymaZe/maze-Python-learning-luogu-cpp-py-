class Solution {
public:
    long long dp[1025][2];
    const long long MOD=1e9+7;
    int numTilings(int N) {
        dp[0][0]=1;
        dp[0][1]=0;
        dp[1][0]=1;
        dp[1][1]=2;
        for(int i=2;i<=N;i++){
            dp[i][0]=(dp[i-1][0]+dp[i-2][0]+dp[i-1][1])%MOD;
            dp[i][1]=(dp[i-1][0]*2+dp[i-2][1])%MOD;
        }
        return  dp[N][0];
    }
};