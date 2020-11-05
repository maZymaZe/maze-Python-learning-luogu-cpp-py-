#include <cstdio>
const int NMAX = 2e5 + 10;
int m, n, f[NMAX], b, l, r;
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        f[i] = i;
    b = n;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        r = ff(r);
        while (l <= r) {
            if(l!=r&&ff(l)==r)break;
            f[r] = ff(f[r-1]);
            r = ff(r);
            --b;
        }
        printf("%d\n", b);
    }
    return 0;
}