#include <cstdio>
const int NMAX = 40;
int a[NMAX], b[NMAX], mi = 0, mx = 0, st, n;
int main() {
    scanf("%d%d", &n, &st);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        mi += a[i], mx += b[i];
    }
    if (st < mi || st > mx) {
        printf("NO\n");
        return 0;
    }
    int p = 1;
    while (mi < st) {
        if (mi + (b[p] - a[p]) >= st) {
            a[p] += st - mi;
            mi = st;
        } else {
            mi += (b[p] - a[p]);
            a[p] = b[p];
        }
        p++;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}