#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n, m, mp[501][501], cnt = 0;
string s;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
void f(int x, int y) {
    mp[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= n && ny <= m && mp[nx][ny]==0)
            f(nx, ny);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '*')
                mp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mp[i][1] == 0) {
            f(i, 1);
        }
        if (mp[i][m] == 0) {
            f(i, m);
        }
    }
    for (int j = 1; j <= m; j++) {
        if (mp[1][j] == 0) {
            f(1, j);
        }
        if (mp[n][j] == 0) {
            f(n, j);
        }
    }
     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt+=(mp[i][j]==0);
        }
    }
    printf("%d", cnt);
    return 0;
}