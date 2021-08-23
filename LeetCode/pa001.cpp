#include <cstdio>
int n, q;
int mp[201][201], dp[201][201];
int x1, yy1, x2, y2;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int main() {
    int mx = 0, my = 0;
    scanf("%d%d", &n, &q);
    mp[100][100] = n;
    int flag = 1, updt;
    while (flag) {
        flag = 0;
        for (int i = 1; i < 200; i++) {
            for (int j = 1; j < 200; j++) {
                if (mp[i][j] > 7) {
                    flag = 1;
                    int del = mp[i][j] / 8;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k], ny = j + dy[k];
                        mp[nx][ny] += del;
                    }
                    mp[i][j] %= 8;
                }
            }
        }
    }
    for (int i = 1; i <= 200; i++) {
        for (int j = 0; j < 200; j++) {
            dp[i][j] =
                mp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d%d", &x1, &yy1, &x2, &y2);
        if (x1 > 98)
            x1 = 98;
        else if (x1 < -98)
            x1 = -98;
        if (x2 > 98)
            x2 = 98;
        else if (x2 < -98)
            x2 = -98;
        if (yy1 > 98)
            yy1 = 98;
        else if (yy1 < -98)
            yy1 = -98;
        if (y2 > 98)
            y2 = 98;
        else if (y2 < -98)
            y2 = -98;
        if (x1 > x2 || yy1 > y2) {
            printf("0\n");
        } else {
            printf("%d\n", dp[x2 + 100][y2 + 100] -
                               dp[x2 + 100][yy1 - 1 + 100] -
                               dp[x1 - 1 + 100][y2 + 100] +
                               dp[x1 - 1 + 100][yy1 - 1 + 100]);
        }
    }
    return 0;
}