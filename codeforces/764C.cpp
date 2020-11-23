#include <cstdio>
const int NMAX = 1e5+10;
int cnt[NMAX], c[NMAX], t1 = 0, ans = 0, ep = 0, n, l[NMAX], r[NMAX], ct = 0,
                        ma = -1, pos = 0, in[NMAX];
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i < n; i++) {
        if (c[l[i]] != c[r[i]]) {
            cnt[l[i]]++, cnt[r[i]]++;
            t1 = l[i];
            ct++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > ma) {
            ma = cnt[i], pos = i;
        }
    }
    if (ma == ct) {
        printf("YES\n%d\n", pos);
    } else if (ct == 0)
        printf("YES\n%d\n", 1);
    else
        printf("NO\n");
    return 0;
}
