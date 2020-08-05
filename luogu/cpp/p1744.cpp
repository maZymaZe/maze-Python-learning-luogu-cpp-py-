#include <cmath>
#include <cstdio>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
struct pr {
    int id;
    double dis;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) {
        return a.dis > b.dis || (a.dis == b.dis && a.id < b.id);
    }
};
struct edge {
    int u, v, nx;
    double l;
} e[2005];

int n, m, s, t, vis[200], x[200], y[200], h[200], tot = 0, t1, t2;
double d[200];
inline void add(int u, int v) {
    tot++;
    e[tot].u = u;
    e[tot].v = v;
    e[tot].nx = h[u];
    h[u] = tot;
    e[tot].l =
        sqrt((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
priority_queue<pr, vector<pr>, cmp> q;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2), add(t2, t1);
    }
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[s] = 0;
    vis[s] = 1;
    q.push({s, 0});
    while (!q.empty()) {
        pr now = q.top();
        q.pop();
        for (int i = h[now.id]; i; i = e[i].nx) {
            if (d[now.id] + e[i].l < d[e[i].v]) {
                d[e[i].v] = d[now.id] + e[i].l;
                if (!vis[e[i].v]) {
                    vis[e[i].v] = 1;
                    q.push({e[i].v, d[e[i].v]});
                }
            }
        }
    }
    printf("%.2lf", d[t]);
    return 0;
}
