#include<cstdio>
int min(int a, int b){ return a < b ? a : b;}
int n,t,dp1[30004][4],dp2[30004][4],ans=0x3f3f3f3f;
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &t);
        dp1[i][1]=dp1[i-1][1]+1;
        dp1[i][2]=min(dp1[i-1][1],dp1[i-1][2])+1;
        dp1[i][3]=min(dp1[i-1][1],min(dp1[i-1][2],dp1[i-1][3]))+1;
        dp1[i][t]--;
        dp2[i][3]=dp2[i-1][3]+1;
        dp2[i][2]=min(dp2[i-1][3],dp2[i-1][2])+1;
        dp2[i][1]=min(dp2[i-1][1],min(dp2[i-1][2],dp2[i-1][3]))+1;
        dp2[i][t]--;
    }
    for(int i=1;i<=3;i++){
        ans=min(ans,dp1[n][i]);
        ans=min(ans,dp2[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}