#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 5e3 + 6;
struct cow {
    int x, y;
    bool operator<(const cow& t) { return x < t.x || (x == t.x && y < t.y); }
} a[NMAX];
int L, W, n;
bool cmp(const cow& a, const cow& b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
int main() {
    scanf("%d%d%d", &L, &W, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    a[++n] = {0, 0};
    a[++n] = {L, 0};
    a[++n] = {0, W};
    a[++n] = {L, W};
    sort(a + 1, a + 1 + n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int h = W, l = 0, v = L - a[i].x;
        for (int j = i + 1; j <= n; j++) {
            if (v * (h - l) <= res)
                break;
            res = max(res, (a[j].x - a[i].x) * (h - l));
            if (a[j].y == a[i].y)
                break;
            if (a[j].y > a[i].y)
                h = min(h, a[j].y);
            else
                l = max(l, a[j].y);
        }
        h = W, l = 0, v = a[i].x;
        for (int j = i - 1; j > 0; j--) {
            if (v * (h - l) <= res)
                break;
            res = max(res, (a[i].x - a[j].x) * (h - l));
            if (a[i].y == a[j].y)
                break;
            if (a[j].y > a[i].y)
                h = min(h, a[j].y);
            else
                l = max(l, a[j].y);
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i < n; i++)
        res = max(res, (a[i + 1].y - a[i].y) * L);
    printf("%d", res);
    return 0;
}