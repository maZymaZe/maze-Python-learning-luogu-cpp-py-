#include <iostream>
#include <string>
using namespace std;
string s[10];
int main() {
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    int c = 0, ans = 0;
    for (int i = 0; i < 8; i++) {
        c = 0;
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == 'B')
                c++;
        }
        ans += (c == 8);
    }
    for (int i = 0; i < 8; i++) {
        c = 0;
        for (int j = 0; j < 8; j++) {
            if (s[j][i] == 'B')
                c++;
        }
        ans += (c == 8);
    }
    if (ans == 16)
        ans = 8;
    cout << ans << endl;
    return 0;
}
