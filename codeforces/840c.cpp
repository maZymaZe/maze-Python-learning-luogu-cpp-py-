#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 302, MOD = 1e9 + 7;
int n, a[NMAX], sme;
long long dp[2][NMAX][NMAX];
void div(int& x) {
    for (int i = 2; i * i <= x; i++) {
        while (!(x % (i * i)))
            x /= (i * i);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        div(a[i]);
    }
    sort(a + 1, a + 1 + n);
    dp[0][0][0] = 1;
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            for (int j = 0; j <= i; j++) {
                for (int k = 1; k <= sme; k++) {
                    (dp[now ^ 1][j][0] += (dp[now ^ 1][j][k] % MOD)) %= MOD;
                    dp[now ^ 1][j][k] = 0;
                }
            }
            sme = 0;
        }
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= min(j, sme); ++k) {
                if (j && k) {
                    (dp[now][j][k] += (dp[now ^ 1][j - 1][k - 1] *
                                       (2 * sme - k + 1) % MOD)) %= MOD;
                }
                (dp[now][j][k] += (dp[now^1][j + 1][k] * (j + 1 - k) % MOD)) %=
                    MOD;
                (dp[now][j][k] += (dp[now ^ 1][j][k] *
                                   (i - (2 * sme - k) - (j - k)) % MOD)) %= MOD;
            }
        }
        now ^= 1;
        sme++;
        memset(dp[now], 0, sizeof(dp[now]));
    }
    printf("%lld\n", dp[now ^ 1][0][0]);
    return 0;
}