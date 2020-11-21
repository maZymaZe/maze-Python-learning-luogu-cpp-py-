#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int NMAX = 1e6 + 7;
int n, card[NMAX], a[NMAX], w[NMAX], l[NMAX];
set<int> s;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), card[a[i]] = 1;
    for (int i = 1; i <= 2 * n; i++)
        if (!card[i])
            s.insert(i);
    for (int i = 1; i <= n; i++) {
        auto t = s.upper_bound(a[i]);
        if (t == s.end())
            w[i] = w[i - 1];
        else {
            w[i] = w[i - 1] + 1;
            s.erase(t);
        }
    }
    s.clear();
    for (int i = 1; i <= 2 * n; i++)
        if (!card[i])
            s.insert(-i);
    for (int i = n; i > 0; i--) {
        auto t = s.upper_bound(-a[i]);
        if (t == s.end())
            l[i] = l[i + 1];
        else {
            l[i] = l[i + 1] + 1;
            s.erase(t);
        }
    }
    int ans = l[1];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, w[i] + l[i + 1]);
    }
    printf("%d\n", ans);
    return 0;
}