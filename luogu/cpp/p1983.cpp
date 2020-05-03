#include <cstdio>
#include <cstring>
int vis[1005], n, m, cp[1005][1005], s, tt[1005], stop[1005], iss[1005],
    indegree[1005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s);
        memset(iss, 0, sizeof(iss));
        for (int j = 1; j <= s; j++) {
            scanf("%d", &stop[j]);
            iss[stop[j]] = 1;
        }
        for (int j = stop[1]; j <= stop[s]; j++) {
            if (!iss[j]) {
                for (int k = 1; k <= s; k++) {
                    if (!cp[j][stop[k]]) {
                        cp[j][stop[k]] = 1, indegree[stop[k]]++;
                    }
                }
            }
        }
    }
    int tp = 1, ans = -1;
    do {
        tp = 0;
        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0 && !vis[i]) {
                tt[++tp] = i, vis[i] = 1;
            }
        for (int i = 1; i <= tp; i++)
            for (int j = 1; j <= n; j++)
                if (cp[tt[i]][j]) cp[tt[i]][j] = 0, indegree[j]--;
        ans++;
    } while (tp);
    printf("%d", ans);
    return 0;
}