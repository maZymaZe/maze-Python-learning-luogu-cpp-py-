#include <cstdio>
int main() {
    long long T, a, b, c;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", a + b + c - 1);
    }
    return 0;
}