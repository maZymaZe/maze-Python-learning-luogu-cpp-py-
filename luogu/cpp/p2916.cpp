#include <algorithm>
#include <cstdio>
using namespace std;
const int MMAX = 1e5 + 10, NMAX = 1e4 + 10;
struct edge {
    int u, v, w;
    bool operator<(const edge& x) { return w < x.w; }
} e[MMAX];
int f[NMAX], n, t1, t2, m, a[NMAX], l[MMAX], mi = 88888888;
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i, scanf("%d", &a[i]), mi = min(mi, a[i]);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &e[i].u,&e[i].v,&e[i].w);
        e[i].w = 2*e[i].w + a[e[i].u] + a[e[i].v] ;
    }
    sort(e+1,e+1+m);
    int cnt=0,p=1;
    long long ans=0;
    while(cnt<n-1){
        if(p<=m&&ff(e[p].u)!=ff(e[p].v)){
            f[ff(e[p].u)]=ff(e[p].v);
            ans+=e[p].w;
            cnt++;
        }
        p++;
    }
    printf("%lld\n",ans+mi);
    return 0;
}
