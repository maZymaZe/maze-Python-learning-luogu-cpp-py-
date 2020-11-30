#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=10002;
struct EDGE{
    int u,v,nx;
}e[NMAX*2];
int ep=0,h[NMAX],n,c[NMAX],t,ans=1;
void add(int a,int b){
    e[++ep]={a,b,h[a]};
    h[a]=ep;
}
void dfs(int x,int cc,int fa){
    for(int i=h[x];i;i=e[i].nx){
        int v=e[i].v;
        if(v==fa)continue;
        if(c[v]!=cc)ans++;
        dfs(v,c[v],x);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&t);
        add(i,t);
        add(t,i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }
    dfs(1,c[1],0);
    printf("%d\n",ans);
    return 0;
}