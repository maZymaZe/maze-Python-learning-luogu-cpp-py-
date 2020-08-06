#include <cstdio>
#include<algorithm>
using namespace std;
struct edge{
    int u, v,w;
    bool operator <(const edge&x){
        if(w<x.w)return 1;
        if(w==x.w){
            if(u<x.u)return 1;
            if(u==x.u){
                if(v<x.v)return 1;
            }
        }
        return 0;
    }
}e[10003];
int f[105],n,t,tot=0,cnt=0,p=1,ans=0;
int ff(int x) {
    if(f[x]==x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&t);
            if(i<j){
                ++tot;
                e[tot]={i,j,t};
            }
        }
    }
    sort(e+1,e+1+tot);
    while(cnt<n-1){
        if(ff(e[p].u)==ff(e[p].v)){
            p++;
            continue;
        }
        f[ff(e[p].u)]=ff(e[p].v);
        ans+=e[p].w;
        cnt++;
        p++;
    }
    printf("%d\n",ans);
    return 0;
}