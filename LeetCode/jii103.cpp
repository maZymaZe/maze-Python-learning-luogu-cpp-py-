class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0]=0;
        bool flag=false;
        for(int i=1;i<=amount;i++){
            flag=false;dp[i]=0x3f3f3f3f;
            for(int j:coins){
                if(i>=j&&dp[i-j]>=0){
                    dp[i]=min(dp[i],dp[i-j]+1);
                    flag=true;
                }
            }
            if(!flag)dp[i]=-1;
        }
        return dp[amount];

    }
};