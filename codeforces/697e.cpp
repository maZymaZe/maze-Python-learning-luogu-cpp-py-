#include <cstdio>
const long long MOD = 1e9 + 7;
long long qpow(long long a, long long b) {
    long long ans = 1, base = a;
    while (b) {
        if (b & 1)
            ans = ans * base % MOD;
        base = base * base % MOD;
        b >>= 1;
    }
    return ans;
}
long long n, t, y = 2;
bool f = false;
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t);
        if (t % 2 == 0)
            f = true;
        y = qpow(y, t) % MOD;
    }
    y = y * qpow(2, MOD - 2) % MOD;
    if (f)
        printf("%lld/%lld", (y + 1) * qpow(3, MOD - 2) % MOD, y);
    else
        printf("%lld/%lld", (y - 1 + MOD) * qpow(3, MOD - 2) % MOD, y);
    return 0;
}
