class Solution {
public:
    int numDecodings(string s) {
        const long long MOD=1e9+7;
        int l=s.size();
        vector<long long> dp(l+1);
        dp[0]=1;
        if(s[0]=='0')dp[1]=0;
        else if(s[0]=='*')dp[1]=9;
        else dp[1]=1;
        for(int i=2;i<=l;i++){
            if(s[i-1]=='*'){
                if(s[i-2]=='*')dp[i]=(dp[i]+dp[i-2]*15)%MOD;
                else if(s[i-2]=='1')dp[i]=(dp[i]+dp[i-2]*9)%MOD;
                else if(s[i-2]=='2')dp[i]=(dp[i]+dp[i-2]*6)%MOD;

                dp[i]=(dp[i]+dp[i-1]*9)%MOD;
            }
            else if(s[i-1]=='0'){
                if(s[i-2]=='1'||s[i-2]=='2')dp[i]=(dp[i]+dp[i-2])%MOD;
                else if(s[i-2]=='*')dp[i]=(dp[i]+dp[i-2]*2)%MOD;
            }
            else if(s[i-1]>'0'&&s[i-1]<'7'){
                if(s[i-2]=='1'||s[i-2]=='2')dp[i]=(dp[i]+dp[i-2])%MOD;
                else if(s[i-2]=='*')dp[i]=(dp[i]+dp[i-2]*2)%MOD;
    
                dp[i]=(dp[i]+dp[i-1])%MOD;
            }else{
                if(s[i-2]=='1'||s[i-2]=='*')dp[i]=(dp[i]+dp[i-2])%MOD;
                dp[i]=(dp[i]+dp[i-1])%MOD;
            } 
        }
        return dp[l];
    }
};