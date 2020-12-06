#include <cmath>
#include <cstdio>
const long long NMAX = 1e5 + 10;
long long n, g[NMAX], m, p1, c1, c2;
long long mabs(long long x)
{
    return x>0?x:-x;
}

int main() {
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &g[i]);
    }
    scanf("%lld%lld%lld%lld", &m, &p1, &c1, &c2);
    g[p1] += c1;
    long long suml = 0, sumh = 0;
    for (long long i = 1; i < m; i++) {
        suml += g[i] * (m - i);
    }
    for (long long i = m + 1; i <= n; i++) {
        sumh += g[i] * (i - m);
    }
    long long p2 = m;
    long long ans = mabs(suml - sumh);
    for (long long i = 1; i <= n; i++) {
        long long L = suml, R = sumh;
        if (i < m) {
            L += (m - i) * c2;
            if (mabs(L - R) < ans || (mabs(L - R) == ans && i < p2)) {
                ans = mabs(L - R);
                p2 = i;
            }
        }
        if (i > m) {
            R += (i - m) * c2;
            if (mabs(L - R) < ans || (mabs(L - R) == ans && i < p2)) {
                ans = mabs(L - R);
                p2 = i;
            }
        }
    }
    printf("%lld", p2);
    return 0;
}