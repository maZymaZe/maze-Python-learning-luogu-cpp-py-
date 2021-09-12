#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 5003;
struct item {
    int h, w, id;
    bool operator<(const item& x) const {
        if (x.h == h)
            return w < x.w;
        return h < x.h;
    }
} a[NMAX];
int pre[NMAX], n, ht, wt, c, dp[NMAX], ans[NMAX];
int main() {
    scanf("%d", &n);
    scanf("%d%d", &ht, &wt);
    for (int i = 1, hh, ww; i <= n; i++) {
        scanf("%d%d", &hh, &ww);
        if (hh > ht && ww > wt) {
            a[++c] = {hh, ww, i};
        }
    }

    if (c == 0) {
        printf("0\n");
        return 0;
    }
    sort(a + 1, a + 1 + c);
    for (int i = 1; i <= c; i++) {
        dp[i] = 1;
        pre[i] = -1;
        for (int j = i - 1; j > 0; j--) {
            if (a[j].h < a[i].h && a[j].w < a[i].w && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
    }
    int mx = -1, mxp = 0;
    for (int i = 1; i <= c; i++) {
        if (dp[i] > mx)
            mx = dp[i], mxp = i;
    }
    printf("%d\n", mx);
    c = 0;

    while (pre[mxp] != -1) {
        ans[++c] = a[mxp].id;
        mxp = pre[mxp];
    }
    ans[++c] = a[mxp].id;
    for (int i = c; i > 0; i--) {
        printf("%d ", ans[i]);
    }
    return 0;
}