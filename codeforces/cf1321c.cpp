#include <cstdio>
#include <list>
using namespace std;
const int MAXLEN = 102;
char s[MAXLEN];
int l, ans = 0;
bool flag = false, f2;
list<char> ls;
int main() {
    scanf("%d", &l);
    scanf("%s", s);
    for (int i = 0; i < l; i++)
        ls.push_back(s[i]);
    while (1) {
        flag = true;
        for (char i = 'z'; (i >= 'a') && flag; i--) {
            for (auto p = ls.begin(); p != ls.end(); ++p) {
                if ((*p) != i) {
                    continue;
                }
                auto t = p;
                if (p != ls.begin()) {
                    --t;
                    if ((*p) - (*t) == 1) {
                        p = ls.erase(p);
                        flag = false;
                        break;
                    }
                }
                t = p;
                t++;
                if (t != ls.end()) {
                    if ((*p) - (*t) == 1) {
                        p = ls.erase(p);
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
            break;
    }
    printf("%d\n", l-ls.size());
    return 0;
}