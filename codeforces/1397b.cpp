#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll NMAX = 1e5 + 10;
ll n, a[NMAX], k = 1, ans = 1ll << 62;
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; k <= (1ll << 50); i++) {
        k = 1;
        ll tot = 0;
        for (int j = 0; j < n; j++) {
            tot += abs(k - a[j]);
            if (k > (1ll << 50))
                break;
            k *= i;
        }
        ans = min(ans, tot);
    }
    printf("%lld\n", ans);
}