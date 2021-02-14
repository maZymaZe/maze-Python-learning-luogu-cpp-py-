#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10;
int n, c[NMAX], t1, t2, h[NMAX], ep = 0;
struct EDGE {
    int u, v, nx;
} e[NMAX << 1];
void add(int u, int v) {
    e[++ep] = {u, v, h[u]};
    h[u] = ep;
}
int sz[NMAX], son[NMAX], ctl[NMAX], top, num[NMAX];
void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int i = h[u]; i; i = e[i].nx) {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}
long long ans[NMAX], sum[NMAX];
void update(int u, int fa, int va) {
    sum[num[c[u]]] -= c[u];
    num[c[u]] += va;
    sum[num[c[u]]] += c[u];
    if (sum[top + 1])
        ++top;
    if (!sum[top])
        top--;
    for (int i = h[u]; i; i = e[i].nx) {
        if (e[i].v != fa && !ctl[e[i].v])
            update(e[i].v, u, va);
    }
}
void dfs2(int u, int fa, int keep) {
    for (int i = h[u]; i; i = e[i].nx) {
        int v = e[i].v;
        if (v == fa || v == son[u])
            continue;
        dfs2(v, u, 0);
    }
    if (son[u]) {
        dfs2(son[u], u, 1);
        ctl[son[u]] = 1;
    }
    update(u, fa, 1);
    ctl[son[u]] = 0;
    ans[u] = sum[top];
    if (!keep) {
        update(u, fa, -1);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2);
        add(t2, t1);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}