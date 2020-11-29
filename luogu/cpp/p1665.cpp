#include <cstdio>
int mp[110][110], n, x[600], y[600], ans = 0;
int nx1, nx2, ny1, ny2, dx, dy;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        x[i] += 50, y[i] += 50;
        mp[x[i]][y[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j =1; j <= n; j++) {
            if(i==j)continue;
            dx = x[i] - x[j], dy = y[i] - y[j];

            nx1 = x[i] + dy, nx2 = x[j] + dy, ny1 = y[i] - dx, ny2 = y[j] - dx;
            if (nx1 >= 0 && nx1 <= 100 && ny1 >= 0 && ny1 <= 100 && nx2 >= 0 &&
                nx2 <= 100 && ny2 >= 0 && ny2 <= 100 && mp[nx1][ny1] &&
                mp[nx2][ny2])
                ans++;
            nx1 = x[i] - dy, nx2 = x[j] - dy, ny1 = y[i] + dx, ny2 = y[j] + dx;
            if (nx1 >= 0 && nx1 <= 100 && ny1 >= 0 && ny1 <= 100 && nx2 >= 0 &&
                nx2 <= 100 && ny2 >= 0 && ny2 <= 100 && mp[nx1][ny1] &&
                mp[nx2][ny2])
                ans++;
        }
    }
    printf("%d\n", ans/8);
    return 0;
}