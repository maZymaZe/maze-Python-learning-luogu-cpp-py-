#include<cstdio>
int dp[105][10005],p[105],n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=p[i]&&i>1)dp[i][j]+=dp[i-1][j-p[i]];
            if(j==p[i]&&i==1)dp[i][j]+=1;
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}