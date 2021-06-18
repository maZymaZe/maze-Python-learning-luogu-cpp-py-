class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1=s1.length(),l2=s2.length();
        vector<vector<int>> dp(l1+2, vector<int>(l2+2));
        for(int i=0;i<l1;i++)dp[i+1][0]=dp[i][0]+s1[i];
        for(int i=0;i<l2;i++)dp[0][i+1]=dp[0][i]+s2[i];
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                dp[i][j]=0x3f3f3f3f;
                if(s1[i-1]==s2[j - 1]){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                dp[i][j]=min(dp[i][j],dp[i-1][j]+s1[i-1]);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[l1][l2];
    }
};