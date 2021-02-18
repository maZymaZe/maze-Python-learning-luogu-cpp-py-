#include <cstdio>
#include <queue>
using namespace std;
int n, m, cnt = 0;
const int NMAX = 2010, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char mp[NMAX][NMAX], ans[NMAX][NMAX];
int d[NMAX][NMAX];
struct pr {
    int x, y;
};
queue<pr> q;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mp[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '*')
                cnt++;
        }
    }
    if (cnt == n * m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("*");
            }
            printf("\n");
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.') {
                int du = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx > 0 && nx <= n && ny > 0 && ny <= m &&
                        mp[nx][ny] == '.') {
                        du++;
                    }
                }
                d[i][j] = du;
                if (du == 1)
                    q.push({i, j});
            } else
                ans[i][j] = '*';
        }
    }
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop();
        if (mp[x][y] == '*' || d[x][y] != 1)
            continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && ny > 0 && nx <= n && ny <= m && mp[nx][ny] == '.') {
                for (int j = 0; j < 4; j++) {
                    int nnx = nx + dx[j], nny = ny + dy[j];
                    if (nnx > 0 && nny > 0 && nnx <= n && nny <= m &&
                        mp[nnx][nny] == '.') {
                        d[nnx][nny]--;
                        if (d[nnx][nny] == 1)
                            q.push({nnx, nny});
                    }
                }
                mp[nx][ny] = mp[x][y] = '*';
                d[nx][ny] = d[x][y] = 0;
                cnt += 2;
                if (i == 0) {
                    ans[x][y] = '<', ans[nx][ny] = '>';
                } else if (i == 1) {
                    ans[x][y] = '>', ans[nx][ny] = '<';
                } else if (i == 2) {
                    ans[x][y] = '^', ans[nx][ny] = 'v';
                } else if (i == 3) {
                    ans[x][y] = 'v', ans[nx][ny] = '^';
                }
                break;
            }
        }
    }
    if (cnt == n * m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Not unique\n");
    }
    return 0;
}