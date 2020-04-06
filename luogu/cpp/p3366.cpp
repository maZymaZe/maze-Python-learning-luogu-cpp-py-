#include<algorithm>
#include<cstdio>
using namespace std;
int f[5001],n,m,cnt=0,p=1;
long long ans=0;
int fx(int x){
    if(f[x]==x)return x;
    else return f[x]=fx(f[x]);
}
struct edge{
    int u,v,w;
    bool operator <(const edge&x){
        return w<x.w;
    }
}e[200008];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(e+1,e+1+m);
    while(cnt<n-1&&p<=m){
        if(fx(e[p].u)!=fx(e[p].v)){
            f[fx(e[p].u)]=fx(e[p].v);
            ans+=e[p].w;
            cnt++;
        }
        p++;
    }
    if(cnt==n-1)printf("%lld",ans);
    else printf("orz");
    return 0;
}