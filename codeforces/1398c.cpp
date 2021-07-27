#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mp;
int T, n, x, tot;
long long ans;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        tot = 0;
        ans = 0;
        mp.clear();
        mp[0] = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%1d", &x);
            tot += x - 1;
            ans += mp[tot];
            mp[tot]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}