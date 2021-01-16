#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct POINT {
    double x, y;
} p[200040];
int n, tmp[200040], tp = 0;
double getdis(int i, int j) {
    return sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) +
                (p[i].y - p[j].y) * (p[i].y - p[j].y));
}
bool cmp1(const POINT& a, const POINT& b) {
    if (a.x < b.x)
        return 1;
    if (a.x == b.x)
        return a.y < b.y;
    return 0;
}
bool cmp2(const int& a, const int& b) {
    return p[a].y < p[b].y;
}
double merge(int l, int r) {
    double dis = 2 << 20;
    if (l == r)
        return dis;
    if (l + 1 == r)
        return getdis(l, r);
    int mid = l + ((r - l) >> 1);
    double dis1 = merge(l, mid);
    double dis2 = merge(mid + 1, r);
    dis = min(dis1, dis2);
    tp = 0;
    for (int i = l; i <= r; i++) {
        if (fabs(p[i].x - p[mid].x) <= dis)
            tmp[++tp] = i;
    }
    sort(tmp + 1, tmp + 1 + tp, cmp2);
    for (int i = 1; i <= tp; i++) {
        for (int j = i + 1; j <= tp && p[tmp[j]].y - p[tmp[i]].y <= dis; j++)
            dis = min(dis, getdis(tmp[j], tmp[i]));
    }
    return dis;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1, cmp1);
    printf("%.4lf", merge(1, n));
    return 0;
}