#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int c[26], n, ls[26];
string a, b;
int main() {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        int l = a.length();
        memset(c, 0, sizeof(c));
        for (int i = 0; i < l; i++) {
            ls[a[i] - 'A'] = i;
            c[a[i] - 'A']++;
        }
        int p = 0;
        for (int i = 0; i < l; i++) {
            while (!c[p])
                p++;
            if (p + 'A' != a[i]) {
                swap(a[ls[p]], a[i]);
                break;
            }
            c[p]--;
        }
        if (a < b) {
            cout << a << endl;
        } else
            cout << "---" << endl;
    }
    return 0;
}