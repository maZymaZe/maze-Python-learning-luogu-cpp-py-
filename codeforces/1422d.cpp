#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int NMAX = 2e5 + 10;
int n, m, d[NMAX], v[NMAX];
int sx, sy, ex, ey;
struct NODE {
    int x, y, op;
} a[NMAX];
bool cmp1(const NODE& a, const NODE& b) {
    return a.x < b.x;
}
bool cmp2(const NODE& a, const NODE& b) {
    return a.y < b.y;
}
int h[NMAX], tot;
struct EDGE {
    int to, nxt, val;
} e[NMAX << 2];
void add(int a, int b, int c) {
    e[++tot].nxt = h[a], h[a] = tot, e[tot].to = b, e[tot].val = c;
}
priority_queue<pair<int, int>> q;
void dij() {
    memset(d, 0x7f, sizeof(d));
    d[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        v[x] = 1;
        for (int i = h[x]; i; i = e[i].nxt) {
            if (d[e[i].to] > d[x] + e[i].val) {
                d[e[i].to] = d[x] + e[i].val;
                q.push({-d[e[i].to], e[i].to});
            }
        }
        while (!q.empty() && v[q.top().second])
            q.pop();
    }
    printf("%d\n", d[m + 1]);
}
int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].op = i;
    }
    for (int i = 1; i <= m; i++) {
        add(0, i, min(abs(sx - a[i].x), abs(sy - a[i].y)));
        add(i, m + 1, abs(ex - a[i].x) + abs(ey - a[i].y));
    }
    add(0, m + 1, abs(sx - ex) + abs(ey - sy));
    sort(a + 1, a + m + 1, cmp1);
    for (int i = 1; i < m; i++) {
        add(a[i].op, a[i + 1].op, a[i + 1].x - a[i].x);
        add(a[i + 1].op, a[i].op, a[i + 1].x - a[i].x);
    }
    sort(a + 1, a + m + 1, cmp2);
    for (int i = 1; i < m; i++) {
        add(a[i].op, a[i + 1].op, a[i + 1].y - a[i].y);
        add(a[i + 1].op, a[i].op, a[i + 1].y - a[i].y);
    }
    dij();
    return 0;
}