class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int sum[105]={0},l=piles.size();
        for(int i=1;i<=l;i++){
            sum[i]=sum[i-1]+piles[i-1];
        }
        int dp[110][160]={0};
        for(int i=l;i>=1;i--){
            for(int j=1;j<=150;j++){
                if(2*j>=l-i+1){
                    dp[i][j]=sum[l]-sum[i-1];
                }
                else{
                    for(int k=1;k<=2*j;k++){
                        if(2*max(k,j)<150&&dp[i+k][max(k,j)]!=0)
                        dp[i][j]=max(dp[i][j],-sum[i-1]+sum[l]-dp[i+k][max(k,j)]);
                    }
                }
            }
        }
        return dp[1][1];
    }
};