#include <iostream>
#include <string>
using namespace std;
string a, b;
long long c[26], ans, n, m;
int main() {
    cin >> n >> m;
    cin >> a >> b;
    for (auto ch : a)
        c[ch - 'a']++;
    int l = 0, r = 0;
    while (r < m) {
        if (c[b[r] - 'a'] >= 0)
            --c[b[r] - 'a'];
        while (c[b[r] - 'a'] < 0 && l <= r) {
            ++c[b[l++] - 'a'];
        }
        ans += 1ll * r - l + 1;
        r++;
    }
    cout << ans << endl;
    return 0;
}