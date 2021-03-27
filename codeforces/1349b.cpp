#include <cstdio>
const int NMAX = 1e5 + 10;
int a[NMAX], n, T, k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        int f = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == k)
                f = 1;
        }
        if (!f) {
            printf("no\n");
            continue;
        }
        if (n == 1) {
            printf("yes\n");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (i + 1 <= n && a[i] >= k && a[i + 1] >= k) {
                printf("yes\n");
                f = 0;
                break;
            }
            if (i + 2 <= n && a[i] >= k && a[i + 2] >= k) {
                printf("yes\n");
                f = 0;
                break;
            }
        }
        if (f)
            printf("no\n");
    }
    return 0;
}