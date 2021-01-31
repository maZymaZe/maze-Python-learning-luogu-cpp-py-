#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int NMAX = 2e5 + 10;
int n, m, f1[NMAX], used[NMAX], cnt = 0, h[NMAX];
int fa[NMAX][21], dep[NMAX], A[NMAX][21];
ll S, ans, dis[NMAX][21], q[2], tot;
int ff1(int x) {
    return f1[x] == x ? x : f1[x] = ff1(f1[x]);
}
struct EDGE {
    int nx, to, id;
    ll ds;
} e[NMAX << 1];
void add(int x, int y, ll z, int w) {
    e[++cnt].nx = h[x], e[cnt].to = y, e[cnt].ds = z, e[cnt].id = w, h[x] = cnt;
}
struct NODE {
    int x, y, id;
    ll z, c;
} b[NMAX];
bool cmp1(const NODE& a, const NODE& b) {
    if (a.z != b.z)
        return a.z < b.z;
    return a.c < b.c;
}
void dfs(int x, int f, int deep) {
    dep[x] = deep;
    fa[x][0] = f;
    for (int i = 1; i <= 20; i++) {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        if (dis[x][i - 1] > dis[fa[x][i - 1]][i - 1])
            dis[x][i] = dis[x][i - 1], A[x][i] = A[x][i - 1];
        else
            dis[x][i] = dis[fa[x][i - 1]][i - 1],
            A[x][i] = A[fa[x][i - 1]][i - 1];
    }
    for (int i = h[x]; i; i = e[i].nx) {
        int v = e[i].to;
        if (v == f)
            continue;
        dis[v][0] = e[i].ds;
        A[v][0] = e[i].id;
        dfs(v, x, deep + 1);
    }
}
struct rp {
    ll x, d;
} ANS[NMAX];
bool cmp2(const rp& a, const rp& b) {
    return a.x < b.x;
}
rp ldis(int x, int y) {
    ll res = 0, idx;
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            if (res < dis[x][i])
                res = dis[x][i], idx = A[x][i];
            x = fa[x][i];
        }
    }
    if (x == y)
        return {idx, res};
    for (int i = 20; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            if (res < dis[x][i])
                res = dis[x][i], idx = A[x][i];
            if (res < dis[y][i])
                res = dis[y][i], idx = A[y][i];
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if (res < dis[x][0])
        res = dis[x][0], idx = A[x][0];
    if (res < dis[y][0])
        res = dis[y][0], idx = A[y][0];
    return {idx, res};
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i].z);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i].c);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &b[i].x, &b[i].y);
        b[i].id = i;
    }
    scanf("%lld", &S);
    sort(b + 1, b + 1 + m, cmp1);
    for (int i = 0; i <= n; i++)
        f1[i] = i;
    ll minn = INF, sum = 0, idx = 0;
    for (int i = 1; i <= m; i++) {
        int fx = ff1(b[i].x), fy = ff1(b[i].y);
        if (fx != fy) {
            f1[fx] = fy;
            sum += b[i].z;
            used[i] = 1;
            if (b[i].c < minn)
                minn = b[i].c, idx = i;
            add(b[i].x, b[i].y, b[i].z, i);
            add(b[i].y, b[i].x, b[i].z, i);
        }
    }
    ans = sum - S / minn;
    dfs(1, 0, 1);
    for (int i = 1; i <= m; i++) {
        if (used[i] || minn <= b[i].c)
            continue;
        rp rt = ldis(b[i].x, b[i].y);
        ll tans = sum - rt.d + b[i].z - S / b[i].c;
        if (tans < ans) {
            q[0] = rt.x;
            q[1] = i;
            ans = tans;
        }
    }
    printf("%lld\n", ans);
    if (!q[0]) {
        for (int i = 1; i <= m; i++) {
            if (used[i]) {
                ANS[++tot].x = b[i].id;
                if (i == idx)
                    ANS[tot].d = b[i].z - S / b[i].c;
                else
                    ANS[tot].d = b[i].z;
            }
        }
    } else {
        for (int i = 1; i <= m; i++) {
            if (used[i] && q[0] != i) {
                ANS[++tot].x = b[i].id;
                ANS[tot].d = b[i].z;
            } else if (q[1] == i) {
                ANS[++tot].x = b[i].id;
                ANS[tot].d = b[i].z - S / b[i].c;
            }
        }
    }
    sort(ANS + 1, ANS + tot + 1, cmp2);
    for (int i = 1; i <= tot; i++) {
        printf("%lld %lld\n", ANS[i].x, ANS[i].d);
    }
    return 0;
}