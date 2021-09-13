#include <iostream>
#include <string>
using namespace std;
string s;
int main() {
    int c = 0;
    long long ans = 0;
    while (getline(cin, s)) {
        if (s[0] == '+')
            c++;
        else if (s[0] == '-')
            c--;
        else {
            int l = s.length();
            for (int i = 0; i < l; i++) {
                if (s[i] == ':') {
                    ans += 1ll * c * (l - i - 1);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}