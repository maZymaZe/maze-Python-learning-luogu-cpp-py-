#include <algorithm>
#include <cstdio>
using namespace std;
struct pr {
    int a, b;
    bool operator<(const pr& x) { return a < x.a || (a == x.a && b < x.b); }
};
pr w[1300];
struct rtg {
    int x1, x2, y1, y2;
} r[1020];
int tbl[3020], pt = 0;
long long ans = 0, pa = 0;
int main() {
    int n, tot = 0, pw;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &r[i].x1, &r[i].y2, &r[i].x2, &r[i].y1);
        tbl[++pt] = r[i].x1;
        tbl[++pt] = r[i].x2;
    }
    sort(tbl + 1, tbl + 1 + pt);
    tot = unique(tbl + 1, tbl + 1 + pt) - tbl-1;
    for (int i = 1; i < tot; i++) {
        pw = 0;
        for (int j = 0; j < n; j++) {
            if (tbl[i] >= r[j].x1 && tbl[i + 1] <= r[j].x2) {
                w[++pw] = {r[j].y1, r[j].y2};
            }
        }
        sort(w + 1, w + 1 + pw);
        if (pw) {
            int l=w[1].a,r=w[1].b;pa=0;
            for (int k = 2; k <= pw; k++) {
                if(w[k].a<=r)r=max(r,w[k].b);
                else {
                    pa+=r-l;
                    l=w[k].a,r=w[k].b;
                }
            }
            pa+=r-l;
            ans+=pa*(tbl[i+1]-tbl[i]);
        }
    }
    printf("%lld",ans);
    return 0;
}