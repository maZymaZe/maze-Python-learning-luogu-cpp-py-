#include <cstdio>
inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}
typedef long long ll;
const int NMAX = 5e6 + 10;
int n, p, k, a[NMAX], pf[NMAX], pb[NMAX];
ll qpow(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1)
            ret = ret * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ret;
}
int inv(int t) {
    return qpow(t, p - 2);
}
int main() {
    n = Read(), p = Read(), k = Read();
    int tot = 0, q = 1;
    pf[0] = 1, pb[n + 1] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = Read();
        pf[i] = 1ll * pf[i - 1] * a[i] % p;
    }
    for (int i = n; i > 0; i--) {
        pb[i] = 1ll * pb[i + 1] * a[i] % p;
    }
    for (int i = 1, t; i <= n; i++) {
        q = 1ll * q * k % p;
        tot = (1ll * tot + 1ll * pf[i - 1] * pb[i + 1] % p * q % p) % p;
    }
    printf("%d\n", (int)(1ll * tot * inv(pf[n]) % p));
    return 0;
}
