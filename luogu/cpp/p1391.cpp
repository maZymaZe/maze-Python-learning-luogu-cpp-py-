#include <cstdio>
int origin[19][19], tr[19][19], ans = 4000, tot1 = 0, n, f = 0, t[18], tp = 0,
                                toto;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool work() {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (origin[i][j]) {
                tr[i][j] = 1;
            } else {
                int t = 0;
                for (int k = 0; k < 3; k++) {
                    int nx = i - 1 + dx[k], ny = j + dy[k];
                    if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                        t ^= tr[nx][ny];
                    }
                }
                if (t)
                    toto++;
                tr[i][j] = t;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx > 0 && nx <= n && ny > 0 && ny <= n) {
                    t ^= tr[nx][ny];
                }
            }
            if (t)
                return false;
        }
    }
    return true;
}
void dfs(int x) {
    if (x > tp) {
        toto = 0;
        if (work()) {
            f = 1;
            if (toto + tot1 < ans)
                ans = toto + tot1;
        }
        return;
    }
    dfs(x + 1);
    tr[1][t[x]] = 1;
    tot1++;
    dfs(x + 1);
    tr[1][t[x]] = 0;
    tot1--;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &origin[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (origin[1][i] == 0)
            t[++tp] = i;
        tr[1][i] = origin[1][i];
    }
    dfs(1);
    if (f)
        printf("%d", ans);
    else
        printf("-1");
    return 0;
}