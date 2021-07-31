#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int ma, mi, tot, T, tt, n, tg, cnt[300000], c = 0;

string s;
int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &tg);
        cin >> s;

        cnt[0] = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                cnt[i + 1] = cnt[i] + 1;
            else
                cnt[i + 1] = cnt[i] - 1;
        }
        int p = cnt[n];
        if (!p) {
            bool inf = 0;
            for (int i = 0; i <= n; i++) {
                if (cnt[i] == tg) {
                    inf = 1;
                    break;
                }
            }
            printf(inf ? "-1\n" : "0\n");
        } else {
            int ans = (tg == 0);
            for (int i = 1; i <= n; i++) {
                if (1ll * (tg - cnt[i]) * p >= 0 && (tg - cnt[i]) % p == 0)
                    ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}