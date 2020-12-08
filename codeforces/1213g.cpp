#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=2e5+10;
struct edge{
    int u,v,w; 
    bool operator<(const edge&x){
        return w<x.w;
    }
}e[NMAX];
int f[NMAX],n,m,t,q[NMAX],mm=0;
long long ans[NMAX],c[NMAX]={0};
int ff(int x){
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){f[i]=i,c[i]=1;}
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+n);
    for(int i=1;i<=m;i++){
        scanf("%d",&q[i]);
        if(q[i]>mm)mm = q[i];
    }
    int p=1;
    for(int i=1;i<=mm;i++){
        ans[i]=ans[i-1];
        while(p<n&&e[p].w<=i){
            if(ff(e[p].u)!=ff(e[p].v)){
                ans[i]+=c[ff(e[p].u)]*c[ff(e[p].v)];
                long long tot=c[ff(e[p].u)]+c[ff(e[p].v)];
                f[ff(e[p].u)]=ff(e[p].v);
                c[ff(e[p].u)]=tot;
                c[ff(e[p].v)]=tot;
            }
            p++;
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",ans[q[i]]);
    }
    return 0;
}