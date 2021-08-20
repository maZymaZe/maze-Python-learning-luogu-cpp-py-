#include <cstdio>
const int NMAX = 1e5 + 10;
int T, n, p, k, a[NMAX], x, y, u[NMAX];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &p, &k);
        for (int i = 1; i <= n; i++)
            scanf("%1d", &a[i]), u[i] = 0;
        scanf("%d%d", &x, &y);
        int ans = 0x3f3f3f3f;
        for (int i = n; i >= 1; i--) {
            if (i + k > n)
                u[i] = (a[i] == 0);
            else
                u[i] = (a[i] == 0) + u[i + k];
        }
        for (int i = p, c = 0; i <= n; i++, c += y) {
            if (c + u[i] * x < ans)
                ans = c + u[i] * x;
        }
        printf("%d\n", ans);
    }
    return 0;
}