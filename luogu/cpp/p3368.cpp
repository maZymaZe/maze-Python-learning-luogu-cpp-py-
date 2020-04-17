#include <cstdio>
long long a[500004], c[500004],b[500004];
int op, l, r, n, m, t;
int lowbit(int x) { return x & (-x); }
void update(int x, int v) {
    a[x] += v;
    while (x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
}
long long finds(int x) {
    if (x == 0)
        return 0;
    else {
        long long ans = 0;
        while (x > 0) {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
        update(i, b[i] - b[i - 1]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &t);
            update(l, t);
            update(r + 1, -t);
        } else {
            scanf("%d", &t);
            printf("%lld\n", finds(t));
        }
    }
    return 0;
}