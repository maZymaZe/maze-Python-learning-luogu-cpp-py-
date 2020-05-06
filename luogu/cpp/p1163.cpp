#include <cstdio>
int l = 0, r = 10000000, mid, tot, rt, m;
double t;
int ok(int x) {
    t = tot;
    for (int i = 1; i <= m; i++) {
        t *= (1.0 * x / 10000);
        t -= rt;
        if (t <= 0) return true;
    }
    return false;
}
int main() {
    scanf("%d%d%d%", &tot, &rt, &m);
    while (r - l >= 1) {
        mid = (l + r) / 2;
        if (ok(mid))
            l = mid;
        else
            r = mid;
        if (r - l == 1) break;
    }
    printf("%.1lf", 1.0 * (l-10000) / 100);
    return 0;
}