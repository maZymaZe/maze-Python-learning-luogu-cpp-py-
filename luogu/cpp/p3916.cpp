#include <cstdio>
int ans[100004], n, m, h[100004], t1, t2;
struct edge {
    int u, v, nx;
} e[100003];
void dfs(int w, int x) {
    ans[w] = x;
    for (int i = h[w]; i; i = e[i].nx) {
        if (!ans[e[i].v]) {
            dfs(e[i].v, x);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t2, &t1);
        e[i].u = t1;
        e[i].v = t2;
        e[i].nx = h[t1];
        h[t1] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (!ans[i]) {
            dfs(i, i);
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}