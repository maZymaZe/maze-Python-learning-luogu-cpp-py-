#include <iostream>
#include <string>
using namespace std;
string s;
string nts(int x) {
    string f;
    int pt = 0, st[100];
    while (x) {
        st[pt++] = (x - 1) % 26 + 1;
        x -= st[pt - 1];
        x /= 26;
    }
    for (int i = pt - 1; i >= 0; i--)
        f += st[i] + 'A' - 1;
    return f;
}
int stn(string x) {
    int r = 0;
    int p = 1;
    int len = x.length();
    for (int i = len - 1; i >= 0; i--) {
        r += p * (x[i] - 'A' + 1);
        p *= 26;
    }
    return r;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int len = s.length();
        if (s[0] == 'R') {
            int ff = 0, nb = 0;
            for (int i = 1; i < len; i++) {
                if (s[i] <= '9' && s[i] >= '0')
                    nb = 1;
                if (s[i] == 'C' && nb) {
                    cout << nts(stoi(s.substr(i + 1, len)))
                         << s.substr(1, i - 1) << endl;
                    ff = 1;
                    break;
                }
            }
            if (ff)
                continue;
        }
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                cout << 'R' << s.substr(i, len) << 'C'
                     << to_string(stn(s.substr(0, i))) << endl;
                break;
            }
        }
    }
    return 0;
}