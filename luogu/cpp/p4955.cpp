#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct EDGE{
    int u,v,w;
    bool operator <(const EDGE& x){ return w<x.w;}
}e[510005];
int ep=0;
void add(int a, int b, int c){
    e[++ep]={a,b,c};
}
int f[260000],n,m,tot,sz[260000],cnt,mp[260000];
int ff(int x){ return f[x]==x ? x: f[x]=ff(f[x]);}
int main(){
    scanf("%d%d",&n,&m);
    tot=n*m;
    for(int i=1;i<=tot;i++){
        scanf("%d",&mp[i]);
        f[i]=i;
    }
    for(int i=1;i<=tot;i++){
        scanf("%d",&sz[i]);
        cnt+=sz[i];
    }
    for(int i=1;i<=tot;i++){
        if(i>m)add(i,i-m,abs(mp[i]-mp[i-m]));
        if(i%m!=1)add(i,i-1,abs(mp[i-1]-mp[i]));
    }
    if(cnt<2){
        printf("0\n");
        return 0;
    }
    sort(e+1,e+1+ep);
    for(int i=1;i<=ep;i++){
        int u=e[i].u,v=e[i].v;
        int fu=ff(u),fv=ff(v);
        if(fu!=fv){
            f[fv]=fu;
            sz[fu]+=sz[fv];
            if(sz[fu]==cnt){
                printf("%d\n",e[i].w);
                return 0;
            }
        }
    }
    return 0;
}
