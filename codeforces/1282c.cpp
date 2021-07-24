#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 2e5 + 10;
struct QUE {
    int typ, t;
    bool operator<(const QUE& x) const { return t < x.t; }
} q[NMAX];
int n, m, T, a[2], ans, c[2], tot, u[2];
int cal(int lim) {
    if (lim <= 0)
        return 0;
    int ret = 0;
    int lt = lim - tot;
    int lc[2] = {c[0] - u[0], c[1] - u[1]};
    if (lt / a[0] <= lc[0])
        ret += lt / a[0], lt -= lt / a[0] * a[0];
    else
        lt -= a[0] * lc[0], ret += lc[0];
    if (lt / a[1] <= lc[1])
        ret += lt / a[1], lt -= lt / a[1] * a[1];
    else
        lt -= a[1] * lc[1], ret += lc[1];
    return ret + u[0] + u[1];
}
int main() {
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d%d", &n, &T, &a[0], &a[1]);
        c[0] = c[1] = 0;
        u[0] = u[1] = 0;
        tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &q[i].typ);
            c[q[i].typ]++;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &q[i].t);
        }
        sort(q + 1, q + 1 + n);
        int p = 1, lim = q[1].t - 1;
        ans = 0;
        ans = max(ans, cal(lim));
        int flag = 0;
        while (p <= n) {
            int ct = q[p].t;
            int pp = p;
            while (pp <= n && q[pp].t == ct) {
                pp++;
            }
            for (int i = p; i < pp; i++) {
                u[q[i].typ]++;
                tot += a[q[i].typ];
                if (tot > T) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
            lim = T;
            if (tot > T)
                break;
            if (pp <= n) {
                if (tot >= q[pp].t) {
                    p = pp;
                    continue;
                }
                lim = min(lim, q[pp].t - 1);
            }
            ans = max(ans, cal(lim));
            p = pp;
        }
        printf("%d\n", ans);
    }
    return 0;
}