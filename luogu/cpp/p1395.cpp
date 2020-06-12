#include <cstdio>
#define MAX 50005
struct edge {
    int u, v, nx;
} e[MAX*2];
int cnt=0, h[MAX]={0}, n, t1, t2, dp[MAX]={0}, nw[MAX]={0}, res, id = 1;
void add(int a, int b) {
    cnt++;
    e[cnt].u = a;
    e[cnt].v = b;
    e[cnt].nx = h[a];
    h[a] = cnt;
}
int dfs(int p, int f, int dep) {
    dp[p] = 1;
    int ans = 0;
    nw[1] += dep;
    for (int i = h[p]; i; i = e[i].nx) {
        if (e[i].v != f)
            ans += dfs(e[i].v, e[i].u, dep + 1);
    }
    dp[p] += ans;
    return dp[p];
}
void dfsx(int p, int f) {
    nw[p] = nw[f] + n - 2 * dp[p];
    for (int i = h[p]; i; i = e[i].nx) {
        if (e[i].v != f)
            dfsx(e[i].v, e[i].u);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2);
        add(t2, t1);
    }
    dfs(1, 0, 0);
    for (int i = h[1]; i; i = e[i].nx) {
        dfsx(e[i].v, 1);
    }
    res = nw[1];
    for (int i = 2; i <= n; i++) {
        if (res > nw[i])
            id = i, res = nw[i];
    }
    printf("%d %d", id, res);
    return 0;
}