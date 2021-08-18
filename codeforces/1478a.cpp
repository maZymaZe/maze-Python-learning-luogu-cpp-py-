#include <cstdio>
int T, n, pre, mx, x, c;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        c = 0, pre = -1, mx = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (x == pre)
                c++;
            else
                c = 1, pre = x;
            if (c > mx)
                mx = c;
        }
        printf("%d\n", mx);
    }
    return 0;
}