#include <cstdio>
int a[30], pt, b, f, aa[30], ppt;
int main() {
    scanf("%d", &b);
    for (int i = 1; i <= 300; i++) {
        pt = 0;
        f = 1;
        int w = i * i;
        while (w) {
            a[++pt] = w % b;
            w /= b;
        }
        for (int j = 1; j <= pt / 2; j++) {
            if (a[j] != a[pt - j + 1]) {
                f = 0;
                break;
            }
        }
        if (f) {
            ppt = 0;
            w = i;
            while (w) {
                aa[++ppt] = w % b;
                w /= b;
            }
            for (int j = ppt; j > 0; j--) {
                if (aa[j] > 9)
                    printf("%c", aa[j] - 10 + 'A');
                else
                    printf("%d", aa[j]);
            }
            printf(" ");
            for (int j = 1; j <= pt; j++) {
                if (a[j] > 9)
                    printf("%c", a[j] - 10 + 'A');
                else
                    printf("%d", a[j]);
            }
            printf("\n");
        }
    }
    return 0;
}