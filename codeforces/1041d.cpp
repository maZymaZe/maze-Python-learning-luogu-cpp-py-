#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int NMAX = 2e5 + 10;
struct PR {
    ll l, r;
    bool operator<(const PR& x) const { return l < x.l; }
} a[NMAX];
ll n, h, ans = -1;
vector<ll> ps;
int main() {
    scanf("%lld%lld", &n, &h);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].l, &a[i].r);
    }
    sort(a + 1, a + 1 + n);
    ps.push_back(0);
    for (int i = 1; i < n; i++) {
        ps.push_back(ps.back() + a[i + 1].l - a[i].r);
    }
    ps.push_back(ps.back() + h + 10);
    for (int i = 1; i <= n; i++) {
        ll bg = a[i].l;
        ll pos = lower_bound(ps.begin(), ps.end(), ps[i - 1] + h) - ps.begin();
        ll ed = a[pos].r + (h - (ps[pos - 1] - ps[i - 1]));
        ans = max(ans, ed - bg);
    }
    printf("%lld\n", ans);
    return 0;
}