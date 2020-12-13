#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX = 2e5+10;
int f[NMAX],n,m,ep,mp;
long long a[NMAX],mi=1e14,t1,t2,t3;
int ff(int x){
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
struct EDGE{
    long long u,v,w;
    bool operator<(const EDGE&x){
        return w<x.w;
    }
}e[NMAX*2];
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
        if(a[i]<mi)mi=a[i],mp=i;
        f[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(mp!=i){
            e[++ep]={mp,i,a[i]+a[mp]};
        }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&t1,&t2,&t3);
        e[++ep]={t1,t2,t3};
    }
    sort(e+1,e+1+ep);
    int cnt=0,p=1;
    long long ans=0;
    while(cnt<n-1){
        if(ff(e[p].u)!=ff(e[p].v)){
            f[ff(e[p].u)]=ff(e[p].v);
            ans+=e[p].w;
            cnt++;
        }
        p++;
    }
    printf("%lld",ans);
    return 0;
}