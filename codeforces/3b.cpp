#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
struct pr {
    long long val, id;
    bool operator<(const pr& x) const { return val > x.val; }
};
int op, n, tv, m;
const int NMAX = 1e5 + 10;
vector<pr> pk[3];
long long ps[NMAX][3];
vector<int> ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &op, &tv);
        pk[op].push_back({tv, i});
    }
    sort(pk[1].begin(), pk[1].end()), sort(pk[2].begin(), pk[2].end());
    for (int i = 1; i <= pk[1].size(); i++) {
        ps[i][1] = ps[i - 1][1] + pk[1][i - 1].val;
    }
    for (int i = 1; i <= pk[2].size(); i++) {
        ps[i][2] = ps[i - 1][2] + pk[2][i - 1].val;
    }
    int ans1 = 0, ans2 = 0;
    ans1 = min((int)pk[1].size(), m);
    int lf = m - ans1;
    ans2 = min((int)pk[2].size(), lf / 2);
    long long nmx = ps[ans1][1] + ps[ans2][2];
    int t2 = ans2, t1 = ans1;
    while (t2 < pk[2].size()) {
        t2++;
        if (2 * t2 > m)
            break;
        t1 = max(0, t1 - 2);
        long long tmx = ps[t1][1] + ps[t2][2];
        if (tmx > nmx) {
            nmx = tmx, ans1 = t1, ans2 = t2;
        }
    }

    int ans3 = 0, ans4 = 0;
    ans3 = min((int)pk[1].size(), m);
    if (ans3 != 0) {
        ans3--;
        int llf = m - ans3;
        ans4 = min((int)pk[2].size(), llf / 2);
        long long nnmx = ps[ans3][1] + ps[ans4][2];
        int tt2 = ans4, tt1 = ans3;
        while (tt2 < pk[2].size()) {
            tt2++;
            if (2 * tt2 > m)
                break;
            tt1 = max(0, tt1 - 2);
            long long ttmx = ps[tt1][1] + ps[tt2][2];
            if (ttmx > nnmx) {
                nnmx = ttmx, ans3 = tt1, ans4 = tt2;
            }
        }

        if (nnmx > nmx) {
            nmx = nnmx, ans1 = ans3, ans2 = ans4;
        }
    }

    printf("%lld\n", nmx);
    for (int i = 0; i < ans1; i++)
        ans.push_back(pk[1][i].id);
    for (int i = 0; i < ans2; i++)
        ans.push_back(pk[2][i].id);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        printf("%d ", i);
    return 0;
}