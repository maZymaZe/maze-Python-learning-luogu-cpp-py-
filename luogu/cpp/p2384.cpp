#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}
const int EMAX = 1e6 + 10, NMAX = 1e3 + 10, MOD = 9987, INF = 0x3f3f3f3f;
struct edge {
    int u, v, w, nx;
    double lgw;
} e[EMAX];
int h[NMAX], n, a, b, c, dis[NMAX], cnt = 0, vis[NMAX], m;
double ds[NMAX];
struct pr {
    int id;
    double s;
};
struct cmp {
    bool operator()(const pr& a, const pr& b) {
        return a.s > b.s || (a.s == b.s && a.id < b.id);
    }
};
priority_queue<pr, vector<pr>, cmp> q;
inline void add(int u, int v, int w) {
    e[++cnt] = {u, v, w, h[u], log10(1.0 * w)};
    h[u]=cnt;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        a = Read(), b = Read(), c = Read();
        add(a, b, c);
    }
    for (int i = 1; i <= n; i++)
        ds[i] = INF, dis[i] = 1;
    ds[1] = 0;

    q.push({1, 0});
    while (!q.empty()) {
        pr now = q.top();
        int x = now.id, y;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = h[x]; i; i = e[i].nx) {
            y = e[i].v;
            if (ds[x] + e[i].lgw < ds[y]) {
                ds[y] = ds[x] + e[i].lgw;
                dis[y] = (dis[x] * e[i].w) % MOD;
                q.push({y, ds[y]});
            }
        }
    }
    printf("%d", dis[n]);
    return 0;
}