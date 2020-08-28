#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAXM = 1e5 + 10;
const int MAXN = 5050;
bool vis[MAXN];
int n, m, s, t, x, y, z, f, dis[MAXN], pre[MAXN], last[MAXN], flow[MAXN],
    maxflow, mincost;
struct edge {
    int u, v, nx, flow, dis;
} e[MAXM];
int h[MAXN], etot = 1;
queue<int> q;
bool spfa(int s, int t) {
    memset(dis, 0x7f, sizeof(dis));
    memset(flow, 0x7f, sizeof(flow));
    memset(vis, 0, sizeof(vis));
    q.push(s), vis[s] = 1, dis[s] = 0, pre[t] = -1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int i = h[now]; i; i = e[i].nx) {
            int nxt = e[i].v;
            if (e[i].flow > 0 && dis[nxt] > dis[now] + e[i].dis) {
                dis[nxt] = dis[now] + e[i].dis;
                pre[nxt] = now;
                last[nxt] = i;
                flow[nxt] = min(flow[now], e[i].flow);
                if (!vis[nxt]) {
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }
    return pre[t] != -1;
}
void MCMF() {
    while (spfa(s, t)) {
        int now = t;
        maxflow += flow[t];
        mincost += flow[t] * dis[t];
        while (now != s) {
            e[last[now]].flow -= flow[t];
            e[last[now] ^ 1].flow += flow[t];
            now = pre[now];
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &x, &y, &z, &f);
        e[++etot] = {x, y, h[x], z, f};
        h[x] = etot;
        e[++etot] = {y, x, h[y], 0, -f};
        h[y] = etot;
    }
    MCMF();
    printf("%d %d", maxflow, mincost);
    return 0;
}