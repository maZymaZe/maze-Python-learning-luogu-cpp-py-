#include <algorithm>
#include <cstdio>
using namespace std;
int p, q, a[105], dp[105][105];
int main() {
    scanf("%d%d", &p, &q);
    for (int i = 1; i <= q; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + q);
    a[0] = 0, a[q + 1] = p + 1;
    for (int i = 1; i <= q; i++) {
        for (int j = 1; j + i - 1 <= q; j++) {
            int k = i + j - 1;
            dp[j][k] = 99999999;
            for (int h = j; h <= k; h++) {
                dp[j][k] = min(dp[j][k], dp[j][h - 1] + dp[h + 1][k] +
                                             (a[k + 1] - a[j - 1] - 1) - 1);
            }
        }
    }
    printf("%d", dp[1][q]);
    return 0;
}