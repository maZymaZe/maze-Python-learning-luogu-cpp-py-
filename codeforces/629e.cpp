#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const ll NMAX=1e5+10,INF= 0x3f3f3f3f3f3f3f3f;
ll n,m,t,d[NMAX],F[NMAX],G[NMAX],dist[NMAX],sz[NMAX],f[NMAX][20];
ll h[NMAX],ep;
struct EDGE{
    ll u,v,nx;
}e[NMAX<<1];
void add(ll a, ll b){
    e[++ep]={a,b,h[a]};
    h[a]=ep;
    e[++ep]={b,a,h[b]};
    h[b]=ep;
}
queue<int> q;
void bfs(){
    d[1]=1;
    q.push(1);
    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=h[x];i; i = e[i].nx){
            int y=e[i].v;
            if(d[y])continue;
            d[y]=d[x]+1;
            dist[y]=dist[x] +1;
            f[y][0]=x;
            for(int j=1;j<=t;j++){
                f[y][j]=f[f[y][j-1]][j-1];
            }
            q.push(y);
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    for(int i=t;i>=0;i--){
        if(d[f[y][i]]>=d[x])y=f[y][i];
    }
    if(x==y)return x;
    for(int i=t;i>=0;i--){
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
void dfs1(ll x,ll fa){
    sz[x]=1;
    for(int i=h[x];i;i=e[i].nx){
        int y = e[i].v;
        if(y==fa)continue;
        dfs1(y,x);
        sz[x]+=sz[y];
        F[x]+=F[y]+sz[y];
    }
}
void dfs2(ll x,ll fa){
    if(x==1)G[x]=F[x];
    for(int i=h[x];i;i = e[i].nx){
        int y = e[i].v;
        if(y==fa)continue;
        G[y]=G[x]-sz[y]+(n-sz[y]);
        dfs2(y,x);
    }
}
long double GetE(int x, int y){
    int L=lca(x,y);
    long double SZ,SUM;
    if(d[x]>d[y])swap(x,y);
    if(L!=x){
        SZ=sz[x]*sz[y];
        SUM=SZ*(dist[x]+dist[y]-2*dist[L]+1)+F[x]*sz[y]+F[y]*sz[x];
    }else{
        ll sx=y;
        for(int i=t;i>=0;i--){
            if(d[f[sx][i]]>d[x])sx=f[sx][i];
        }
        SZ=(n-sz[sx])*sz[y];
        SUM=SZ*(dist[x]+dist[y]-2*dist[L]+1)+(G[x]-F[sx]-sz[sx])*sz[y]+F[y]*(n-sz[sx]);
    }
    return SUM/SZ;
}
int main(){
    scanf("%lld%lld",&n,&m);
    t=(ll)(log(n)/log(2))+1;
    ll t1,t2;
    for(int i=1;i<n;i++){
        scanf("%lld%lld",&t1,&t2);
        add(t1,t2);
    }
    bfs();
    dfs1(1,0);
    dfs2(1,0);
    while(m--){
        scanf("%lld%lld",&t1,&t2);
        printf("%.8lf\n",(double)GetE(t1,t2));
    }
    return 0;
}
