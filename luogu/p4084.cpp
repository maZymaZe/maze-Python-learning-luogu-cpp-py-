#include <cstdio>
const int NMAX = 1e5 + 10;
const int MOD = 1e9 + 7;
struct edge {
    int u, v, nx;
} e[NMAX << 1];
int tot = 0, h[NMAX], k, n, t1, t2;
long long ans[NMAX] = {0};
inline void add(int u, int v) {
    ++tot;
    e[tot].u = u, e[tot].v = v;
    e[tot].nx = h[u], h[u] = tot;
}
long long dp[NMAX][4] = {0};
void dfs(int p, int fa) {
    if ((!dp[p][1]) && (!dp[p][2]) && (!dp[p][0])) {
        dp[p][1] = dp[p][2] = dp[p][0] = 1;
    }
    for (int i = h[p]; i; i = e[i].nx) {
        if (e[i].v != fa) {
            dfs(e[i].v, p);
            dp[p][0] = (dp[p][0] * (dp[e[i].v][1] + dp[e[i].v][2])) % MOD;
            dp[p][1] = (dp[p][1] * (dp[e[i].v][0] + dp[e[i].v][2])) % MOD;
            dp[p][2] = (dp[p][2] * (dp[e[i].v][0] + dp[e[i].v][1])) % MOD;
        }
    }
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2);
        add(t2, t1);
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d%d", &t1, &t2);
        dp[t1][--t2] = 1;
    }
    long long ans = 0;
    dfs(1,0);
    for (int i = 0; i < 3; i++) {
        ans = (ans + dp[1][i]) % MOD;
    }

    printf("%lld", ans);
    return 0;
}