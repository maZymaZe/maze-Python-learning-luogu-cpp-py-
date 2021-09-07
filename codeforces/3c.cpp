#include <iostream>
#include <string>
using namespace std;
int a[3][3], t[3], sc[3];
string s;
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (int j = 0; j < 3; j++) {
            if (s[j] == 'X')
                a[i][j] = 1;
            else if (s[j] == '0')
                a[i][j] = 2;
            t[a[i][j]]++;
        }
    }
    if (t[1] < t[2] || t[1] > t[2] + 1) {
        cout << "illegal" << endl;
        return 0;
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
        sc[a[0][0]]++;
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
        sc[a[0][2]]++;
    for (int i = 0; i < 3; i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2])
            sc[a[i][0]]++;
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i])
            sc[a[0][i]]++;
    }
    if ((sc[1] && sc[2]) || (sc[1] > 0 && t[1] == t[2]) ||
        (sc[2] > 0 && t[1] > t[2])) {
        cout << "illegal" << endl;
        return 0;
    }
    if (sc[1] > sc[2]) {
        cout << "the first player won" << endl;
        return 0;
    }
    if (sc[1] < sc[2]) {
        cout << "the second player won" << endl;
        return 0;
    }
    if (t[0] == 0) {
        cout << "draw" << endl;
        return 0;
    }
    if (t[1] == t[2]) {
        cout << "first" << endl;
        return 0;
    } else {
        cout << "second" << endl;
        return 0;
    }
    return 0;
}