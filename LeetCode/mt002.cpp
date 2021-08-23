#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
struct MP {
    int l, r;
    bool operator<(const MP& other) const {
        return (l == other.l) ? r < other.r : l < other.l;
    }
};
map<MP, int> mp;
map<int, int> cal;
const int NMAX = 5e4 + 10;
int n, a[NMAX], b[NMAX], ans[NMAX];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    ans[n] = 0;
    for (int i = n; i > 1; i--) {
        int isl = b[i], isr = b[i], tot = a[b[i]];
        auto it = mp.lower_bound({b[i], b[i]});
        if (it != mp.end()) {
            if (it->first.l == b[i] + 1) {
                cal[it->second]--;
                if (cal[it->second] == 0) {
                    cal.erase(it->second);
                }
                isr = it->first.r;
                tot += it->second;
                it = mp.erase(it);
            }
        }
        if (it != mp.begin()) {
            --it;
            if (it->first.r + 1 == b[i]) {
                cal[it->second]--;
                if (cal[it->second] == 0) {
                    cal.erase(it->second);
                }
                isl = it->first.l;
                tot += it->second;
                it = mp.erase(it);
            }
        }
        mp.insert({{isl, isr}, tot});
        cal[tot]++;

        auto iit = cal.end();
        --iit;
        ans[i - 1] = iit->first;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
