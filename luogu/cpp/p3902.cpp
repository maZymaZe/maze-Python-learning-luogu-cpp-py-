#include <algorithm>
#include <cstdio>
using namespace std;
int n, a[100005], b[100005], s[100005], t, ps = 0, w;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
       a[i]=t;
    }
    for (int i = 1; i <= n; i++) {
        if (ps == 0) {
            ps++;
            s[ps] = a[i];
        } else {
            if (a[i] > s[ps]) {
                ps++;
                s[ps] = a[i];
            } else {
                w = lower_bound(s + 1, s + 1 + ps, a[i]) - s;
                s[w] =a[i];
            }
        }
    }
    printf("%d", n-ps);
    return 0;
}