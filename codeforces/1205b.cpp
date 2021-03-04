#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 300, MMAX = 3e5 + 10;
const int INF = 7e7;
int n;
long long f[NMAX][NMAX], a[NMAX][NMAX], v[MMAX];
int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        if (v[i])
            cnt++;
        else
            i--, n--;
        if (cnt == 129) {
            printf("3\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((v[i] & v[j]) != 0 && i != j)
                a[i][j] = f[i][j] = 1;
            else
                a[i][j] = f[i][j] = INF;
        }
    }
    long long ans = INF;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && i != k && j != k) {
                    ans = min(ans, f[i][j] + a[i][k] + a[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    if (ans == INF)
        ans = -1;
    printf("%lld\n", ans);
    return 0;
}