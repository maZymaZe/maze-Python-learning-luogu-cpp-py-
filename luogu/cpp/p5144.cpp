#include <cstdio>
int max(int a,int b){
    return a>b?a:b;
}
int a[1005],dp[1005][105],n,m,x[1005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        x[i]=x[0]^a[i];
        x[0]^=a[i];
        dp[i][1]=x[i];
    }
    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j++){
            for(int k=i-1;k<j;k++){
                dp[j][i]=max(dp[j][i],dp[k][i-1]+(x[j]^x[k]));
            }
        }
    }
    printf("%d",dp[n][m]);
    return 0;
}