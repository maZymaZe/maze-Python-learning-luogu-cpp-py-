#include<cstdio>
int n,m,dp[203][203];
const int MOD=9901;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)dp[1][i]=1;
    for(int d=1;d<=m;d++){
        for(int i=3;i<=n;i+=2){
            for(int j=1;j<i;j+=2){
                (dp[i][d]+=dp[j][d-1]*dp[i-j-1][d-1])%=MOD;
            }
        }
    }
    printf("%d",(dp[n][m]-dp[n][m-1]+MOD)% MOD);
    return 0;
}