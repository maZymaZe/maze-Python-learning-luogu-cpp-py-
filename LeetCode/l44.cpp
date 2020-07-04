class Solution {
public:
    bool isMatch(string s, string p) {
        int ls=s.size(),lp=p.size();
        vector<vector<bool> > dp(ls+1,vector<bool>(lp+1));
        dp[0][0]=true;
        for (int i = 1; i <= lp; ++i) {
            if (p[i - 1] == '*')dp[0][i] = true;
            else break;
        }
        for(int i=1;i<=ls;i++){
            for(int j=1;j<=lp;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')dp[i][j]=dp[i-1][j]|dp[i][j-1];
            }
        }
        return dp[ls][lp];
    }
};

