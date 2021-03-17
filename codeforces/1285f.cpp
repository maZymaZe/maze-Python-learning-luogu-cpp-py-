#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int NMAX = 1e5 + 10;
int n, lim, a[NMAX], vis[NMAX];
vector<int> vec, d[NMAX];
int cnt[NMAX], stk[NMAX], rsp;
int p[NMAX], v[NMAX], mu[NMAX], pcnt = 0;
void findprime(int sz) {
    mu[1] = 1;
    for (int i = 2; i <= sz; i++) {
        if (!v[i])
            p[++pcnt] = i, mu[i] = -1;
        for (int j = 1; j <= pcnt && i * p[j] <= sz; j++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
            else
                mu[i * p[j]] = -mu[i];
        }
    }
}
bool cmp(const int a, const int b){ return a > b ? 1:0;}
int main() {
    findprime(1e5);
    for (int i = 1; i <= 1e5; i++) {
        for (int j = i; j <= 1e5; j += i)
            d[j].push_back(i);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        lim = max(lim, a[i]);
        ++vis[a[i]];
    }
    ll ans = 0;
    for (int g = 1; g <= lim; g++) {
        vec.clear();
        for (int i = g; i <= lim; i += g) {
            for (int j = 1; j <= vis[i]; ++j)
                vec.push_back(i / g);
        }
        sort(vec.begin(), vec.end(), cmp);
        for (int i : vec) {
            int s = 0;
            for (int j : d[i])
                s += mu[j] * cnt[j];
            while (s) {
                int x = stk[rsp--];
                if (__gcd(i, x) == 1) {
                    ans = max(ans, 1ll * g * i * x), --s;
                }
                for (int j : d[x])
                    --cnt[j];
            }
            stk[++rsp]=i;
            for (int j:d[i]) ++cnt[j];
        }
        while (rsp) {
            int x = stk[rsp--];
            for (int i : d[x])
                cnt[i]--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}