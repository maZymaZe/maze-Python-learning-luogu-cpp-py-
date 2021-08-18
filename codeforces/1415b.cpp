#include <cstdio>
const int NMAX = 1e5 + 10;
int T, n, a[NMAX], k;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int use = n;
        for (int i = 1; i <= 100; i++) {
            int p = 1, c = 0;
            while (p <= n) {
                while (p <= n && a[p] == i)
                    p++;
                if (a[p] != i && p <= n)
                    p += k, c++;
            }
            if (c < use)
                use = c;
        }
        printf("%d\n", use);
    }
    return 0;
}