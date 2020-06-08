class Solution {
public:
    int translateNum(int num) {
        string s=to_string(num);
        int dp[13]={0},l=s.size();
        dp[0]=1;
        for(int i=1;i<l;i++){
            dp[i]=dp[i-1];
            if(s[i-1]=='1'){
                dp[i]+=(i==1)?1:dp[i-2];
            }
            if(s[i-1]=='2'&&s[i]<'6'){
                dp[i]+=(i==1)?1:dp[i-2];
            }
        }
        return dp[l-1];
    }
};