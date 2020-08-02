#include <cstdio>
const int MAXN = 1e6 + 5;
struct edge {
    int u, v, nx;
} e[MAXN << 1];
int h[MAXN], sz[MAXN] = {0}, n, x, y,fa[MAXN] = {0},dep[MAXN] = {0};
long long up[MAXN]={0};
void dfs(int root, int father) {
    sz[root] = 1;
    dep[root]=dep[father]+1;
    for (int i = h[root]; i; i = e[i].nx) {
        if (e[i].v == father)
            continue;
        fa[e[i].v] = root;
        dfs(e[i].v, root);
        sz[root]+=sz[e[i].v];
    }
}
void dfs2(int root) {
    for (int i = h[root]; i; i = e[i].nx) {
        
        if (e[i].v != fa[root])
            up[e[i].v]=up[e[i].u]-sz[e[i].v]*2+n,
            dfs2(e[i].v);
    }
    
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        e[i << 1].u = x, e[i << 1].v = y;
        e[i << 1].nx = h[x], h[x] = (i << 1);
        e[(i << 1) - 1].u = y, e[(i << 1) - 1].v = x;
        e[(i << 1) - 1].nx = h[y], h[y] = (i << 1) - 1;
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++)up[1]+=dep[i];
    dfs2(1);
    long long ans = 0;
    int ret;
    for (int i = 1; i <= n; i++) {
        if (up[i]  > ans)
            ans = up[i] ,ret = i;
    }
    printf("%d\n", ret);
    return 0;
}