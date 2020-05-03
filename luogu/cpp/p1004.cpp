#include <cstdio>
int max(int a, int b) {
    if (a > b) return a;
    return b;
}
int n, a, b, c, mp[11][11], dp[11][11][11][11];
int main() {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    while (!(a == 0 && b == 0 && c == 0)) {
        mp[a][b] = c;
        scanf("%d%d%d", &a, &b, &c);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                      dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),
                      max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+mp[i][j]+mp[k][l];
                        if(i==k&&l==j)dp[i][j][k][l]-=mp[i][j];
                   
                }
            }
        }
    }
    printf("%d", dp[n][n][n][n]);
    return 0;
}