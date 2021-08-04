#include <cstdio>
int a[102] = {0};
int T, n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int j = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] > a[j])
                j = i;
        }
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (i != j)
                c += a[i];
        }
        if (a[j] > c || ((c ^ a[j]) & 1)) {
            printf("T\n");
        } else
            printf("HL\n");
    }
    return 0;
}