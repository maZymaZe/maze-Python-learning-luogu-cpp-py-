#include <cstdio>
void work() {
    long long ans = 0, a = 0, b = 0, x = 0, y = 0, n = 0;
    scanf("%lld%lld%lld%lld%lld", &a, &b, &x, &y, &n);
    if (n >= (a - x) + (b - y)) {
        printf("%lld\n", x * y);
        return;
    }
    ans = a * b;
    if (n > (a - x)) {
        if (ans > x * (a + b - n - x))
            ans = x * (a + b - n - x);
    } else if (ans > (a - n) * b)
        ans = (a - n) * b;
    if (n > (b - y)) {
        if (ans > y * (a + b - n - y))
            ans = y * (a + b - n - y);
    } else if (ans > (b - n) * a)
        ans = (b - n) * a;
    printf("%lld\n", ans);
    return;
}
int main() {
    int t = 0;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        work();
    }
    return 0;
}