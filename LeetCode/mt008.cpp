#include <cstdio>
const int NMAX = 50003;
struct EDGE {
    int u, v, nx;
} e[NMAX << 1];
int ep = 0, h[NMAX];
void add(int u, int v) {
    e[++ep] = {u, v, h[u]};
    h[u] = ep;
    e[++ep] = {v, u, h[v]};
    h[v] = ep;
}
int ss[NMAX], tt[NMAX];
void dfs(int p, int d, int f, int a[]) {
    a[p] = d;
    for (int i = h[p]; i; i = e[i].nx) {
        if (e[i].v != f) {
            dfs(e[i].v, d + 1, p, a);
        }
    }
}
int main() {
    int s, t, n, t1, t2;
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2);
    }
    dfs(s, 0, -1, ss);
    dfs(t, 0, -1, tt);
    int ans = 0, rs;
    for (int i = 1; i <= n; i++) {
        if (ss[i] > tt[i] && ss[i] > ans)
            ans = ss[i];
    }
    printf("%d\n", ans);
    return 0;
}
