#include <cstdio>
int T, n, a[103];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = n - 1; i >= 0; i--)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}