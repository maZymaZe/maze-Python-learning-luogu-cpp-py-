#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int f[256], ans, pre = -1;
string s;
int main() {
    cin >> s;
    int l = s.size();
    ans = 0;
    f['A'] = f['E'] = f['I'] = f['O'] = f['U'] = f['Y'] = 1;
    for (int i = 0; i < l; i++) {
        if (f[s[i]] == 1) {
            pre = i;
            ans = max(pre + 1, ans);
            break;
        }
    }
    if (pre == -1) {
        cout << l+1 << endl;
        return 0;
    }
    for (int i = pre + 1; i < l; i++) {
        if (f[s[i]] == 1) {
            ans = max(ans, i - pre);
            pre = i;
        }
    }
    ans = max(ans, l - pre);
    cout << ans << endl;
    return 0;
}