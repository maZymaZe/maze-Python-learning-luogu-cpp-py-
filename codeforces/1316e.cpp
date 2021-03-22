#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll NMAX = 1e5 + 10, STM = (1 << 7) + 4;
ll n, p, k, t, dp[STM], C[STM];
struct PLAYER {
    int a, b[STM];
    bool operator<(const PLAYER& x) { return a > x.a; }
} py[NMAX];
struct NODE {
    int s, c;
    bool operator<(const NODE& x) { return c > x.c; }
} Q[STM];
int main() {
    scanf("%lld%lld%lld", &n, &p, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &py[i].a);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= p; j++) {
            scanf("%d", &py[i].b[j]);
        }
    }
    sort(py + 1, py + 1 + n);
    t = (1 << p) - 1;
    for (int i = 0; i <= t; i++) {
        int w = i, c = 0;
        while (w)
            w -= (w & (-w)), c++;
        Q[i + 1].s = i;
        Q[i + 1].c = c;
    }
    sort(Q + 1, Q + 2 + t);
    for (int i = 1; i <= t; i++) {
        dp[i] = -0x3f3f3f3f;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= t + 1; j++) {
            int s = Q[j].s, c = Q[j].c;
            ll w = dp[s];
            if (w < 0)
                continue;
            if (i - c <= k)
                dp[s] += py[i].a;
            for (int k = 1; k <= p; k++) {
                if (!(s & (1 << (k - 1)))) {
                    dp[s | (1 << (k - 1))] =
                        max(dp[s | (1 << (k - 1))], w + py[i].b[k]);
                }
            }
        }
    }
    printf("%lld", dp[t]);
    return 0;
}