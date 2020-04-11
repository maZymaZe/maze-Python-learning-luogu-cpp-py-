#include<cstdio>
#include<cstring>
#define INF 150000000000
long long n,m,u[50001],v[50001],w[50001],d[1501],t;
void bf(){
    scanf("%lld%lld",&n,&m);
    int f=0;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
        w[i]*=-1;
    }
    for(int i=1;i<=n;i++)
    d[i]=INF;
    d[1]=0;
    for(int i=1;i<=n-1;i++){
        f=1;
        for(int j=1;j<=m;j++){
            if(d[v[j]]>d[u[j]]+w[j]){
                d[v[j]]=d[u[j]]+w[j];
               
            }
        }
       
    }
    if(d[n]>1e10)printf("-1");
    else printf("%lld",-d[n]);
}
int main(){
    bf();
    return 0;
}