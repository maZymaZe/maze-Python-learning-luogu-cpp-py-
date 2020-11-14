#include <cstdio>
int n, m, a[30], b[30][30], v[30], maxl = 40, ans[30], nt = 0, nw[30];
void dfs(int p, int d) {
    if (d > maxl)
        return;
    if (nt == (1 << n) - 1) {
        if (d < maxl) {
            for (int i = 1; i <= d; i++)
                ans[i] = v[i];
            maxl = d;
        } else if (d == maxl) {
            bool f = 0;
            for (int i = 1; i <= d; i++) {
                if (f == 1 || v[i] <= ans[i]) {
                    if (v[i] < ans[i])
                        f = 1;
                    ans[i] = v[i];
                } else
                    break;
            }
        }
        return;
    }
    if (p > m)
        return;
    v[d + 1] = p;
    for (int i = 1; i <= n; i++) {
        nw[i] += b[p][i];
        if (nw[i] >= a[i])
            nt |= 1 << (i - 1);
    }
    dfs(p + 1, d + 1);
    for (int i = 1; i <= n; i++) {
        nw[i] -= b[p][i];
        if (nw[i] < a[i])
            nt &= ~(1 << (i - 1));
    }
    v[d + 1] = 0;
    dfs(p + 1, d);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &b[i][j]);
    }
    dfs(1, 0);
    printf("%d ", maxl);
    for (int i = 1; i <= maxl; i++)
        printf("%d ", ans[i]);
    return 0;
}