#include <algorithm>
#include <string>
using namespace std;
int main() {
    string s("00110");
    int l = s.size(), c[2] = {0}, bf = 0, ans = 0;
    if (l < 2)
        return 0;
    int pre = s[0] - '0';
    c[pre]++;
    for (int i = 1; i < l; i++) {
        if (s[i] == pre) {
            c[pre]++;
        } else {
            ans += min(bf, c[pre]);
            bf = c[pre];
            c[pre] = 0;
            pre = s[i] - '0';
            c[pre] = 1;
        }
    }
    ans += min(bf, c[pre]);
    return 0;
}