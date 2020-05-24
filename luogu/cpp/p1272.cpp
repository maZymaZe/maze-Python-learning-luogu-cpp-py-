#include<cstdio>
#include<cstring>
struct edge{
    int u,v,nx;
}e[333];
inline int min(int a,int b){return a < b ? a : b;}
int h[333],n,p,dp[160][160],ans,c[160];
void dfs(int w,int fa){
    dp[w][1]=c[w];
    for(int i=h[w];i;i=e[i].nx){
        if(e[i].v!=fa){
            dfs(e[i].v,w);
            for(int j=p;j>=1;j--){
                for(int k=1;k<j;k++){
                    dp[w][j]=min(dp[w][j],dp[w][k]+dp[e[i].v][j-k]-2);
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&p);
    for(int i=1;i<n;i++){
        scanf("%d%d",&e[i<<1].u,&e[i<<1].v);
        e[i<<1].nx= h[e[i<<1].u];
        h[e[i<<1].u]=i<<1;
        e[(i << 1)-1].u=e[i<<1].v;
        e[(i << 1)-1].v=e[i<<1].u;
        e[(i << 1)-1].nx=h[e[i<<1].v];
        h[e[i<<1].v]=(i<<1)-1;
        c[e[i<<1].v]++;c[e[i<<1].u]++;
    }
    memset(dp,0x3f,sizeof(dp));
    dfs(1,0);
    ans=dp[1][p];
    for(int i=2;i<=n;i++){
        if(ans>dp[i][p])ans=dp[i][p];
    }
    printf("%d",ans);
    return 0;
}