#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, mi, ma, m;
string s;
int main() {
    cin >> n >> s;
    m = 150, mi = 300, ma = 0;
    vector<string> ans(400, string(n, '.'));
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            ans[m][i] = '/';
        } else if (s[i] == '-') {
            m--;
            ans[m][i] = '\\';
        } else
            ans[m][i] = '-';
        ma = max(ma, m);
        mi = min(mi, m);
        if (s[i] == '+')
            m++;
    }
    int len = ans.size();
    for (int i = ma; i >= mi; i--)
        cout << ans[i] << endl;
    return 0;
}