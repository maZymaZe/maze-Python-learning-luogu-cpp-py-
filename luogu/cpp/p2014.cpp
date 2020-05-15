#include <cstdio>
#include<algorithm>
using namespace std;
struct edge {
    int u, v, nx;
} e[333];

int h[333], n, m, val[333], fa[333], dp[333][333];

void dfs(int x) {
    for (int i = h[x]; i; i = e[i].nx) {
        dfs(e[i].v);
        for (int j = m + 1; j >= 1; j--) {
            for (int k = 0; k < j; k++) {
                dp[x][j] = max(dp[x][j], dp[e[i].v][k] + dp[x][j - k]);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d",  &e[i].u,&dp[i][1]);
        e[i].nx = h[e[i].u];
        e[i].v = i;
        h[e[i].u] = i;
    }
    dfs(0);
    printf("%d", dp[0][m + 1]);
    return 0;
}