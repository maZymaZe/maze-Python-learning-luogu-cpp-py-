#include <cstdio>
#include <cstring>
int max(int a, int b) {
    return a > b ? a : b;
}
int s, d, m, maxx, sd[55][12] = {0}, dp[500005] = {0};
int main() {
    scanf("%d%d%d", &s, &d, &m);
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= d; j++) {
            scanf("%d", &sd[i][j]);
        }
    }
    for (int i = 2; i <= d; i++) {
        maxx = 0;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= s; j++) {
            for (int k = sd[j][i - 1]; k <= m; k++) {
                dp[k] =
                    max(dp[k], dp[k - sd[j][i - 1]] + sd[j][i] - sd[j][i - 1]);
                maxx = max(maxx, dp[k]);
            }
        }
        m += maxx;
    }
    printf("%d\n", m);
    return 0;
}