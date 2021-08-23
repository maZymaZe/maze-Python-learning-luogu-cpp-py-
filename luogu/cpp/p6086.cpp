#include <cstdio>
const int NMAX = 5e6 + 10;
int n, op, f[NMAX], p[NMAX], d[NMAX];
long long ans = 0;
void FatherToPrufer() {
    for (int i = 1; i < n; i++)
        ++d[f[i]];
    for (int i = 1, j = 1; i < n - 1; i++, j++) {
        while (d[j])
            ++j;
        p[i] = f[j];
        while (i <= n - 2 && ((--d[p[i]]) == 0) && p[i] < j)
            p[i + 1] = f[p[i]], i++;
    }
}
void PruferToFather() {
    for (int i = 1; i < n - 1; i++) {
        ++d[p[i]];
    }
    p[n - 1] = n;
    for (int i = 1, j = 1; i < n; i++, j++) {
        while (d[j])
            ++j;
        f[j] = p[i];
        while (i < n && ((--d[p[i]]) == 0) && p[i] < j)
            f[p[i]] = p[i + 1], ++i;
    }
}
int main() {
    scanf("%d%d", &n, &op);
    if (op == 1) {
        for (int i = 1; i < n; i++) {
            scanf("%d", &f[i]);
        }
        FatherToPrufer();
        for (int i = 1; i < n - 1; i++) {
            ans ^= 1ll * p[i] * i;
        }
    } else if (op == 2) {
        for (int i = 1; i < n - 1; i++) {
            scanf("%d", &p[i]);
        }
        PruferToFather();
        for (int i = 1; i < n; i++) {
            ans ^= 1ll * f[i] * i;
        }
    }
    printf("%lld\n", ans);
    return 0;
}