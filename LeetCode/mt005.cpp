#include <cstdio>
#include <cstring>
const int NMAX = 2004, MOD = 1e9 + 7;
struct EDGE {
    int u, v, nx;
} e[NMAX << 1];
int ep, n, k, val[NMAX], h[NMAX];
void add(int u, int v) {
    e[++ep] = {u, v, h[u]};
    h[u] = ep;
    e[++ep] = {v, u, h[v]};
    h[v] = ep;
}

long long ans, cnt;
long long dfs(int u, int fa, int idl, int vl) {
    long long ret = 0, cc = 1;

    for (int i = h[u]; i; i = e[i].nx) {
        int v = e[i].v;
        if (v != fa) {
            if ((val[v] == val[idl] && (v < idl)) ||
                (val[v] < val[idl] && val[idl] - val[v] <= k))
                cc = cc * (dfs(v, u, idl, vl) + 1) % MOD;
        }
    }

    return cc;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1, tx, ty; i < n; i++) {
        scanf("%d%d", &tx, &ty);
        add(tx, ty);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i <= n; i++) {
        long long t = 1, ret;

        t = dfs(i, -1, i, val[i]);
        ans = (ans + t) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}