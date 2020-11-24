#include <cstdio>
#include <cstring>
const int NMAX = 2e5 + 10;
struct EDGE {
    int u, v, nx;
} e[NMAX * 2];
int n, h[NMAX], ep, t1, t2, T, m, maxdep, maxw, t, c[NMAX], cnt[2], f[NMAX],
    a[NMAX], b[NMAX];

inline void add(int a, int b) {
    e[++ep] = {a, b, h[a]};
    h[a] = ep;
}
int ff(int x) {
    if (f[x] == x)
        return x;
    return f[x] = ff(f[x]);
}
void dfs(int dep,int x,int fa){
    if(dep>maxdep){
        maxdep=dep,maxw=x;
    }
    for(int i=h[x];i;i=e[i].nx){
        if(e[i].v!=fa){
            dfs(dep+1,e[i].v,x);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        scanf("%d", &c[i]);
    }
    ep = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);

        if (c[ff(a[i])] == c[ff(b[i])])
            f[ff(a[i])] = ff(b[i]);
    }
    for (int i = 1; i <= n; i++)
        ff(i);
    for (int i = 1; i < n; i++) {
        if (f[a[i]] != f[b[i]]) {
            add(f[a[i]], f[b[i]]), add(f[b[i]], f[a[i]]);
        }
    }
    dfs(0, f[1], 0);
    dfs(0, maxw, 0);
    printf("%d\n", (maxdep + 1) /2);

    return 0;
}