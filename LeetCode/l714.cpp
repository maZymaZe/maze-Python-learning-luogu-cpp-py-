class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int l=prices.size();
        if(l<2)return 0;
        int dp1[50001]={0},dp2[50001]={0};
        dp1[0]=0;dp2[0]=-prices[0];
        for(int i=1;i<l;i++){
            dp1[i]=max(dp1[i-1],dp2[i-1]+prices[i]-fee);
            dp2[i]=max(dp2[i-1],dp1[i-1]-prices[i]);
        }
        return dp1[l-1];
    }
};