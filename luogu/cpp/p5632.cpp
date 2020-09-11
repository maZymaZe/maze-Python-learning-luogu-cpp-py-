#include <cstdio>
#include <cstring>
int min(int a, int b) {
    return a < b ? a : b;
}
const int NMAX = 603, INF = 0x3f3f3f3f;
int n, m, x, y, z, s, t, dis[NMAX][NMAX], w[NMAX], dap[NMAX], vis[NMAX],
    ord[NMAX];
int process(int x) {
    memset(vis, 0, sizeof(vis));
    memset(w, 0, sizeof(w));
    w[0] = -1;
    for (int i = 1; i <= n - x + 1; i++) {
        int mx = 0;
        for (int j = 1; j <= n; j++) {
            if (!dap[j] && !vis[j] && w[j] > w[mx]) {
                mx = j;
            }
        }
        vis[mx] = 1, ord[i] = mx;
        for (int j = 1; j <= n; j++) {
            if (!dap[j] && !vis[j])
                w[j] += dis[mx][j];
        }
    }
    s = ord[n - x], t = ord[n - x + 1];
    return w[t];
}
int stoer_wagner() {
    int res = INF;
    for (int i = 1; i < n; i++) {
        res = min(res, process(i));
        dap[t] = 1;
        for (int j = 1; j <= n; j++) {
            dis[s][j] += dis[t][j];
            dis[j][s] += dis[j][t];
        }
    }
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        dis[x][y] += z, dis[y][x] += z;
    }
    printf("%d", stoer_wagner());
    return 0;
}
