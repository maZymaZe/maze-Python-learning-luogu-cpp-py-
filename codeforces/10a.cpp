#include <cstdio>
int u[2000], n, p1, p2, p3, t1, t2, l, r, ll, rr;
int main() {
    scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
    t2 += t1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        r--;
        for (int j = l; j <= r; j++)
            u[j] = 1;
        if (i == 0)
            ll = l;
        if (i == n - 1)
            rr = r;
    }
    int ot = 0, ans = 0;
    for (int i = ll; i <= rr; i++) {
        if (u[i])
            ot = 0, ans += p1;
        else {
            ot++;
            if (ot > t2)
                ans += p3;
            else if (ot > t1)
                ans += p2;
            else
                ans += p1;
        }
    }
    printf("%d\n", ans);
    return 0;
}