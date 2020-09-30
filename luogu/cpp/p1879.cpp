#include <cstdio>
const int CSIZE = 5002, MPSIZE = 13, MOD = 1e8;
int dp[MPSIZE][CSIZE], n, m, mp[MPSIZE][MPSIZE] = {0}, F[13], c, state[CSIZE];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &mp[i][j]);
            F[i] = (F[i] << 1) + (mp[i][j]);
        }
    c = (1 << m) - 1;
    dp[0][0] = 1;
    for (int i = 0; i <= c; i++) {
        state[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= c; j++) {
            if (state[j] && ((j & F[i]) == j)) {
                for (int k = 0; k <= c; k++) {
                    if ((k & j) == 0) {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][k]) % MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= c; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}