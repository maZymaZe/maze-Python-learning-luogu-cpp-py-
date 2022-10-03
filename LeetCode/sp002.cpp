#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10;
int n, k, t, c[NMAX], tot, u[NMAX];
int ta[2 * NMAX];
void add(int p) {
    while (p < 2 * NMAX) {
        ta[p]++;
        p += (-p & p);
    }
}
int cal(int p) {
    int r = 0;
    while (p) {
        r += ta[p];
        p -= (-p & p);
    }
    return r;
}
int main() {
    long long ans = 0;
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        t -= k;
        tot += t;
        c[i] = tot;
        u[i] = tot;
    }
    sort(u, u + 1 + n);
    for (int i = 0; i <= n; i++)
        c[i] = lower_bound(u, u + 1 + n, c[i]) - u + 1;
    for (int i = 0; i <= n; i++) {
        ans += cal(c[i]);
        add(c[i]);
    }
    printf("%lld\n", ans);
    return 0;
}