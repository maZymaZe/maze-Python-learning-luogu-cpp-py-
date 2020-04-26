#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, ans = 0, f[40005], aa, bb;
int ff(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = ff(f[x]);
}
struct gp {
    int w, u, v;
    bool operator<(const gp& x) { return this->w > x.w; }
} g[100005];
int main() {
    int a, b, c;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) f[i] = i, f[i + n] = n + i;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        g[i].u = a;
        g[i].v = b;
        g[i].w = c;
    }
    sort(g + 1, g + 1 + m);

    for (int i = 1; i <= m; i++) {
        aa = g[i].u;
        bb = g[i].v;
        if (ff(aa) == ff(bb) || ff(aa + n) == ff(bb + n)) {
            ans = g[i].w;
            break;
        }
        f[f[aa + n]] = f[bb];
        f[f[aa]] = f[bb+ n];
    }
    printf("%d\n", ans);
    return 0;
}