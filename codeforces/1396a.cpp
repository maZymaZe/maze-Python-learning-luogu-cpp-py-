#include <cstdio>
long long n, a[100003];
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    printf("1 1\n");
    printf("%d\n", a[1] * (-1));
    a[1] = 0;
    if (n == 1) {
        printf("1 1\n0\n1 1\n0\n");
        return 0;
    }
    printf("%d %lld\n", 2, n);
    for (int i = 2; i <= n; i++) {
        printf("%lld ", a[i] * (n - 1));
    }
    printf("\n");
    printf("%d %lld\n", 1, n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a[i] * n * (-1));
    }
    printf("\n");
    return 0;
}