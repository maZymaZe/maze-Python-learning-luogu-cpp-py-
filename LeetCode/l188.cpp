class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int l = prices.size();
        if(k>l/2+2){
            int ans=0,x;
            for(int i=1;i<l;i++)x=prices[i]-prices[i-1],ans+=(x>0)?x:0;
            return ans;
        }
        const int MINF=-0x3f3f3f3f;
        vector<vector<int> > dp0(l + 1, vector<int>(k + 2,MINF)),
            dp1(l + 1, vector<int>(k + 2,MINF));
        dp0[0][1]=0;
        for(int i=1;i<=l;i++){
            for(int j=1;j<=k+1;j++){
                dp0[i][j]=max(dp0[i-1][j],dp1[i-1][j-1]+prices[i-1]);
                dp1[i][j]=max(dp1[i-1][j],dp0[i-1][j]-prices[i-1]);
            }
        }
        int ans=0;
        for(int i=1;i<=k+1;i++)ans=max(ans,dp0[l][i]);
        return ans;
    }
};