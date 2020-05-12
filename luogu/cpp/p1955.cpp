#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int t, n, f[1000006], b[1000006 * 3];
struct node {
    int x, y, e;
    bool operator<(const node& x) { return e > x.e; }
} a[1000006];
int ff(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = ff(f[x]);
}
int main() {
    scanf("%d", &t);
    while (t--) {
        int flag = 1;
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].e);
            b[++tot] = a[i].x;
            b[++tot] = a[i].y;
        }
        sort(b + 1, b + tot + 1);
        int tott = unique(b + 1, b + tot + 1) - b;
        for (int i = 1; i <= n; i++) {
            a[i].x = lower_bound(b + 1, b + 1 + tott, a[i].x) - b;
            a[i].y = lower_bound(b + 1, b + tott + 1, a[i].y) - b;
        }
        for (int i = 1; i <= tott; i++) f[i] = i;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (a[i].e == 1) {
                int f1 = ff(a[i].x), f2 = ff(a[i].y);
                if (f1 != f2) {
                    f[f1] = f2;
                }
            } else {
                int f1 = ff(a[i].x), f2 = ff(a[i].y);
                if (f1 == f2) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}