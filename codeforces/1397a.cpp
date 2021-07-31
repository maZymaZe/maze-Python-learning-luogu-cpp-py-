#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int T, n, a[26], b[26];
string s;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);

        memset(b, 0, sizeof(b));
        int flag = 1, t = n;

        while (n--) {
            cin >> s;
            int l2 = s.length();
            for (int i = 0; i < l2; i++) {
                b[s[i] - 'a']++;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (b[i] % t != 0)
                flag = 0;
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}