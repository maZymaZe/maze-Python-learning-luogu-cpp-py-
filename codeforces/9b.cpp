#include <cmath>
#include <cstdio>
int n, vb, vs, a[120], ans = -1;
double tm = 1e18, td = 1e18;
long long x, y;
int main() {
    scanf("%d", &n);
    scanf("%d%d", &vb, &vs);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%lld%lld", &x, &y);
    for (int i = 2; i <= n; i++) {
        double k = (double)a[i] / vb;
        double v = (double)sqrt((x - a[i]) * (x - a[i]) + y * y) / vs;
        if (k + v <= tm && v < td) {
            tm = k + v;
            td = v;
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}