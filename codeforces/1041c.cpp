#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
struct pr {
    ll val, pos;
    bool operator<(const pr& x) const { return val < x.val; }
};
set<pr> s;
const int NMAX = 2e5 + 10;
ll n, m, d, ans[NMAX], t;
int main() {
    scanf("%lld%lld%lld", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t);
        s.insert({t, i});
    }
    int cnt = 0;
    while (!s.empty()) {
        cnt++;
        auto it = s.begin();
        ans[it->pos] = cnt;
        ll p = it->val;
        s.erase(it);
        it = s.upper_bound({p + d, 0});
        while (it != s.end()) {
            ans[it->pos] = cnt;
            p = it->val;
            s.erase(it);
            it = s.upper_bound({p + d, 0});
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    return 0;
}