#include <cstdio>
#include <cstring>
int max(int a,int b){ return a > b ? a : b;}
int n, m, h[3003], money[3003] = {0};
struct edge {
    int u, v, nx, w;
} e[3003];
int dp[3003][3003],t[3003];
int dfs(int x) {
    if (x > n - m) {
        dp[x][1] = money[x];
        return 1;
    }
    int sum=0;
    for(int i=h[x]; i; i = e[i].nx){
        int y=e[i].v;
        int tk=dfs(y);
        for(int j=0;j<=sum;j++)t[j]=dp[x][j];
        for(int j=0;j<=sum;j++){
            for(int k=0;k<=tk;k++){
                dp[x][j+k]=max(dp[x][j+k],dp[y][k]-e[i].w+t[j]);
            }
        }
        sum+=tk;
    }
    return sum;
}
int main() {
    int t1, t2, t3, tot = 0;
    scanf("%d%d", &n, &m);
    memset(dp,~0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)dp[i][0]=0;
    for (int i = 1; i <= n - m; i++) {
        scanf("%d", &t1);
        for (int j = 1; j <= t1; j++) {
            scanf("%d%d", &t2, &t3);
            e[++tot] = {i, t2, h[i], t3};
            h[i] = tot;
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        scanf("%d", &money[i]);
    dfs(1);
    for(int i=m;i>=0;i--){
        if(dp[1][i]>=0){
            printf("%d",i);
            break;
        }
    }
    return 0;
}