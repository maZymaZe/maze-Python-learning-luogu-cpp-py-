#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
ll n, k;
string s;
unordered_map<string, int> mp;
vector<int> cnt;
ll c[2002][2002] = {0}, MOD = 1e9 + 7, dp[2002][2002] = {0};

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    for (auto it : mp)
        cnt.push_back(it.second);

    for (int i = 1; i <= 2000; i++) {
        c[i][0] = 1;
        c[i][1] = i;
        for (int j = 2; j < i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
        c[i][i] = 1;
    }
    int len = cnt.size();
    dp[0][0] = 1;
    for (int t = 0; t < len; t++) {
        for (int i = 0; i <= cnt[t]; i++) {
            for (int j = 0; j <= k; j++) {
                if (j >= (i - 1) * i / 2) {
                    (dp[t + 1][j] +=
                     (dp[t][j - (i - 1) * i / 2] * c[cnt[t]][i]) % MOD) %= MOD;
                }
            }
        }
    }
    printf("%lld\n", dp[len][k]);
    return 0;
}