#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int NMAX = 2e5 + 10;
ll T, n, k, a[NMAX];
int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        ll gcd;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            if (i == 2)
                gcd = abs(a[2] - a[1]);
            else if (i > 2)
                gcd = __gcd(gcd, abs(a[i] - a[1]));
        }
        if ((k - a[1]) % gcd == 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}