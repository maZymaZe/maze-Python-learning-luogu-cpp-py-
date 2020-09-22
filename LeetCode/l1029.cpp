class Solution {
public:
    int dp[102][60]= {0};
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int l=costs.size();
        memset(dp, 0x3f3f3f3f, sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=l;i++){
            for(int j=0;j<=l/2&&j<=i;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+costs[i-1][1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1]+costs[i-1][0],dp[i-1][j]+costs[i-1][1]);
                }
            }
        }
        return dp[l][l/2];
    }
};