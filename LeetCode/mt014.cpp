#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int NMAX = 40003;
int a[NMAX], b[NMAX], x, y, n;
int main() {
    scanf("%d%d", &x, &y);
    n = x + y;
    string ans(n, '#');
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    if (x > y) {
        nth_element(b + 1, b + x, b + 1 + n);
        for (int i = 0; i < n; i++) {
            if (a[i + 1] <= b[x])
                ans[i] = 'A';
            else
                ans[i] = 'B';
        }
    } else if (y > x) {
        nth_element(b + 1, b + y, b + 1 + n);
        for (int i = 0; i < n; i++) {
            if (a[i + 1] <= b[y])
                ans[i] = 'B';
            else
                ans[i] = 'A';
        }
    } else {
        ans = string(x, 'A') + string(y, 'B');
    }
    cout << ans << endl;
    return 0;
}
