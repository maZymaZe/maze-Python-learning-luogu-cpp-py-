#include<cstdio>
int n,m;
long long dp[10][100][1030]={0};
int cx[1030]={0},cnt=0,sit[1030],gs[1030];
void dfs(int he,int sum,int node){
    if(node>=n){
        sit[++cnt]=he;
        gs[cnt]=sum;
        return;
    }
    dfs(he,sum,node+1);
    dfs(he+(1<<node),sum+1,node+2);
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(0,0,0);
    for(int i=1;i<=cnt;i++)dp[1][gs[i]][i]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            for(int k=1;k<=cnt;k++){
                if(sit[j]&sit[k])continue;
                if(sit[j]&(sit[k]<<1))continue;
                if((sit[j]<<1)&sit[k])continue;
                for(int l=m;l>=gs[j];l--){
                    dp[i][l][j]+=dp[i-1][l-gs[j]][k];
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=cnt; i++)ans+=dp[n][m][i];
    printf("%lld\n",ans);
    return 0;
}