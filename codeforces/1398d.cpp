#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 202;
int r[NMAX], g[NMAX], b[NMAX], dp[NMAX][NMAX][NMAX], x, y, z, ans = 0;
int main() {
    scanf("%d%d%d", &x, &y, &z);
    for (int i = 1; i <= x; i++) {
        scanf("%d", &r[i]);
    }
    for (int i = 1; i <= y; i++) {
        scanf("%d", &g[i]);
    }
    for (int i = 1; i <= z; i++) {
        scanf("%d", &b[i]);
    }
    sort(r + 1, r + 1 + x);
    sort(g + 1, g + 1 + y);
    sort(b + 1, b + 1 + z);
    for (int i = x; i >= 0; i--) {
        for (int j = y; j >= 0; j--) {
            for (int k = z; k >= 0; k--) {
                if (i < x && j < y) {
                    dp[i][j][k] = max(
                        dp[i][j][k], dp[i + 1][j + 1][k] + r[i + 1] * g[j + 1]);
                }
                if (i < x && k < z) {
                    dp[i][j][k] = max(
                        dp[i][j][k], dp[i + 1][j][k + 1] + r[i + 1] * b[k + 1]);
                }
                if (j < y && k < z) {
                    dp[i][j][k] = max(
                        dp[i][j][k], dp[i][j + 1][k + 1] + g[j + 1] * b[k + 1]);
                }
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}