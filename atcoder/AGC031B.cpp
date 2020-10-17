#include <cstdio>
const int MOD = 1e9 + 7;
const int NMAX = 2e5 + 7;
int n = 0, t = 0, preTot[NMAX] = {0}, dp[NMAX] = {0}, pre = 0;
int main() {
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (!preTot[t]) {
            dp[i] = dp[i - 1];
            preTot[t] = dp[i - 1];
            pre = t;
        } else {
            if (t == pre) {
                dp[i] = dp[i - 1];
                continue;
            }
            dp[i] = (preTot[t] + dp[i - 1]) % MOD;
            preTot[t] = (preTot[t] + dp[i - 1]) % MOD;
            pre = t;
        }
    }
    printf("%lld", dp[n]);
    return 0;
}