#include <cstdio>
#include <cstring>
int n, a[20030], b[20030], m, op, tx, ty, k;
int main() {
    scanf("%d", &n);
    memset(b, -1, sizeof(b));
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &op);
        if (op == 2) {
            scanf("%d", &tx);
            printf("%d\n", b[tx]);
        } else {
            scanf("%d%d%d", &k, &tx, &ty);
            for (int i = 0; i < k; i++) {
                if (ty + i > n)
                    break;
                if (tx + i > n)
                    break;
                b[ty + i] = a[tx + i];
            }
        }
    }
    return 0;
}