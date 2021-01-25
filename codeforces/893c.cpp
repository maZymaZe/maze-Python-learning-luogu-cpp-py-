#include<cstdio>
const int NMAX=1e5 + 10;
long long v[NMAX],ans,c[NMAX];
int n,f[NMAX],m,t1,t2,u[NMAX];
int ff(int x){return f[x] == x ? x : f[x] = ff(f[x]);}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]),v[i]=c[i],f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        f[ff(t1)]=ff(t2);
    }
    for(int i=1;i<=n;i++)if(c[i]<v[ff(i)])v[ff(i)]=c[i];
    for(int i=1;i<=n;i++)if(!u[ff(i)])ans+=v[ff(i)],u[ff(i)]=1;
    printf("%lld\n",ans);
    return 0;
}