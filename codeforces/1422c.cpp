#include <iostream>
#include <string>
using namespace std;
const long long MOD = 1e9 + 7, NMAX = 1e5 + 10;
long long b[NMAX], a[NMAX];
string s;
int main() {
    cin >> s;
    int len = s.length();
    long long ans = 0;
    a[0] = 1;
    b[0] = 0;
    for (int i = 1; i <= len; i++) {
        a[i] = a[i - 1] * 10 % MOD;
        (b[i] = b[i - 1] + i * a[i - 1]) %= MOD;
    }
    for (int i = 1; i <= len; i++) {
        int pc = i - 1;
        (ans += (long long)(s[i - 1] - '0') * a[len - i] % MOD *
                ((long long)pc * (pc - 1) / 2 + pc) % MOD) %= MOD;
        (ans += (long long)(s[i - 1] - '0') * b[len - i]) %= MOD;
    }
    cout << ans << endl;
    return 0;
}