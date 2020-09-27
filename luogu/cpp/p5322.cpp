#include <algorithm>
#include <cstdio>
using namespace std;
int n, s, m, a[110][110], dp[20002], ans = 0;
int main() {
    scanf("%d%d%d", &s, &n, &m);
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[j][i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + 1 + s);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s; k++) {
                if (j > 2 * a[i][k]) {
                    dp[j] = max(dp[j], dp[j - 2 * a[i][k] - 1] + k * i);
                }
            }
        }
    }
    for (int i = 0; i <= m; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}