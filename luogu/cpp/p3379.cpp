#include <cstdio>
#define MAX 500005
inline int read() {
    int f = 1, ref = 0;
    char c;
    while (c = getchar(), !(c >= '0' && c <= '9'))
        if (c == '-') f = -1;
    while (c >= '0' && c <= '9') ref = ref * 10 + (c - '0'), c = getchar();
    return f * ref;
}
int n, m, s, ans[MAX], h[MAX], father[MAX], qh[MAX];
bool vis[MAX];
int f(int x) {
    if (father[x] == x)
        return x;
    else
        return father[x] = f(father[x]);
}
struct edge {
    int u, v, nx;
} e[MAX << 1];
struct que {
    int u, v, nx, sm, l;
    bool flag;
    que() { flag = false; }
} q[MAX << 1];
void tarjan(int x, int pp) {
    for (int i = h[x]; i; i = e[i].nx) {
        if (e[i].v == pp || vis[e[i].v]) continue;
        tarjan(e[i].v, e[i].u);
        father[e[i].v] = f(x);
        vis[e[i].v] = true;
    }
    for (int i = qh[x]; i; i = q[i].nx) {
        if ((!q[i].flag )&& vis[q[i].v]) {
            ans[q[i].l] = f(q[i].v);
            q[i].flag = true;
            q[q[i].sm].flag = true;
        }
    }
}
int main() {
    n = read();
    m = read();
    s = read();
    int t1, t2;
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i < n; i++) {
        t1 = read();
        t2 = read();
        e[(i << 1) - 1].u = t1;
        e[(i << 1) - 1].v = t2;
        e[(i << 1) - 1].nx = h[t1];
        h[t1] = (i << 1) - 1;
        e[(i << 1)].u = t2;
        e[(i << 1)].v = t1;
        e[(i << 1)].nx = h[t2];
        h[t2] = (i << 1);
    }
    for (int i = 1; i <= m; i++) {
        t1 = read();
        t2 = read();
        q[(i << 1) - 1].u = t1;
        q[(i << 1) - 1].v = t2;
        q[(i << 1) - 1].nx = qh[t1];
        qh[t1] = (i << 1) - 1;
        q[(i << 1) - 1].sm = (i << 1);
        q[(i << 1) - 1].l = i;
        q[(i << 1)].u = t2;
        q[(i << 1)].v = t1;
        q[(i << 1)].nx = qh[t2];
        qh[t2] = (i << 1);
        q[(i << 1)].l = i;
        q[(i << 1)].sm = (i << 1) - 1;
    }
    tarjan(s, 0);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}