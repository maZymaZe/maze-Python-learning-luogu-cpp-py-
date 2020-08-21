#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int NMAX = 102 * 2, MMAX = 2008 * 2;
const int INF = 0x3f3f3f3f;
int h[NMAX], n, m, s, t, tot = 1, level[NMAX], cnt[NMAX], now[MMAX],
                         maxflow = 0, ans;
struct edge {
    int u, v, w, nx;
} e[MMAX];
void bfs() {
    for (int i = 1; i <= 2*n; i++)
        level[i] = INF;
    queue<int> q;
    q.push(t);
    level[t] = 0;
    cnt[0]++;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = h[x]; i; i = e[i].nx) {
            int y = e[i].v;
            if (level[y] == INF) {
                level[y] = level[x] + 1;
                cnt[level[y]]++;
                q.push(y);
            }
        }
    }
}
int dfs(int x, int flow) {
    if (x == t) {
        maxflow += flow;
        return flow;
    }
    int ans = 0;
    for (int i = now[x]; i; i = e[i].nx) {
        int y = e[i].v;
        now[x] = i;
        if (e[i].w && level[x] == level[y] + 1) {
            int k = dfs(y, min(flow - ans, e[i].w));
            if (k) {
                e[i].w -= k;
                e[i ^ 1].w += k;
                ans += k;
            }
            if (ans == flow)
                return ans;
        }
    }
    --cnt[level[x]];
    if (!cnt[level[x]]) {
        level[s+n] = n+n + 1;
    }
    level[x]++;
    cnt[level[x]]++;
    return ans;
}
void isap() {
    bfs();
    while (level[s+n] < 2*n) {
        for (int i = 1; i <= 2*n; i++) {
            now[i] = h[i];
        }
        dfs(s+n, INF);
    }
}
int main() {
    int t1, t2, t3;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++) {
            e[++tot] = {i, i + n, 1, h[i]};
            h[i] = tot;
            e[++tot] = {i + n, i, 0, h[i + n]};
            h[i + n] = tot;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t1, &t2);
        e[++tot] = {t1 + n, t2, INF, h[t1+n]};
        h[t1 + n] = tot;
        e[++tot] = {t2, t1 + n, 0, h[t2]};
        h[t2] = tot;

        e[++tot] = {t2 + n, t1, INF, h[t2+n]};
        h[t2 + n] = tot;
        e[++tot] = {t1, t2 + n, 0, h[t1]};
        h[t1] = tot;
    }
    isap();
    printf("%d\n", maxflow);
    return 0;
}