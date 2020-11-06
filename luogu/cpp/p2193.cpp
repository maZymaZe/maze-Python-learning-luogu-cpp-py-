#include <cstdio>
const int MOD = 1e9 + 7;
int n, q, dp[2004][2004];
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= q; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k += j) {
                dp[i][k] = (dp[i - 1][j] + dp[i][k]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[q][i]) % MOD;
    }
    printf("%d", ans);
    return 0;
}