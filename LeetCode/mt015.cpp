#include <cstdio>
#include <queue>
using namespace std;
const int NMAX = 103;
int a[NMAX][NMAX], b[NMAX][NMAX], f[NMAX][NMAX];
int n, m, xs, ys, xt, yt;
queue<int> qx, qy;
int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &xs, &ys, &xt, &yt);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    qx.push(xs), qy.push(ys);
    f[xs][ys] = 1;
    int k = 0;
    while (!qx.empty()) {
        int l = qx.size();
        int bk = 0;
        for (int i = 0; i < l; i++) {
            int x = qx.front(), y = qy.front();
            qx.pop(), qy.pop();
            if (x == xt && y == yt) {
                bk = 1;
                break;
            }
            if (0 <= k % (a[x][y] + b[x][y]) &&
                a[x][y] > k % (a[x][y] + b[x][y])) {
                if (x + 1 <= n && !f[x + 1][y]) {
                    qx.push(x + 1), qy.push(y);
                    f[x + 1][y] = 1;
                }
                if (x - 1 > 0 && !f[x - 1][y]) {
                    qx.push(x - 1), qy.push(y);
                    f[x - 1][y] = 1;
                }
            } else if (a[x][y] <= k % (a[x][y] + b[x][y]) &&
                       (a[x][y] + b[x][y]) > k % (a[x][y] + b[x][y])) {
                if (y + 1 <= m && !f[x][y + 1]) {
                    qx.push(x), qy.push(y + 1);
                    f[x][y + 1] = 1;
                }
                if (y - 1 > 0 && !f[x][y - 1]) {
                    qx.push(x), qy.push(y - 1);
                    f[x][y - 1] = 1;
                }
            }
            qx.push(x), qy.push(y);
        }
        if (bk) {
            break;
        }
        k++;
    }
    printf("%d\n", k);
    return 0;
}