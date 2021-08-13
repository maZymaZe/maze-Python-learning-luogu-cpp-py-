#include <cstdio>
int T, n, m, x;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%d", &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            if (x >= 10 * m) {
                printf("YES\n");
            } else {
                int flag = 0;
                while (x >= 0) {
                    x -= m;
                    if (x % 10 == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) {
                    printf("YES\n");
                } else {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}