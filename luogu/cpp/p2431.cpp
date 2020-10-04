#include <cstdio>
long long a, b;
int ans = 0;
int main() {
    scanf("%lld%lld", &a, &b);
    for (int i = 62; i >= 0; i--) {
        long long mask = 1ll << i;
        if ((a & mask) == (b & mask))
            ans += (!!(mask & a));
        else {
            ans += (i != 0) ? i : 1;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
