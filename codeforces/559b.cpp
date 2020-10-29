#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int MAXLEN = 2e5 + 10;
string s, t;
int l;

bool ck(int l1, int l2, int len) {
    return s.substr(l1, len) == t.substr(l2, len);
}
bool cck(int l1, int l2, int len) {
    if (len % 2)
        return s.substr(l1, len) == t.substr(l2, len);
    return (cck(l1, l2 + len / 2, len / 2) && cck(l1 + len / 2, l2, len / 2)) ||
           (cck(l1, l2, len / 2) && cck(l1 + len / 2, l2 + len / 2, len / 2));
}
int main() {
    cin >> s >> t;
    l = s.size();
    bool c = cck(0, 0, l);
    if (c) {
        printf("YES\n");
    } else
        printf("NO\n");
    return 0;
}