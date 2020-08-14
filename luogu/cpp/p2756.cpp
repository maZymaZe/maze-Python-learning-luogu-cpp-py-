#include <cstdio>
#include<cstring>
const int NMAX = 103;
struct edge {
    int u, v, nx;
} e[NMAX * NMAX];
int n, m, ans=0,tot = 0, h[NMAX], t1, t2, link[NMAX];
bool vis[NMAX];
bool dfs(int x) {
    for (int i = h[x]; i; i = e[i].nx) {
        if (!vis[e[i].v]) {
            vis[e[i].v]=1;
            if (!link[e[i].v] || dfs(link[e[i].v])) {
                link[e[i].v] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &m, &n);
    scanf("%d%d", &t1, &t2);
    while (t1 != -1) {
        ++tot;
        e[tot].u = t1, e[tot].v = t2, e[tot].nx = h[t1];
        h[t1] = tot;
        scanf("%d%d", &t1, &t2);
    }
    for(int i =1;i<=m;i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ans++;
    }
    printf("%d\n",ans);
    for(int i=1+m;i<=n;i++){
        if(link[i])printf("%d %d\n",link[i],i);
    }
    return 0;
}