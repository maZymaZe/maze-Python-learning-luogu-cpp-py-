#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 2002;
int n, m, mp[MAXN][MAXN], up[MAXN][MAXN], left[MAXN][MAXN], right[MAXN][MAXN],
    ans1, ans2;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
            left[i][j] = right[i][j] = j;
            up[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (mp[i][j] != mp[i][j - 1])
                left[i][j] = left[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m - 1; j > 0; j--) {
            if (mp[i][j] != mp[i][j + 1])
                right[i][j] = right[i][j + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1 && mp[i][j] != mp[i - 1][j]) {
                left[i][j] = max(left[i][j], left[i - 1][j]);
                right[i][j] = min(right[i][j], right[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }
            int a = right[i][j] - left[i][j] + 1;
            int b = min(a, up[i][j]);
            ans1 = max(ans1, b * b);
            ans2 = max(ans2, a * up[i][j]);
        }
    }
    printf("%d\n%d", ans1, ans2);
    return 0;
}