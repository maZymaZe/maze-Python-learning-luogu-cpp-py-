#include <cstdio>
#include <vector>
using namespace std;
int n, m;
const int NMAX = 1e5 + 10;
int a[NMAX];
long long ans = 0;
vector<int> oc[NMAX];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), oc[a[i]].push_back(i);
    int bg = n + 1, p = n, q = 1, gg = 0, fp;
    while (p > 0 && (oc[p].empty() || bg > oc[p].back())) {
        if (!oc[p].empty())
            bg = oc[p].front();
        p--;
    }
    ans += (m - p + 1);
    q++;
    fp = p;
    while (q <= m) {
        if (!oc[q - 1].empty() && oc[q - 1].front() < gg) {
            break;
        }
        if (!oc[q - 1].empty())
            gg = oc[q - 1].back();
        while (p <= m) {
            while (p <= m && oc[p + 1].empty())
                p++;
            if (p + 1 <= m && oc[p + 1].front() < gg)
                fp = p + 1, p++;
            else
                break;
        }
        ans += m - fp + 1;
        q++;
    }
    printf("%lld\n", ans);
    return 0;
}