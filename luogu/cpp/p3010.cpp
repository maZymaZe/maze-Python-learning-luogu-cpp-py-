#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1e6, MMAX = 5e5 + 10, NMAX = 258;
ll n, v[NMAX], dp[MMAX], s = 0,vis[MMAX];
int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &v[i]), s += v[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= v[i]; j--) {
            dp[j] = (dp[j] + dp[j - v[i]]) ;
            if(dp[j])vis[j]=1;
            dp[j]%=MOD;
        }
    }
    int w = s / 2;
    for (int i = w; i >= 0; i--) {
        if (vis[i]) {
            printf("%d\n%lld\n", s-i-i, dp[i]);
            break;
        }
    }
    return 0;
}
