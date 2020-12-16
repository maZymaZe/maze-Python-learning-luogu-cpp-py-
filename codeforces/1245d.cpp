#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int NMAX=2004;
struct EDGE{
    int u,v;
    long long w;
    bool operator<(const EDGE&x){
        return w<x.w;
    }
}e[NMAX*NMAX];
long long x[NMAX],y[NMAX],c[NMAX],k[NMAX];
int n,f[NMAX],ep=0,t1,t2,t3,st[NMAX],p=0,cn[2][NMAX],pp;
int ff(int x){
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
void add(int a,int b,long long c){
    e[++ep]={a,b,c};
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x[i],&y[i]);
        f[i]=i;
    }
    for(int i=1;i<=n;i++){scanf("%lld",&c[i]);add(0,i,c[i]);}
    for(int i=1;i<=n;i++){scanf("%lld",&k[i]);}
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            add(i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
        }
    }
    sort(e+1,e+1+ep);
    int cnt=0,fx,fy;
    long long ans=0;
    for(int i=1;i<=ep;i++){
        fx=ff(e[i].u),fy=ff(e[i].v);
        if(fx!=fy){
            cnt++;
            f[fx]=fy;
            ans+=e[i].w;
            if(!e[i].u){
                st[++p]=e[i].v;
            }else{
                cn[0][++pp]=e[i].u;
                cn[1][pp]=e[i].v;
            }
        }
        if(cnt==n)break;
    }
    printf("%lld\n%d\n",ans,p);
    for(int i=1;i<p;i++)printf("%d ",st[i]);
    printf("%d\n",st[p]);
    printf("%d\n",pp);
    for(int i=1;i<=pp;i++)printf("%d %d\n",cn[0][i],cn[1][i]);
    return 0;
}