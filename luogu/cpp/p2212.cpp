#include<algorithm>
#include<cstdio>
using namespace std;
int f[2001],n,m=0,cnt=0,p=1,c,x[2001],y[2001];
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
}e[4000008];
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<= n; i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int r=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
            if(r>=c){
                m++,e[m].u=i,e[m].v=j,e[m].w=r;
            }
        }
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
    else printf("-1");
    return 0;
}