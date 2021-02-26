#include<cstdio>
const int NMAX=1002,MOD=998244353;
int dp[2][NMAX<<1][4],n,k;
int min(int a, int b){ return a < b ? a : b;}
int main(){
    scanf("%d%d",&n,&k);
    dp[1][1][0]=1,dp[1][1][1]=1,dp[1][2][2]=1,dp[1][2][3]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=min(2*i,k);j++){
            dp[(i&1)][j][0]=(dp[!(i&1)][j][0]+dp[!(i&1)][j-1][1])%MOD;
            dp[(i&1)][j][0]+=(dp[!(i&1)][j][2]+dp[!(i&1)][j][3])%MOD;
            dp[(i&1)][j][0]%=MOD;

            dp[(i&1)][j][1]=(dp[!(i&1)][j-1][0]+dp[!(i&1)][j][1])%MOD;
            dp[(i&1)][j][1]+=(dp[!(i&1)][j][2]+dp[!(i&1)][j][3])%MOD;
            dp[(i&1)][j][1]%=MOD;

            dp[(i&1)][j][2]=(dp[!(i&1)][j-1][0]+dp[!(i&1)][j-1][1])%MOD;
            (dp[(i&1)][j][2]+=dp[!(i&1)][j][2])%=MOD;
            if(j>1)(dp[(i&1)][j][2]+=dp[!(i&1)][j-2][3])%=MOD;

            dp[(i&1)][j][3]=(dp[!(i&1)][j-1][0]+dp[!(i&1)][j-1][1])%MOD;
            (dp[(i&1)][j][3]+=dp[!(i&1)][j][3])%=MOD;
            if(j>1)(dp[(i&1)][j][3]+=dp[!(i&1)][j-2][2])%=MOD;
        }
    }
    int ans=0;
    for(int i=0;i<4; i++)ans=(ans+dp[(n&1)][k][i])% MOD;
    printf("%d\n",ans);
    return 0;
}