#include <cstdio>
#include <cstring>
struct edge {
    int u, v, nx;
} e[200005];
int flag, n, k, t, t1, t2, h[100005] = {0}, ff;
int dfs(int x, int fa) {
    int sz = 1;
    for (int i = h[x]; i; i = e[i].nx) {
        if (e[i].v != fa) {
            int tt = dfs(e[i].v, x);
            if (tt == -1) return -1;
            if (tt == k) continue;
            if (tt > k) return -1;
            sz += tt;
        }
    }
    return sz;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        flag = 1;
        memset(h, 0, sizeof(h));
        memset(e, 0, sizeof(e));
        scanf("%d%d", &n, &k);

        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &t1, &t2);
            e[(i << 1) + 2].u = t1;
            e[(i << 1) + 2].v = t2;
            e[(i << 1) + 2].nx = h[t1];
            h[t1] = (i << 1) + 2;
            e[(i << 1) | 1].u = t2;
            e[(i << 1) | 1].v = t1;
            e[(i << 1) | 1].nx = h[t2];
            h[t2] = ((i << 1) | 1);
        }
        if (n % k != 0) {
            printf("NO\n");
            continue;
        }
        
        ff = dfs(1, 0);
        if (ff == k || ff == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}