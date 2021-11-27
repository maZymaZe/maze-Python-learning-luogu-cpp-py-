#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, ans = 0, mi = 0, sc = 0;
    string s;
    cin >> n >> s;
    for (char i : s) {
        if (i == 'E')
            sc++;
        else
            sc--;
        mi = min(mi, sc);
        ans = max(ans, sc - mi);
    }
    cout << ans << endl;
    return 0;
}