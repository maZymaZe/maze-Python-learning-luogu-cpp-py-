#include <algorithm>
#include <cstdio>
using namespace std;
long long g, s, top, ans = 0x7fffffffffffffffll;
int n, m, f[204], t1, t2, t3, t4;
struct EDGE {
    long long u, v, w1, w2;
} e[50040], tmp[204];
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
bool cmp(const EDGE& a, const EDGE& b) {
    if (a.w1 < b.w1)
        return true;
    else if (a.w1 == b.w1)
        return a.w2 < b.w2;
    return false;
}
int main() {
    scanf("%d%d%lld%lld", &n, &m, &g, &s);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w1, &e[i].w2);
    }
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        for (int a = 1; a <= n; a++)
            f[a] = a;
        tmp[++top] = e[i];
        for (int j = top; j >= 2; j--)
            if (tmp[j].w2 < tmp[j - 1].w2)
                swap(tmp[j], tmp[j - 1]);
        long long cnt = 0;
        for (int j = 1; j <= top; j++) {
            int u = ff(tmp[j].u), v = ff(tmp[j].v);
            if (u != v) {
                f[u] = v;
                tmp[++cnt] = tmp[j];
                if (cnt == n - 1)
                    break;
            }
        }
        if (cnt == n - 1) {
            ans = min(ans, g * e[i].w1 + s * tmp[cnt].w2);
        }
        top = cnt;
    }
    if (ans == 0x7fffffffffffffffll)
        printf("-1\n");
    else
        printf("%lld\n", ans);
    return 0;
}