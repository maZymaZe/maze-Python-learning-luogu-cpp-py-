#include<algorithm>
#include<cstdio>
using namespace std;
int f[501],n,m,cnt=0,p=1,t;
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
}e[250008];
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&t);
            if(t>m)t=m;
            if(i==j)e[(i-1)*n+j].w=9999999;
            else{
                if(t==0)e[(i-1)*n+j].u=i,e[(i-1)*n+j].v=j,e[(i-1)*n+j].w=m;
                else e[(i-1)*n+j].u=i,e[(i-1)*n+j].v=j,e[(i-1)*n+j].w=t;
            }
        }
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(e+1,e+1+n*n);
    while(cnt<n-1&&p<=n*n){
        if(fx(e[p].u)!=fx(e[p].v)){
            f[fx(e[p].u)]=fx(e[p].v);
            ans+=e[p].w;
            cnt++;
        }
        p++;
    }
    if(cnt==n-1)printf("%lld",ans+m);
    else printf("orz");
    return 0;
}