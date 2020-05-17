#include<cstdio>
int dp[1001][1001]={0},n,k;
int main(){
    scanf("%d%d",&n,&k);dp[1][0]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i][j]=(dp[i][j]+(dp[i-1][j])*(j+1))%2015;
            if(j>=1)dp[i][j]=(dp[i][j]+(i-j)*(dp[i-1][j-1]))%2015;
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}