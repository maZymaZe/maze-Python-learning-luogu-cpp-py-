#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll n, m, k, T, ans;
char ch;
const int NMAX = 66;
ll lin[NMAX], col[NMAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ans = 5;
        ll flag = 0;
        memset(lin, 0, sizeof(lin));
        memset(col, 0, sizeof(col));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> ch;
                if (ch == 'P') {
                    flag = 1;
                    continue;
                }
                ans = min(ans, 4);
                if ((i == 1 || i == n) && (j == 1 || j == m))
                    ans = min(ans, 2);
                lin[i]++, col[j]++;
                if (i == 1 || i == n || j == 1 || j == m)
                    ans = min(ans, 3);
            }
        }
        for (int i = 1; i <= n; i++)
            if (lin[i] == m)
                ans = min(ans, 2);
        if (lin[1] == m || lin[n] == m)
            ans = min(ans, 1);
        for (int i = 1; i <= m; i++)
            if (col[i] == n)
                ans = min(ans, 2);
        if (col[1] == n || col[m] == n)
            ans = min(ans, 1);
        if (!flag)
            ans = 0;
        if (ans == 5)
            cout << "MORTAL" << endl;
        else
            cout << ans << endl;
    }
}