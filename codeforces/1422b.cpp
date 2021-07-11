#include <cstdio>
const int NMAX = 102 + 10;
int abs(int x) {
    return x > 0 ? x : -x;
}
int d[5], top, mp[NMAX][NMAX];
long long ans = 0;
int findmid() {
    if (top < 4)
        return d[0];
    int ma1 = -1, ma1p, ma2 = -1;
    for (int i = 0; i <= 3; i++) {
        if (d[i] > ma1) {
            ma1 = d[i];
            ma1p = i;
        }
    }
    for (int i = 0; i <= 3; i++) {
        if (d[i] > ma2 && i != ma1p) {
            ma2 = d[i];
        }
    }
    return ma2;
}
int n, m, T;
int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &mp[i][j]);
            }
        }
        int hn = (n + 1) / 2, hm = (m + 1) / 2;
        for (int i = 1; i <= hn; i++) {
            for (int j = 1; j <= hm; j++) {
                top = 0;
                if (i == hn && (n & 1) && (j == hm) && (m & 1))
                    ;
                else if (i == hn && (n & 1)) {
                    d[top++] = mp[i][j];
                    d[top++] = mp[i][m - j + 1];
                    int mid = findmid();
                    for (int k = 0; k < top; k++) {
                        ans += abs(d[k] - mid);
                    }
                } else if (j == hm && (m & 1)) {
                    d[top++] = mp[i][j];
                    d[top++] = mp[n - i + 1][j];
                    int mid = findmid();
                    for (int k = 0; k < top; k++) {
                        ans += abs(d[k] - mid);
                    }
                } else {
                    d[top++] = mp[i][j];
                    d[top++] = mp[n - i + 1][j];
                    d[top++] = mp[i][m - j + 1];
                    d[top++] = mp[n - i + 1][m - j + 1];
                    int mid = findmid();
                    for (int k = 0; k < top; k++) {
                        ans += abs(d[k] - mid);
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}