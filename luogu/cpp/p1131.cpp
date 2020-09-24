#include <cstdio>
const int NMAX=1e6+ 10;
int max(int a,int b){ return a > b ? a : b;}
struct edge{
    int v,nx,dis;
}e[NMAX];
int n,s,a,b,t,maxn[NMAX],cnt,h[NMAX];
long long ans;
inline void add(int u, int v, int w){
    e[++cnt]={v,h[u],w};h[u]=cnt;
}
void dfs(int x,int fa){
    for(int i=h[x];i; i = e[i].nx){
        if(e[i].v!= fa)dfs(e[i].v,x);
    }
    for(int i=h[x];i; i = e[i].nx){
        if(e[i].v!= fa)maxn[x]=max(maxn[x],e[i].dis);
    }
    for(int i=h[x];i; i = e[i].nx){
        if(e[i].v != fa)ans+=maxn[x]-e[i].dis;
    }
    for(int i=h[fa];i; i = e[i].nx){
        if(e[i].v==x)e[i].dis+=maxn[x];
    }
}
int main() {
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a, &b, &t);
        add(a,b,t);
        add(b,a,t);
    }
    dfs(s,0);
    printf("%lld\n",ans);
    return 0;
}