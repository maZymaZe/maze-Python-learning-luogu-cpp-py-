#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=2e5+10;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
struct EDGE{
    int u,v,nx;
}e[NMAX<<1];
int a[NMAX],h[NMAX],ep,n,t1, t2,t3,ans[NMAX],fa[NMAX],dis[NMAX];
void add(int u,int v){
    e[++ep]={u,v,h[u]};
    h[u]=ep;
}
void dfs(int x){
    for(int i=h[x];i;i=e[i].nx){
        int y=e[i].v;
        if(y==fa[x])continue;
        ans[y]=dis[y]=gcd(dis[x],a[y]);
        fa[y]=x;
        dfs(y);
    }
}
void work(int u,int d){
    for(int i=h[u];i;i= e[i].nx){
        int v=e[i].v;
        if(fa[u]==v)continue;
        int dd=gcd(d,a[v]);
        if(ans[v]%dd==0)continue;
        ans[v]=max(ans[v],dd);
        work(v,dd);
    }
}
void dfsx(int x){
    ans[x]=max(ans[x],dis[fa[x]]);
    work(x,dis[fa[x]]);
    for(int i=h[x];i;i=e[i].nx){
        int y=e[i].v;
        if(y==fa[x])continue;
        dfsx(y);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n; i++){
        scanf("%d%d",&t1,&t2);
        add(t1,t2);add(t2,t1);
    }
    ans[1]=dis[1]=a[1];
    dfs(1);
    dfsx(1);
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}