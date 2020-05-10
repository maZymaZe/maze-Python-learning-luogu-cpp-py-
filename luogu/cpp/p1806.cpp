#include<cstdio>
long long dp[501][501],n,ans;
int main(){
    scanf("%lld",&n);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=0;k<j;k++){
                dp[i][j]+=dp[i-j][k];
            }
        }
    }
    for(int i=0;i<=n;i++)
    ans+=dp[n][i];
    printf("%lld",ans-1);
    return 0;
}