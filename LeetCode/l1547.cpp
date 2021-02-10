class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m= cuts.size();
        sort(cuts.begin(),cuts.end());
        int dp[102][102];
        memset(dp, 0x3f,sizeof(dp));
        if(m>1)dp[0][1]=cuts[1];
        else dp[0][1]=n;
        for(int i=2;i<m;i++){
            dp[i-1][i]=cuts[i]-cuts[i-2];
        }
        for(int i=0;i<=m;i++)dp[i][i]=0;
        if(m>1)dp[m-1][m]=n-cuts[m-2];
        for(int i=2;i<=m;i++){
            for(int j=0;j+i<=m;j++){
                int mi= 0x3f3f3f3f;
                for(int k=j;k<j+i;k++){
                    mi=min(dp[j][k]+dp[k+1][j+i], mi);
                }
                if(j==0&&j+i!=m)mi+=cuts[i];
                else if(j==0&&j+i==m)mi+=n;
                else if(j+i==m)mi+=(n-cuts[j-1]);
                else mi+=(cuts[j+i]-cuts[j-1]);
                dp[j][j+i]=mi;
            }
        }
        return dp[0][m];
    }
};