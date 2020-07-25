#include <cstdio>
#include <cstring>
int min(int a, int b) {
    return a < b ? a : b;
}
int n, m, dp[2000000], s[100010][25], num[25], x;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j];
        }
        s[i][x]++, num[x]++;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << m); i++) {
        int len = 0;
        for (int j = 1; j <= m; j++) {
            if (i & (1 << (j - 1)))
                len += num[j];
        }
        for (int j = 1; j <= m; j++) {
            if (i & (1 << (j - 1))) {
                dp[i] = min(dp[i], dp[i ^ (1 << (j - 1))] + num[j] - s[len][j] +
                                     s[len - num[j]][j]);
            }
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}