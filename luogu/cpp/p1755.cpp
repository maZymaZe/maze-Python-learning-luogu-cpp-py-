#include <cstdio>
#include <cstring>
int fb[60] = {0};

int m, t, ans[50], ca = 0;
bool f;
int main() {
    scanf("%d", &m);
    fb[1] = fb[2] = 1;
    for (int i = 3; i <= 44; i++) {
        fb[i] = fb[i - 1] + fb[i - 2];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        memset(ans, 0, sizeof(ans));
        f = false;
        ca = 0;
        printf("%d=", t);
        for (int j = 44; j > 0; j--) {
            if (t) {
                if (t >= fb[j]) {
                    ans[++ca] = fb[j];
                    t -= ans[ca];
                }
            } else
                break;
        }
        for (int j = ca; j > 0; j--) {
            if (f)
                printf("+%d", ans[j]);
            else
                printf("%d", ans[j]), f = true;
        }
        printf("\n");
    }
    return 0;
}
