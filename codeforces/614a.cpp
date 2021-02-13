#include <cstdio>
long long l, r, k, m, f = 0;
int main() {
    scanf("%lld%lld%lld", &l, &r, &k);
    m = 1;
    long long lim = (1e18 + 1e10) / k;
    lim+=10;
    while (m < 1e18 + 1e10 && m > 0) {
        if (m >= l && m <= r)
            printf("%lld ", m), f = 1;
        if (m > lim)
            break;
        m *= k;
    }
    if (!f)
        printf("-1\n");
    return 0;
}