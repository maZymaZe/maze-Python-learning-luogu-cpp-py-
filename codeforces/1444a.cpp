#include <cmath>
#include <cstdio>
int main() {
    long long T, a, b;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &a, &b);
        if (a % b != 0) {
            printf("%lld\n", a);
        } else {
            long long s = sqrt(b) + 1, t = a, aa = a;
            for (int i = 2; i <= s; i++) {
                if (b % i == 0) {
                    long long c1 = 1, c2 = 1;
                    while (b % i == 0) {
                        b /= i;
                        c1 *= i;
                    }
                    while (a % i == 0) {
                        a /= i;
                        c2 *= i;
                    }
                    long long md = c2 / c1 * i;
                    if (md < t)
                        t = md;
                }
            }
            if (b != 1) {
                long long c1 = 1, c2 = 1;

                while (a % b == 0) {
                    a /= b;
                    c2 *= b;
                }
                long long md = c2;
                if (md < t)
                    t = md;
            }
            printf("%lld\n", aa / t);
        }
    }
    return 0;
}