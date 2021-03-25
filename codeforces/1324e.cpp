#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, dp[2][2003], l, r, h, t;
int main() {
    scanf("%d%d%d%d", &n, &h, &l, &r);
    for (int i = 0; i <= h; i++)
        dp[0][i] = dp[1][i] = -0x3f3f3f3f;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        for (int j = 0; j < h; j++) {
            dp[i & 1][j] = max(dp[!(i & 1)][(j - t + h + h) % h],
                               dp[!(i & 1)][(j - t + h + h + 1) % h]) +
                           (j >= l && j <= r);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
        ans = max(ans, dp[n & 1][i]);
    printf("%d\n", ans);
    return 0;
}