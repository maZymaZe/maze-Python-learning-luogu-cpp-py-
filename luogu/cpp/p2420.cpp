#include <cstdio>
const int NODEMAX = (1e5) + 10;
int n, m, q1, q2, h[NODEMAX]={0};
int vis[NODEMAX]={0};
struct edge {
    int u, v, w, nx;
} e[NODEMAX << 1];
void dfs(int root, int fa, int nw) {
    vis[root] = nw;
    for (int i = h[root]; i; i = e[i].nx) {
        if (e[i].v == fa)
            continue;
        dfs(e[i].v, e[i].u, nw ^ e[i].w);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &e[i << 1].u, &e[i << 1].v, &e[i << 1].w);
        e[(i << 1) - 1].u = e[i << 1].v;
        e[(i << 1) - 1].v = e[i << 1].u;
        e[(i << 1) - 1].w = e[i << 1].w;
        e[i << 1].nx = h[e[i << 1].u];
        h[e[i << 1].u] = i << 1;
        e[(i << 1) - 1].nx = h[e[i << 1].v];
        h[e[i << 1].v] = (i << 1) - 1;
    }
    dfs(1, 0, 0);
    scanf("%d", &m);
    for(int i=1;i<=m;i++){
        scanf("%d%d", &q1, &q2);
        printf("%d\n",vis[q1]^vis[q2]);
    }
    return 0;
}