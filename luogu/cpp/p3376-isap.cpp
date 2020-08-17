#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
inline ll min(ll a, ll b) {
    return a < b ? a : b;
}
int n, m, s, t;
const ll INF = 1e18;
const int NMAX = 230;
const int MMAX = 2 * 5003;
int head[NMAX], nx[MMAX], ver[MMAX], tot = 1;
ll edge[MMAX], maxflow, level[NMAX], gap[MMAX] = {0};
int now[MMAX];
queue<int> q;
inline void add(int u, int v, int w) {
    ver[++tot] = v, edge[tot] = w, nx[tot] = head[u], head[u] = tot;
    ver[++tot] = u, edge[tot] = 0, nx[tot] = head[v], head[v] = tot;
}
void bfs() {
    for (int i = 1; i <= n; i++)
        level[i] = INF;
    q.push(t);
    level[t] = 0;
    gap[0] = 1;
    now[t] = head[t];
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nx[i]) {
            int y = ver[i];
            if (level[y] == INF) {
                q.push(y);
                now[y] = head[y];
                level[y] = level[x] + 1;
                gap[level[y]]++;
            }
        }
    }
}
ll dfs(int x, ll flow) {
    if (x == t) {
        maxflow += flow;
        return flow;
    }
    ll ans = 0, k, i;
    for (i = now[x]; i; i = nx[i]) {
        now[x] = i;
        int y = ver[i];
        if (edge[i] && level[y] + 1 == level[x]) {
            k = dfs(y, min(edge[i], flow - ans));
            if (k) {
                edge[i] -= k;
                edge[i ^ 1] += k;
                ans += k;
            }
            if (ans == flow)
                return ans;
        }
    }
    --gap[level[x]];
    if (!gap[level[x]])
        level[s] = n + 1;
    level[x]++;
    gap[level[x]]++;
    return ans;
}
void isap() {
    maxflow = 0;
    bfs();
    while (level[s] < n) {
        for (int i = 1; i <= n; i++)
            now[i] = head[i];
        dfs(s, INF);
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    tot = 1;
    int t1, t2, t3;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &t1, &t2, &t3);
        add(t1, t2, t3);
    }
    isap();
    printf("%lld\n", maxflow);
    return 0;
}