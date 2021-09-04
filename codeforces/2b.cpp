#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1002;
int dp2[NMAX][NMAX], dp5[NMAX][NMAX], flag, fx, fy, n, mp[NMAX][NMAX];
int d2[NMAX][NMAX], d5[NMAX][NMAX];
int op[NMAX * 3], p = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 0)
                flag = 1, fx = i, fy = j;

            int c2 = 0, c5 = 0;
            while (mp[i][j] % 5 == 0 && mp[i][j] != 0)
                c5++, mp[i][j] /= 5;
            while (mp[i][j] % 2 == 0 && mp[i][j] != 0)
                c2++, mp[i][j] /= 2;
            if (i == 1 && j == 1) {
                dp2[i][j] = c2;
                d2[i][j] = 0;

                dp5[i][j] = c5;
                d5[i][j] = 0;
            } else if (i == 1) {
                dp2[i][j] = dp2[i][j - 1] + c2;
                d2[i][j] = 4;
                dp5[i][j] = dp5[i][j - 1] + c5;
                d5[i][j] = 4;
            } else if (j == 1) {
                dp2[i][j] = dp2[i - 1][j] + c2;
                d2[i][j] = 3;
                dp5[i][j] = dp5[i - 1][j] + c5;
                d5[i][j] = 3;
            } else {
                if (dp2[i - 1][j] > dp2[i][j - 1]) {
                    dp2[i][j] = dp2[i][j - 1] + c2;
                    d2[i][j] = 4;
                } else {
                    dp2[i][j] = dp2[i - 1][j] + c2;
                    d2[i][j] = 3;
                }
                if (dp5[i - 1][j] > dp5[i][j - 1]) {
                    dp5[i][j] = dp5[i][j - 1] + c5;
                    d5[i][j] = 4;
                } else {
                    dp5[i][j] = dp5[i - 1][j] + c5;
                    d5[i][j] = 3;
                }
            }
        }
    }
    if (flag && min(dp2[n][n], dp5[n][n]) > 0) {
        printf("1\n");
        for (int i = 1; i < fx; i++)
            printf("D");
        for (int i = 1; i < n; i++)
            printf("R");
        for (int i = fx; i < n; i++)
            printf("D");
        printf("\n");
        return 0;
    }
    printf("%d\n", min(dp2[n][n], dp5[n][n]));
    if (dp2[n][n] < dp5[n][n]) {
        int tx = n, ty = n;
        while (d2[tx][ty] != 0) {
            if (d2[tx][ty] == 3)
                op[++p] = 'D', tx--;
            else if (d2[tx][ty] == 4)
                op[++p] = 'R', ty--;
        }
    } else {
        int tx = n, ty = n;
        // dwqs
        while (d5[tx][ty] != 0) {
            if (d5[tx][ty] == 3)
                op[++p] = 'D', tx--;
            else if (d5[tx][ty] == 4)
                op[++p] = 'R', ty--;
        }
    }
    for (int i = p; i > 0; i--)
        printf("%c", op[i]);

    printf("\n");
    return 0;
}