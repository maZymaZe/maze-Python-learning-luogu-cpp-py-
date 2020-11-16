#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n, t1, t2;
const long double PI = acos(-1);
const int NMAX = 100000 + 10;
struct pr {
    long double pos;
    int id;
    bool operator<(const pr& x) { return pos < x.pos; }
} a[NMAX];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t1, &t2);
        a[i].id = i;
        if (!t1) {
            if (t2 > 0)
                a[i].pos = PI / 2;
            else
                a[i].pos = PI / 2 * 3;
        } else if (!t2) {
            if (t1 > 0)
                a[i].pos = 0;
            else
                a[i].pos = PI;
        } else {
            long double t = atan((long double)1.0 * t2 / t1);
            if (t1 > 0 && t2 > 0)
                a[i].pos = t;
            else if (t1 > 0 && t2 < 0)
                a[i].pos = t + 2 * PI;
            else
                a[i].pos = t + PI;
        }
    }
    sort(a + 1, a + 1 + n);
    long double delta = 999;
    for (int i = 1; i < n; i++) {
        if (a[i + 1].pos - a[i].pos < delta) {
            delta = a[i + 1].pos - a[i].pos;
            t1 = a[i + 1].id, t2 = a[i].id;
        }
    }
    if (a[1].pos - a[n].pos + 2 * PI < delta) {
        t1 = a[1].id, t2 = a[n].id;
    }
    printf("%d %d", t1, t2);
    return 0;
}