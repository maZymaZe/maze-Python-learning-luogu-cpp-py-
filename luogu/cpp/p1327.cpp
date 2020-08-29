#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 1e5 + 10;
int n, a[NMAX], b[NMAX], vis[NMAX], nxt[NMAX], cnt = 0, ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        nxt[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            int p = i;
            cnt = 0;
            while (nxt[p] != i) {
                vis[p] = 1;
                cnt++;
                p = nxt[p];
            }
            vis[p] = 1;
            ans += cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}