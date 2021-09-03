#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int n, mx = -1000, a[1032];
string mm, p[1032];
map<string, int> m1, m2;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> a[i];
        m2[p[i]] += a[i];
    }
    for (auto x : m2)
        mx = max(mx, x.second);
    for (int i = 1; i <= n; i++) {
        m1[p[i]] += a[i];
        if (m1[p[i]] >= mx && m2[p[i]] == mx) {
            mm = p[i];
            break;
        }
    }
    cout << mm << endl;
    return 0;
}