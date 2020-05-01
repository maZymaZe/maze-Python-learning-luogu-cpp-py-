#include<cstdio>
#include<algorithm>
using namespace std;
int a[16002],n,h[16002],t1,t2,f[16002],dp[16002],v[16002],ans=-2147483647;
struct edge{
    int u,v,nx;
}e[32100];
int dfs(int x){
    if(v[x]==1)return dp[x];
    else{
        v[x]=1;
        dp[x]=a[x];
        for(int i=h[x];i; i = e[i].nx){
            if(e[i].v!=f[x]){
                f[e[i].v]=x;
                dp[x]+=max(0,dfs(e[i].v));
            }
        }
    }
    ans=max(ans, dp[x]);
    return dp[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&t1,&t2);
        e[i<<1].u= t1;e[i<<1].v=t2;
        e[i<<1].nx=h[t1];h[t1]=i<<1;
        e[(i << 1)-1].u=t2;e[(i << 1)-1].v=t1;
        e[(i << 1)-1].nx=h[t2];h[t2]=(i << 1)-1;
    }
    dfs(1);
    printf("%d",ans);
    return 0;
}