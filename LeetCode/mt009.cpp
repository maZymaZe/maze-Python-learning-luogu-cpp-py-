#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
vector<int> ft[1003];
ll n, m, dp[1003][1003];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                ft[i].push_back(j);
                if (j * j != i)
                    ft[i].push_back(i / j);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k : ft[j]) {
                if (i == 1) {
                    dp[i][k] = 1;
                } else {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[m][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}