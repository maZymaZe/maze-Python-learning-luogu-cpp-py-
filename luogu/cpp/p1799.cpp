#include <cstdio>
int max(int a,int b){ return a> b ? a : b;}
int dp[1200]={0}, n, a[1200]={0},ans=0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i-1; j >=0 ; j--) {
            if(j==0) {dp[j]=dp[j]+(a[i]==i);}
            else dp[j]=max(dp[j]+(i-j==a[i]),dp[j-1]);
        }
    }
    for(int i = 0; i < n; i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}