#include <cstdio>
const int NMAX = 1e5 + 10;
int n, a[NMAX], l = 0, r = 0, pl, pr, tl = 0, tr = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    pl = 1, pr = n;
    while (pl <= pr) {
        if (l <= r)
            l += a[pl++], tl++;
        else
            r += a[pr--], tr++;
    }
    printf("%d %d\n", tl, tr);
}