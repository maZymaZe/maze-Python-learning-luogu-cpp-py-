#include <cstdio>
inline int abs(int x) {
    return (x < 0) ? -x : x;
}
int n, a[205], tot = 0, lim, md = 0x3f3f3f3f, t1, a1, a2;
bool dp[202][5002] = {0};
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), tot += a[i];
    dp[0][0] = 1;
    lim = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = (tot + 1) / 2; j >= a[i]; j--) {
            for (int k = 1; k <= i && k <= lim; k++) {
                dp[k][j] = dp[k][j] | dp[k - 1][j - a[i]];
            }
        }
    }
    for (int i = (tot + 1) / 2; i >= 0; i--)
        if (dp[n / 2][i]) {
            printf("%d %d", i, tot - i);
            break;
        }
    return 0;
}