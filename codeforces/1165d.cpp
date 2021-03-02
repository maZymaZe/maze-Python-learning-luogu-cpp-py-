#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;
ll d[305], gs;
int T, n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int f = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &d[i]);
        }
        sort(d + 1, d + 1 + n);
        gs = d[1] * d[n];
        ll l = 1, r = n, lim = sqrt(gs);
        for (ll i = 2; i <= lim; i++) {
            if (gs % i == 0) {
                if (i * i == gs) {
                    if (l != r) {
                        f = 0;
                        break;
                    } else if (d[l] == i) {
                        f = 3;
                        break;
                    } else {
                        f = 0;
                        break;
                    }
                } else {
                    if (d[l] != i || d[r] != gs / i) {
                        f = 0;
                        break;
                    } else
                        l++, r--;
                }
            }
        }
        if (f == 1 && l != r + 1)
            f = 0;
        if (f != 0)
            printf("%lld\n", gs);
        else
            printf("-1\n");
    }
    return 0;
}