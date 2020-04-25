#include <cmath>
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
int mi(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
int n, m, s, h[MAX], a[MAX << 1], dft = 0, dep[MAX << 1];
int vis[MAX << 1], lg[MAX << 1], st[MAX << 1][20];
struct edge {
    int u, v, nx;
} e[MAX << 1];
void dfs(int x, int pp, int deep) {
    a[x] = ++dft;
    vis[dft] = x;
    dep[dft] = deep;
    for (int i = h[x]; i; i = e[i].nx) {
        if (e[i].v == pp) continue;
        dfs(e[i].v, e[i].u, deep + 1);
        vis[++dft] = x;
        dep[dft] = deep;
    }
}
int rs(int p, int q) {
    int d = lg[q - p + 1] - 1;
    if (dep[st[p][d]] <= dep[st[q - (1 << d) + 1][d]])
        return vis[st[p][d]];
    else
        return vis[st[q - (1 << d) + 1][d]];
}

int main() {
    n = read();
    m = read();
    s = read();
    int t1, t2;
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
    dfs(s, 0, 1);
    for (int i = 1; i <= dft; i++) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    for (int i = 1; i <= dft; i++) st[i][0] = i;
    for (int j = 1; (1 << j) <= dft; j++) {
        for (int i = 1; i - 1 <= dft - (1 << j); i++) {
            t1 = st[i][j - 1];
            t2 = st[i + (1 << (j - 1))][j - 1];
            if (dep[t1] <= dep[t2])
                st[i][j] = t1;
            else
                st[i][j] = t2;
        }
    }
    for (int i = 1; i <= m; i++) {
        t1 = read();
        t2 = read();
        int l = a[t1], r = a[t2];
        if (l > r) {
            int tmp = l;
            l = r;
            r = tmp;
        }
        printf("%d\n", rs(l, r));
    }
    return 0;
}