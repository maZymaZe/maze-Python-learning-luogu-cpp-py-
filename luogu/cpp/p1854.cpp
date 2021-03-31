#include<cstdio>
int max(int a,int b){ return a > b ? a : b;}
const int NMAX=103;
int n,m,dp[NMAX][NMAX],a[NMAX],mp[NMAX][NMAX];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            dp[i][j]=-0x3f3f3f3f;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j-1]+mp[i][j],dp[i][j]);
            if(i<=j-1)dp[i][j]=max(dp[i][j],dp[i][j-1]);
            
        }
    }
    int ans=dp[n][m],ret[NMAX]={0},p=m;
    for(int i=n;i>0;i--){
        for(;p;p--){
            if(mp[i][p]==dp[i][p]-dp[i-1][p-1]){
                ret[i]=p;
                p--;
                break;
            }
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        printf("%d ",ret[i]);
    }
    return 0;
}