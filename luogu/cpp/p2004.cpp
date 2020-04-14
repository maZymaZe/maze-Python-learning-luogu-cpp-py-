#include <cstdio>
template <typename T>
T max(T a, T b) {
    if (a > b)
        return a;
    else
        return b;
}
int n, m, c, mp[1020][1020], a1, a2;
long long v[1020][1020], ans = -9999999999999;
int main() {
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                v[i][j] = mp[i][j];
            } else if (i == 1) {
                v[i][j] = v[i][j - 1] + mp[i][j];
            } else if (j == 1) {
                v[i][j] = v[i - 1][j] + mp[i][j];
            } else {
                v[i][j] =
                    v[i][j - 1] - v[i - 1][j - 1] + v[i - 1][j] + mp[i][j];
            }
        }
    }
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            if (ans < v[i + c - 1][j + c - 1] - v[i - 1][j + c - 1] -
                          v[i + c - 1][j - 1] + v[i - 1][j - 1]) {
                ans = v[i + c - 1][j + c - 1] - v[i - 1][j + c - 1] -
                      v[i + c - 1][j - 1] + v[i - 1][j - 1];
                a1 = i;
                a2 = j;
            }
        }
    }
    printf("%d %d", a1, a2);
    return 0;
}