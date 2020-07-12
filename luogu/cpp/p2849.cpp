#include <cstdio>
#include<cstring>
int n, m, dp[550][550], x[550], y[550];
inline int abs(int x) {
    return x > 0 ? x : -x;
}
inline int min(int a,int b){return a< b ? a : b;}
inline int d(int a, int b) {
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}
int main(){
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    int tot = 0;
    memset(dp,0x3f, sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][i]=0;
    }
    dp[1][0]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=min(i-1,m);j++){
          for(int k=0;k<=j;k++){
              dp[i][j]=min(dp[i][j],dp[i-k-1][j-k]+d(i,i-k-1));
          }
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}