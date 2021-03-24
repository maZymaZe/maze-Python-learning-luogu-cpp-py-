#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 3e5 + 15;
struct EDGE {
    int u, v, nx;
} e[NMAX << 1];
int ep = 1, h[NMAX], n, t1, t2, c[NMAX], ans[NMAX], dp[NMAX];
void add(int u, int v) {
    e[++ep] = {u, v, h[u]};
    h[u] = ep;
    e[++ep] = {v, u, h[v]};
    h[v] = ep;
}
void dfs1(int x, int fa) {
    dp[x] = c[x];
    for (int i = h[x]; i; i = e[i].nx) {
        int y = e[i].v;
        if (y == fa)
            continue;
        dfs1(y, x);
        dp[x] += max(0, dp[y]);
    }
}
void dfs2(int x, int fa) {
    if (dp[x] > 0)
        ans[x] = max(ans[fa], dp[x]);
    else {
        ans[x] = max(ans[fa] + c[x], c[x]);
        for (int i = h[x]; i; i = e[i].nx) {
            int y = e[i].v;
            if (y == fa)
                continue;
            ans[x] += max(dp[y], 0);
        }
    }
    for (int i = h[x]; i; i = e[i].nx) {
        int y = e[i].v;
        if (y == fa)
            continue;
        dfs2(y, x);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] == 0)
            c[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2);
    }
    dfs1(1, 0);
    ans[1] = dp[1];
    for (int i = h[1]; i; i = e[i].nx) {
        dfs2(e[i].v, 1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}