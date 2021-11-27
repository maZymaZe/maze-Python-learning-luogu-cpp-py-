#include <algorithm>
#include <cstdio>
using namespace std;
struct gp {
    int a, b;
    bool operator<(const gp& x) const { return b > x.b; }
} w[3];
int n;
int main() {
    scanf("%d%d%d%d%d%d%d", &w[0].a, &w[1].a, &w[2].a, &n, &w[0].b, &w[1].b,
          &w[2].b);
    sort(w, w + 3);
    long long ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += ((long long)min(n, w[i].a)) * w[i].b;
        n -= min(n, w[i].a);
    }
    printf("%lld\n", ans);
    return 0;
}