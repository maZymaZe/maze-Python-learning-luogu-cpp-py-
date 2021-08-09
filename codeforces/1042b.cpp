#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, a[10] = {0}, t, ans;
string s;
int main() {
    cin >> n;
    for (int i = 0; i < 10; i++)
        a[i] = 1e8;
    for (int i = 0; i < n; i++) {
        cin >> t >> s;
        if (s == "A")
            a[1] = min(a[1], t);
        else if (s == "B")
            a[2] = min(a[2], t);
        else if (s == "C")
            a[3] = min(a[3], t);
        sort(s.begin(), s.end());
        if (s == "AB")
            a[4] = min(a[4], t);
        else if (s == "BC")
            a[5] = min(a[5], t);
        else if (s == "AC")
            a[6] = min(a[6], t);
        else if (s == "ABC")
            a[7] = min(a[7], t);
    }
    ans = min(a[1] + a[2] + a[3],
              min(a[5] + a[4],
                  min(a[4] + a[6],
                      min(a[5] + a[6],
                          min(a[1] + a[5],
                              min(a[2] + a[6],
                                  min(a[3] + a[4],
                                      min(a[1] + a[2] + min(a[5], a[6]),
                                          min(a[1] + a[3] + min(a[4], a[5]),
                                              min(a[2] + a[3] + min(a[4], a[6]),
                                                  a[7]))))))))));
    if (ans > 10000000)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}
