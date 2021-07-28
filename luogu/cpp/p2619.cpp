#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll NMAX = 5e4 + 10, EMAX = 1e5 + 10;
struct EDGE {
    ll x, y, w, c;
    bool operator<(const EDGE& x) const {
        if (w == x.w)
            return c < x.c;
        return w < x.w;
    }
} e[EMAX + 1];
int n, m, need;
int f[NMAX];
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
ll sum, ans, tmp, cnt = 0;
void fmst() {
    sort(e + 1, e + 1 + m);
    int c = 0;
    for (int i = 1; i <= m; i++) {
        if (ff(e[i].x) != ff(e[i].y)) {
            f[ff(e[i].x)] = ff(e[i].y);
            c++;
            if (e[i].c == 0)
                tmp++;
            sum += e[i].w;
        }
        if (c == n - 1)
            break;
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &need);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld%lld", &e[i].x, &e[i].y, &e[i].w, &e[i].c);
        e[i].x++, e[i].y++;
    }
    int l = -102, r = 102;
    while (l <= r) {
        int mid = (l + r) / 2;
        for (int i = 1; i <= m; i++) {
            if (e[i].c == 0)
                e[i].w += mid;
        }
        for (int i = 1; i <= n; i++)
            f[i] = i;
        sum = cnt = tmp = 0;
        fmst();
        if (tmp >= need) {
            l = mid + 1;
            ans = sum - need * mid;
        } else {
            r = mid - 1;
        }
        for (int i = 1; i <= m; i++) {
            if (e[i].c == 0)
                e[i].w -= mid;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
