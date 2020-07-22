#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 2147483647;
int vis[20], lev[20], d[20], c[20][20], tar[20][20];
int ans = INF, tmp, tot, cnt, n, m, p;
bool cmp(const int& a, const int& b) {
    return c[p][a] < c[p][b];
}
void dfs(int num, int node) {
    for (int i = num; i <= cnt; i++) {
        if (tot + tmp * lev[vis[i]] >= ans)
            return;
        for (int j = node; j <= d[vis[i]]; j++) {
            if (!lev[tar[vis[i]][j]]) {
                cnt++;
                vis[cnt] = tar[vis[i]][j];
                tmp -= c[vis[cnt]][tar[vis[cnt]][1]];
                tot += c[vis[i]][vis[cnt]] * lev[vis[i]];
                lev[vis[cnt]] = lev[vis[i]] + 1;
                dfs(i, j + 1);
                tot -= c[vis[i]][vis[cnt]] * lev[vis[i]];
                lev[vis[cnt]] = 0;
                tmp += c[vis[cnt]][tar[vis[cnt]][1]];
                cnt--;
            }
        }
        node = 1;
    }
    if (cnt == n) {
        if (tot < ans)
            ans = tot;
        return;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int u, v, w;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        if (w > c[u][v])
            continue;
        if (c[u][v] == INF) {
            tar[u][++d[u]] = v;
            tar[v][++d[v]] = u;
        }
        c[u][v] = c[v][u] = w;
    }
    for (int i = 1; i <= n; i++) {
        p = i;
        sort(tar[i] + 1, tar[i] + 1 + d[i], cmp);
        tmp += c[i][tar[i][1]];
    }
    for (int i = 1; i <= n; i++) {
        tot = 0, cnt = 1;
        vis[1] = i;
        tmp -= c[i][tar[i][1]];
        lev[i] = 1;
        dfs(1, 1);
        lev[i] = 0;
        tmp += c[i][tar[i][1]];
    }
    printf("%d", ans);
    return 0;
}