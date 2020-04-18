#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int f[1001],n,m,cnt=0,p=1,xx[1001],yy[1001],q=0;
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
}e[2000008];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&xx[i],&yy[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            double dd=sqrt((xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]));
            q++;
            e[q].u=i;e[q].v=j;e[q].w=dd;
            q++;
            e[q].u=j;e[q].v=i;e[q].w=dd;
        }
    }
    for(int i=1;i<=n;i++)f[i]=i;
    sort(e+1,e+1+q);
    while(cnt<n-1){
        if(fx(e[p].u)!=fx(e[p].v)){
            f[fx(e[p].u)]=fx(e[p].v);
            cnt++;
            if(cnt==n-m+1){
                printf("%.2lf",e[p].w);
                break;
            }
        }
        p++;
    }

    return 0;
}