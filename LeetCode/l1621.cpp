class Solution {
   public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n),s(n);
        dp[0] =s[0]=1;
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(j<i)dp[j] = 0;
                else if(j==i||i==0)dp[j] = 1;
                else dp[j]=(s[j-1]+dp[j-1])%MOD;
            }
            s[0]=dp[0];
            for(int j=1;j<n;j++){
                s[j]=(s[j-1]+dp[j])%MOD;
            }
        }
        return dp[n-1];
    }
};