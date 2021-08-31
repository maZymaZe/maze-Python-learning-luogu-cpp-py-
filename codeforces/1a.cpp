#include <cstdio>
long long a, b, c;
int main() {
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%lld\n", ((a + c - 1) / c) * ((b + c - 1) / c));
    return 0;
}