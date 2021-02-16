#include <cstdio>
const int NMAX = 102;
int c[3];
double dp[3][NMAX][NMAX][NMAX];
int main() {
    scanf("%d%d%d", &c[0], &c[1], &c[2]);
    for (int i = 0; i <= c[0]; i++) {
        for (int j = 0; j <= c[1]; j++) {
            for (int k = 0; k <= c[2]; k++) {
                if (i == 0) {
                    if (j) {
                        dp[0][i][j][k] = 0;
                        dp[1][i][j][k] = 1;
                        dp[2][i][j][k] = 0;
                    } else if (k) {
                        dp[0][i][j][k] = 0;
                        dp[1][i][j][k] = 0;
                        dp[2][i][j][k] = 1;
                    } else {
                        dp[0][i][j][k] = dp[1][i][j][k] = dp[2][i][j][k] = 0;
                    }
                } else if (j == 0) {
                    if (k) {
                        dp[0][i][j][k] = 0;
                        dp[1][i][j][k] = 0;
                        dp[2][i][j][k] = 1;
                    } else {
                        dp[0][i][j][k] = 1;
                        dp[1][i][j][k] = 0;
                        dp[2][i][j][k] = 0;
                    }
                } else if (k == 0) {
                    dp[0][i][j][k] = 1;
                    dp[1][i][j][k] = 0;
                    dp[2][i][j][k] = 0;
                } else {
                    double tt = i * j + j * k + i * k;
                    for (int h = 0; h < 3; h++) {
                        dp[h][i][j][k] = dp[h][i][j - 1][k] * i * j / tt +
                                         dp[h][i][j][k - 1] * j * k / tt +
                                         dp[h][i - 1][j][k] * i * k / tt;
                    }
                }
            }
        }
    }
    printf("%.12lf %.12lf %.12lf\n", dp[0][c[0]][c[1]][c[2]],
           dp[1][c[0]][c[1]][c[2]], dp[2][c[0]][c[1]][c[2]]);
    return 0;
}