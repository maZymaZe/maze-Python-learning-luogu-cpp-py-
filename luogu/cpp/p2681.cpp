#include <algorithm>
#include <cstdio>
#include <unordered_map>
using namespace std;
int a[1005], x, y, n, f, ans, m;
unordered_map<int, int> mp;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &f, &x, &y);
        int res = 0, mc = 0;
        if (f == 1)
            a[x] = y;
        else {
            mp.clear();
            for (int j = x; j <= y; j++) {
                if (mp.count(a[j])==0)
                    mp.insert({a[j], 1});
                else
                    mp[a[j]]++;
            }
            for (int j = x; j <= y; j++) {
                if (mp[a[j]] > mc ||
                    (mp[a[j]] == mc && a[j] < res)) {
                    res = a[j], mc = mp[a[j]];
                }
            }
            printf("%d\n", res);
        }
    }
    return 0;
}