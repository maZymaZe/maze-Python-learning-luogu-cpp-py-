#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int f[501],n,m,cnt=0,p=1,x[501],y[501],tot=0;
long long ans=0;
int fx(int x){
    if(f[x]==x)return x;
    else return f[x]=fx(f[x]);
}
struct edge{
    int u,v;
    double w;
    bool operator <(const edge&x){
        return w<x.w;
    }
}e[300008];
void add(int u,int v){
    tot++;
    e[tot].u=u;e[tot].v=v;
    e[tot].w=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            add(i,j);
            add(j,i);
        }
    }
    for(int i=1;i<=m;i++)f[i]=i;
    sort(e+1,e+1+tot);
    while(cnt<m-1&&p<=tot){
        if(fx(e[p].u)!=fx(e[p].v)){
            f[fx(e[p].u)]=fx(e[p].v);
            ans+=e[p].w;
            cnt++;
            if(cnt==m-1-n+1){
                printf("%.2lf",e[p].w);
            }
        }
        p++;
    }
    
    return 0;
}