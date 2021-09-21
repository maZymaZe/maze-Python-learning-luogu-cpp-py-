#include <cstdio>
void exgcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1, y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
int main() {
    long long a, b, c, x = 0, y = 0, g;
    scanf("%lld%lld%lld", &a, &b, &c);
    c = -c;
    exgcd(a, b, x, y);
    g = a * x + b * y;
    if (c % g) {
        printf("-1\n");
        return 0;
    }
    x = c / g * x;
    y = c / g * y;
    printf("%lld %lld\n", x, y);
    return 0;
}