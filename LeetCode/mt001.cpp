#include <iostream>
#include <string>
using namespace std;
int T;
string s;
bool work() {
    cin >> s;
    int ca = 0, cA = 0, c1 = 0;
    if (s[0] >= '0' && s[0] <= '9')
        return false;
    for (char c : s) {
        if (c >= '0' && c <= '9')
            c1++;
        else if (c >= 'a' && c <= 'z')
            ca++;
        else if (c >= 'A' && c <= 'Z')
            cA++;
    }
    return (c1) && (ca || cA) && (c1 + ca + cA == s.size());
}
int main() {
    cin >> T;
    while (T--) {
        cout << (work() ? "Accept" : "Wrong") << endl;
    }
    return 0;
}
