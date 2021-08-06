#include <cstdio>
typedef long long ll;
ll n, T, x, ans, c;
int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        ans = c = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &x);
            if (c + x >= 0) {
                c = c + x;
            } else {
                ans += -(c + x);
                c = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}