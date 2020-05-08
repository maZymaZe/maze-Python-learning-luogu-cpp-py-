#include <algorithm>
#include <cstdio>
#define MAX 100006
using namespace std;
int f[MAX];
int ff(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = ff(f[x]);
}
struct edge {
    int u, v, w;
    bool operator<(const edge& x) { return this->w < x.w; }
} e[MAX];
int enemy[MAX] = {0}, n, u[MAX], m, t, t1, t2;
long long ans = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) scanf("%d", &t), enemy[t] = 1;
    for (int i = 0; i < n; i++) f[i] = i;
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &t1, &t2, &t);
        e[i].u = t1;
        e[i].v = t2;
        e[i].w = t;
        ans += t;
    }
    sort(e + 1, e + n);
    for (int i = n - 1; i >= 1; i--) {
        t1 = ff(e[i].u);
        t2 = ff(e[i].v);
        if (!(enemy[t1] && enemy[t2])) {
            ans -= e[i].w;
            f[t2] = t1;

            if (enemy[t1]) {
                enemy[t2] = 1;
            } else if (enemy[t2]) {
                enemy[t1] = 1;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}