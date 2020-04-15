#include <algorithm>
#include <cstdio>
using namespace std;
int n, a[100005], b[100005], s[100005], t, ps = 0, w;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        a[t] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        b[i] = a[t];
    }
    for (int i = 1; i <= n; i++) {
        if (ps == 0) {
            ps++;
            s[ps] = b[i];
        } else {
            if (b[i] > s[ps]) {
                ps++;
                s[ps] = b[i];
            } else {
                w = lower_bound(s + 1, s + 1 + ps, b[i]) - s;
                s[w] = b[i];
            }
        }
    }
    printf("%d", ps);
    return 0;
}