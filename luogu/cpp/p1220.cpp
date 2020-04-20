#include <algorithm>
#include <cstdio>
using namespace std;
int n, w, pos[60], v[60], dp[60][60][2], sum[60], tot = 0;
int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &pos[i], &v[i]);
        tot += v[i];
        sum[i] = tot;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j][1] = dp[i][j][0] = 99999999;
        }
    }
    dp[w][w][0] = dp[w][w][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, w - i + 1); j <= w; j++) {
            dp[j][j + i - 1][0] = min(
                dp[j + 1][j + i - 1][0] +
                    (sum[n] - sum[j + i - 1] + sum[j]) * (pos[j + 1] - pos[j]),
                dp[j + 1][j + i - 1][1] + (sum[n] - sum[j + i - 1] + sum[j]) *
                                              (pos[j + i - 1] - pos[j]));
            dp[j][j + i - 1][1] = min(
                dp[j][j + i - 2][0] + (sum[n] - sum[j + i - 2] + sum[j - 1]) *
                                          (pos[j + i - 1] - pos[j]),
                dp[j][j + i - 2][1] + (sum[n] - sum[j + i - 2] + sum[j - 1]) *
                                          (pos[j + i - 1] - pos[j + i - 2]));
        }
    }
    printf("%d", min(dp[1][n][0], dp[1][n][1]));
    return 0;
}