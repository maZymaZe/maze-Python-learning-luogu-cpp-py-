#include <cstdio>
#include <cstring>
int max(int a, int b) {
    if (a > b) return a;
    return b;
}
int main() {
    int m, n, f[2000] = {0}, s[5], a[30] = {0}, sum = 0, ans = 0;
    for (int i = 1; i <= 4; i++) scanf("%d", &s[i]);
    for (int k = 1; k <= 4; k++) {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        sum = 0;
        for (int i = 1; i <= s[k]; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        for (int i = 1; i <= s[k]; i++) {
            for (int j = sum / 2; j >= a[i]; j--) {
                if (j >= a[i]) {
                    f[j] = max(f[j], f[j - a[i]] + a[i]);
                }
            }
        }
        ans += sum - f[sum / 2];
    }
    printf("%d", ans);
    return 0;
}