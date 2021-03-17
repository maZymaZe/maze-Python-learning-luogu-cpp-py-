class Solution {
public:
    int numDistinct(string s, string t) {
        int ls=s.length(),lt=t.length();
        vector<vector<long long>> dp(2,vector<long long>(lt+1));
        dp[0][0]=1;
        for(int i=1;i<=ls;i++){
            for(int j=0;j<=lt;j++){
                dp[i&1][j]=0;
                if(j>0&&s[i-1]==t[j-1]){
                    dp[i&1][j]=dp[(i-1)&1][j-1];
                }
                dp[i&1][j]+=dp[(i-1)&1][j];
            }
        }
        return dp[ls&1][lt];
    }
};