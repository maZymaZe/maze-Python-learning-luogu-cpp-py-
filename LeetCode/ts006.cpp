#include <iostream>
#include <string>
using namespace std;
int isn(char c) {
    return (c >= '0' && c <= '9');
}
string s;
int main() {
    cin >> s;
    s = 'a' + s + 'a';
    int cnt = 0;
    int l = s.length();
    for (int i = 0; i < l - 1; i++) {
        if (isn(s[i]) && !isn(s[i + 1])) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}