#include <algorithm>
#include <cstdio>
using namespace std;
struct pr {
    int v, id;
    bool operator<(const pr& x) const {
        if (v == x.v)
            return id < x.id;
        return v > x.v;
    }
} p[50002];
int n, m, a[50004];
int main() {
    scanf("%d%d", &n, &m);
    if (m > n)
        m = n;
    for (int i = 1, tx, ty; i <= n; i++) {
        scanf("%d%d", &tx, &ty);
        p[i] = {2 * ty + tx, i};
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= m; i++)
        a[i] = p[i].id;
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++)
        printf("%d ", a[i]);
    return 0;
}