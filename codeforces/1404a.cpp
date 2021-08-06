#include <iostream>
#include <string>
using namespace std;
int T, n, k, c1, c2, c3;
string s;
int main() {
    cin >> T;
    while (T--) {
        cin >> n >> k >> s;
        c1 = c2 = c3 = 0;
        for (int i = 0; i + k < n; i++) {
            if (s[i] != '?' && s[i + k] == '?')
                s[i + k] = s[i];
            if (s[i] == '?' && s[i + k] != '?')
                s[i] = s[i + k];
        }
        for (int i = n - 1; i - k >= 0; i--) {
            if (s[i] != '?' && s[i - k] == '?')
                s[i - k] = s[i];
            if (s[i] == '?' && s[i - k] != '?')
                s[i] = s[i - k];
        }
        for (int i = 0; i < k; i++) {
            if (s[i] == '0')
                c1++;
            else if (s[i] == '1')
                c2++;
            else
                c3++;
        }
        if (!(c1 <= k / 2 && c1 + c3 >= k / 2)) {
            cout << "NO" << endl;
            continue;
        } else {
            for (int i = 0; i < k; i++) {
                if (s[i] == '?') {
                    if (c1 < k / 2) {
                        c1++;
                        c3--;
                        s[i] = '0';
                    } else if (c2 < k / 2) {
                        c2++;
                        c3--;
                        s[i] = '1';
                    }
                }
            }
        }
        int suc = 1;
        for (int i = k; i < n; i++) {
            if (s[i] != s[i - k]) {
                if (s[i] == '?') {
                    s[i] = s[i - k];
                } else {
                    suc = 0;
                    break;
                }
            }
        }
        if (suc)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}