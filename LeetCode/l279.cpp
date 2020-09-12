class Solution {
public:

    int numSquares(int n) {
        vector<int> dp(n+1,0x3f3f3f3f);
        int tot=sqrt(n);
        vector<int> ls(tot+1);
        for(int i=1; i<=tot; i++)ls[i]=i*i;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=tot;j++){
                if(i>=ls[j]){
                    dp[i]=min(dp[i],dp[i-ls[j]]+1);
                }
                else break;
            }
        }
        return dp[n];
    }
};