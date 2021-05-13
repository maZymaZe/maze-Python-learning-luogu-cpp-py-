class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mal=steps/2;
        mal=min(mal,arrLen-1);
        vector<vector<int>> dp(2,vector<int>(mal+5));
        dp[0][0]=1;
        const int MOD = 1e9 + 7;
        for(int i=1;i<=steps;i++){
            for(int j=0;j<=mal;j++){
                dp[i&1][j]=dp[(i&1)^1][j];
                if(j-1>=0){
                    (dp[i&1][j]+=dp[(i&1)^1][j-1])%=MOD;
                }
                if(j+1<=mal){
                    (dp[i&1][j]+=dp[(i&1)^1][j+1])%=MOD;
                }
            }
        }
        return dp[steps&1][0];
    }
};