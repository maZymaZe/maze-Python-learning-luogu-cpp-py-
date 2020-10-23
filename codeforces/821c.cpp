#include <algorithm>
#include <cstdio>
using namespace std;
const int NMAX = 3e5 + 10;
char s[10];
int n, top = 1, sorti, a[NMAX], ans = 0, t, ned = 1, appear[NMAX], cnt = 0;
int main() {
    scanf("%d", &n);
    int m = 2 * n;
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        if (s[0] == 'r') {
            if (a[top] == ned && appear[ned] > sorti)
                top--, cnt--;
            else {
                if (appear[ned] > sorti || cnt > 0) {
                    sorti = i;
                    ans++;
                    cnt = 0;
                }
            }
            ned++;
        } else {
            scanf("%d", &t);
            a[++top] = t;
            appear[t] = i;
            cnt++;
        }
    }
    printf("%d", ans);
    return 0;
}