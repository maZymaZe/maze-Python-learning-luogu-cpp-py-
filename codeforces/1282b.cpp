#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int NMAX = 2e5 + 10;
long long T, a[NMAX], n, p, k;
vector<vector<long long> > mp;
int main() {
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &p, &k);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        sort(a, a + n);
        mp.clear();
        mp.resize(k);
        for (int i = 0; i < k; i++)
            mp[i].push_back(0);
        for (int i = k - 1; i < n; i++) {
            long long nx = mp[i % k].back() + a[i];
            if (nx > p)
                nx = p + 1;
            mp[i % k].push_back(nx);
        }
        long long pt = 0, ans = 0;
        auto it = upper_bound(mp[k - 1].begin(), mp[k - 1].end(), p);
        ans = max(ans, k * (it - mp[k - 1].begin() - 1));
        for (int i = 0; i < k - 1; i++) {
            pt += a[i];
            if (pt > p)
                break;
            auto it = upper_bound(mp[i].begin(), mp[i].end(), p - pt);

            ans = max(ans, k * (it - mp[i].begin() - 1) + i + 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}