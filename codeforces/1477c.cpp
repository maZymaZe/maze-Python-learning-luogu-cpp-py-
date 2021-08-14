#include <cstdio>
typedef long long ll;
int main() {
    int n, vis[5003] = {0};
    ll x[5003], y[5003];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    printf("1 ");
    int nw = 1;
    vis[1] = 1;
    for (int i = 1; i < n; i++) {
        ll mxl = 0, mxp = -1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) {
                if ((x[nw] - x[j]) * (x[nw] - x[j]) +
                        (y[nw] - y[j]) * (y[nw] - y[j]) >
                    mxl) {
                    mxl = (x[nw] - x[j]) * (x[nw] - x[j]) +
                          (y[nw] - y[j]) * (y[nw] - y[j]);
                    mxp = j;
                }
            }
        }
        vis[mxp] = 1;
        printf("%d ", mxp);
        nw = mxp;
    }
    return 0;
}