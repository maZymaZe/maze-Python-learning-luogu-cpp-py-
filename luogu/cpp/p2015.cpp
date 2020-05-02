#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, q, h[105], t1, t2, t3, a[105], dp[105][105] = {0}, ans = 0;
vector<int> vc[105];
struct edge {
    int u, v, nx, w;
} e[233];
void dfs1(int x, int fa) {
    for (int i = h[x]; i; i = e[i].nx) {
        if (e[i].v != fa) {
            a[e[i].v] = e[i].w;
            vc[x].push_back(e[i].v);
            dfs1(e[i].v, x);
        }
    }
}
int dfs(int root, int m) {
    if (dp[root][m]) return dp[root][m];
    if (m == 0) return 0;
    if (vc[root].size() == 0) return 0;
    int l, r;
    l = vc[root][0];
    r = vc[root][1];

    for (int i = 1; i < m; i++) {
        dp[root][m] =
            max(dp[root][m], a[l] + a[r] + dfs(l, i - 1) + dfs(r, m - i - 1));
    }
    dp[root][m] = max(dp[root][m], a[l] + dfs(l, m - 1));
    dp[root][m] = max(dp[root][m], a[r] + dfs(r, m - 1));
    return dp[root][m];
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &t1, &t2, &t3);
        e[i << 1].u = t1;
        e[i << 1].v = t2;
        e[i << 1].nx = h[t1];
        h[t1] = i << 1;
        e[i << 1].w = t3;
        e[(i << 1) - 1].u = t2;
        e[(i << 1) - 1].v = t1;
        e[(i << 1) - 1].nx = h[t2];
        h[t2] = (i << 1) - 1;
        e[(i << 1) - 1].w = t3;
    }
    dfs1(1, 0);
    dfs(1, q);
    printf("%d", dp[1][q]);
    return 0;
}