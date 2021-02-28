#include <cmath>
#include <cstdio>
typedef long long ll;
int main() {
    ll n, b, t, ans = 0x7fffffffffffffffll;
    scanf("%lld%lld", &n, &b);
    ll m = sqrt(b) + 1000;
    for (ll i = 2; i <= m; i++) {
        if (b % i == 0) {
            ll cnt = 0, c = 0;
            while (b % i == 0) {
                b /= i;
                cnt++;
            }
            ll w = n, p = i;
            while (w >= p) {
                c += w / p;
                if (w / i + 10 < p)
                    break;
                p *= i;
                if (p < 0)
                    break;
            }
            ll tans = c / cnt;
            if (tans < ans)
                ans = tans;
        }
    }
    if (b != 1) {
        ll r = n, pc = 0, tb = b;
        while (r >= tb) {
            pc += r / tb;
            if (r / b + 10 < tb)
                break;
            tb *= b;
            if (tb < 0)
                break;
        }
        if (pc < ans)
            ans = pc;
    }
    if (ans == 0x7fffffffffffffffll)
        ans = 0;
    printf("%lld", ans);
    return 0;
}