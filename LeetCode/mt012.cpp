#include <cstdio>
const int NMAX = 1e4 + 10, QMAX = 1e5 + 10;
int lck[NMAX], bp[NMAX];
int n, m, q, op, x, y;
int main() {
    scanf("%d%d%d", &m, &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &x, &y);
            if (bp[x] >= 0 && bp[x] <= n && !lck[bp[x]] && !lck[y]) {
                bp[x] = y;
            }
        } else if (op == 2) {
            scanf("%d", &x);
            lck[x] = 1;
        } else if (op == 3) {
            scanf("%d", &x);
            lck[x] = 0;
        } else if (op == 4) {
            scanf("%d", &x);
            if (bp[x] > 0 && bp[x] <= n && !lck[bp[x]]) {
                printf("%d\n", bp[x]);
                bp[x] = n + 1;
            } else
                printf("-1\n");
        } else if (op == 5) {
            scanf("%d", &x);
            if (bp[x] == n + 1)
                bp[x] = 0;
        }
    }
    return 0;
}