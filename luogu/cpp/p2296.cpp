#define MAX 10005
#define EMAX 200005
#define INF 2000000000
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct pr {
    int d, p;
};
struct edge {
    int u, v;
    int nx;
} e[EMAX], fe[EMAX];
struct cmp {
    bool operator()(pr a, pr b) { return a.d > b.d; }
};
priority_queue<pr, vector<pr>, cmp> fq, q;
int head[MAX], vis[MAX], dis[MAX], cnt, n, m, s, t, t1, t2, t3, fhead[MAX],
    fvis[MAX], fdis[MAX];
int uok[MAX] = {0};
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t1, &t2);
        e[i].u = t1;
        e[i].v = t2;
        e[i].nx = head[e[i].u];
        head[e[i].u] = i;
        fe[i].v = t1;
        fe[i].u = t2;
        fe[i].nx = fhead[fe[i].u];
        fhead[fe[i].u] = i;
    }
    scanf("%d%d", &s, &t);
    for (int i = 1; i <= n; i++)
        fdis[i] = INF;
    fdis[t] = 0;
    fq.push({0, t});
    while (!fq.empty()) {
        pr now = fq.top();
        fq.pop();
        if (fvis[now.p])
            continue;
        fvis[now.p] = 1;
        for (int i = fhead[now.p]; i; i = fe[i].nx) {
            int vv = fe[i].v;
            if (fdis[vv] > fdis[now.p] + 1) {
                fdis[vv] = fdis[now.p] + 1;
                fq.push({fdis[vv], vv});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j; j = e[j].nx) {
            if (fdis[e[j].v] == INF) {
                uok[i] = -1;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    uok[s] = 0;
    uok[t] = 0;
    q.push({0, s});
    while (!q.empty()) {
        pr now = q.top();
        q.pop();
        if (vis[now.p] || uok[now.p] == -1)
            continue;
        vis[now.p] = 1;
        for (int i = head[now.p]; i; i = e[i].nx) {
            int vv = e[i].v;
            if (dis[vv] > dis[now.p] + 1) {
                dis[vv] = dis[now.p] + 1;
                q.push({dis[vv], vv});
            }
        }
    }
    if (dis[t] == INF)
        printf("-1");
    else
        printf("%d", dis[t]);
    return 0;
}
