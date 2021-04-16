#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll NMAX = 2077;
ll n, m, a[NMAX], b[NMAX], ca, cb, ans;
int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n);
    for (int i = 1; i < m; i++)
        scanf("%lld", &b[i]);
    sort(b + 1, b + m);
    int pa = n - 1, pb = m - 1;
    while (ca < n && cb < m) {
        if (a[pa] >= b[pb]) {
            ans += a[pa] * (cb + 1);
            ca++;
            pa--;
        } else {
            ans += b[pb] * (ca + 1);
            cb++;
            pb--;
        }
    }
    while (ca < n) {
        ans += a[pa] * (cb + 1);
        ca++;
        pa--;
    }
    while (cb < m) {
        ans += b[pb] * (ca + 1);
        cb++;
        pb--;
    }
    printf("%lld",ans);
    return 0;
}