#include <iostream>
#include <string>
using namespace std;
string s;
int n, l, r;
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            l = i + 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'T') {
            r = i - 1;
            break;
        }
    }
    for (int i = l; i < n; i++) {
        if (s[i] == 'T') {
            l = i + 1;
            for (int j = r; j >= l; j--) {
                if (s[j] == 'M') {
                    r = j - 1;
                    break;
                }
            }
            break;
        }
    }
    cout << s.substr(l, r - l + 1);
    return 0;
}