#include <cstdio>
#include <cstring>
int n, m, a[230][230], t, vis[203], ans = 0, cow[203], d;
bool dfs(int x) {
    for (int i = 1; i <= m; i++) {
        if ((!vis[i]) && a[x][i]) {
            vis[i] = 1;
            if (cow[i] == 0 || dfs(cow[i])) {
                cow[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d);
        for (int j = 1; j <= d; j++) {
            scanf("%d", &t);
            a[i][t] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}