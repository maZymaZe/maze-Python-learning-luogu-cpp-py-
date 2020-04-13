#include <cstdio>
#include <cstring>
int s[100008], il[100008], ol[100008], n, t, ps, po, pi, f;
int main() {
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &il[j]);
        }
        for (int j = 1; j <= n; j++) {
            scanf("%d", &ol[j]);
        }
        f = 1;
        ps = 0, po = 1;
        pi = 1;
        while (po != n + 1) {
            if (ps > 0 && s[ps] == ol[po]) {
                s[ps] = 0;
                ps--;
                po++;
            } else {
                while (pi <= n && il[pi] != ol[po]) {
                    ps++;
                    s[ps] = il[pi];
                    pi++;
                }
                if (pi == n + 1) {
                    printf("No\n");
                    f = 0;
                    break;
                } else {
                    pi++;
                    po++;
                }
            }
        }
        if(f== 1)printf("Yes\n");
    }
    return 0;
}