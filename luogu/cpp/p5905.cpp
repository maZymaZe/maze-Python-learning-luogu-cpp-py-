#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int NMAX = 3e3 + 10, MMAX = 1e4 + 10, INF = 1e9;
struct EDGE {
    int u, v, w, nx;
} e[MMAX];
int h[NMAX], ep = 0;
void add(int u, int v, int w) {
    e[++ep] = {u, v, w, h[u]};
    h[u] = ep;
}
struct NODE {
    long long dis;
    int v;
    bool operator<(const NODE& other) const { return dis > other.dis; }
};
int n, m, vis[NMAX];
long long dis[NMAX][NMAX], d[NMAX];
priority_queue<NODE> q;
bool bf() {
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = h[j]; k; k = e[k].nx) {
                if (d[e[k].v] > d[e[k].u] + e[k].w) {
                    flag = 1;
                    d[e[k].v] = d[e[k].u] + e[k].w;
                }
            }
        }
        if (!flag)
            return true;
    }
    for (int j = 1; j <= n; j++) {
        for (int k = h[j]; k; k = e[k].nx) {
            if (d[e[k].v] > d[e[k].u] + e[k].w) {
                return false;
            }
        }
    }
    return true;
}
void dij(int s) {
    memset(vis, 0, sizeof(vis));
    dis[s][s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int x = q.top().v;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = h[x]; i; i = e[i].nx) {
            if (dis[s][e[i].v] > dis[s][e[i].u] + e[i].w) {
                dis[s][e[i].v] = dis[s][e[i].u] + e[i].w;
                q.push({dis[s][e[i].v], e[i].v});
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, t1, t2, t3; i <= m; i++) {
        scanf("%d%d%d", &t1, &t2, &t3);
        add(t1, t2, t3);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dis[i][j] = INF;
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    if (!bf()) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = h[i]; j; j = e[j].nx) {
            e[j].w += d[i] - d[e[j].v];
        }
    }
    for (int i = 1; i <= n; i++) {
        dij(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] == INF)
                dis[i][0] += 1ll * j * dis[i][j];
            else {
                dis[i][j] = dis[i][j] + d[j] - d[i];
                dis[i][0] += 1ll * j * dis[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", dis[i][0]);
    }
    return 0;
}