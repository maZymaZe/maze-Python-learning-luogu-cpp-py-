#include <algorithm>
#include <cstdio>
using namespace std;
int n, W;
double ans, f[1004];
struct COW {
    int w, t;
    double js;
} c[253];
bool solve(double x) {
    for (int i = 1; i <= W; i++)
        f[i] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        c[i].js = c[i].t - c[i].w * x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            f[min(c[i].w + j, W)] = max(f[min(c[i].w + j, W)], f[j] + c[i].js);
        }
    }
    return f[W] >= 0;
}
int main() {
    scanf("%d%d", &n, &W);
    double l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i].w, &c[i].t);
        r += c[i].t;
    }
    r += 100;
    while (r - l >= 0.0000001) {
        double mid = (l + r) / 2;
        if (solve(mid)) {
            l = mid + 0.0000001;
            ans = l;
        } else
            r = mid - 0.0000001;
    }
    ans = ans * 1000;
    printf("%d", (int)ans);
    return 0;
}