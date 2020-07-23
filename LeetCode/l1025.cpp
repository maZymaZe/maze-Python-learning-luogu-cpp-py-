class Solution {
public:
    bool divisorGame(int N) {
        bool dp[1010]={0};
        dp[1]=0,dp[0]=1,dp[2]=1,dp[3]=0;
        for(int i=4;i<=N;i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    dp[i]=dp[i]||(bool)(!dp[i-j]);
                }
            }
        }
        return dp[N];
    }
};