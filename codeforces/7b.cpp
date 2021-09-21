#include <iostream>
#include <list>
#include <string>
using namespace std;
int f[200], t, n, p = 0, x;
struct SEG {
    int len, uid;
};
string s;
list<SEG> ls;
int main() {
    cin >> t >> n;
    ls.push_back({n, 0});
    for (int i = 0; i < t; i++) {
        cin >> s;
        if (s[0] == 'a') {
            cin >> x;
            int suc = 0;
            for (auto it = ls.begin(); it != ls.end(); ++it) {
                if (it->uid == 0 && it->len >= x) {
                    int lf = it->len - x;
                    printf("%d\n", ++p);
                    it = ls.insert(it, {x, p});
                    ++it;
                    it = ls.erase(it);
                    if (lf)
                        ls.insert(it, {lf, 0});
                    suc = 1;
                    f[p] = 1;
                    break;
                }
            }
            if (!suc) {
                cout << "NULL" << endl;
            }
        } else if (s[0] == 'e') {
            cin >> x;
            if (x > 0 && x < 200 && f[x]) {
                f[x] = 0;
                for (auto it = ls.begin(); it != ls.end(); ++it) {
                    if (it->uid == x) {
                        int nlen = it->len;
                        if (it != ls.begin()) {
                            --it;
                            if (it->uid == 0) {
                                nlen += it->len;
                                it = ls.erase(it);
                            } else
                                ++it;
                        }
                        it = ls.erase(it);
                        if (it != ls.end() && it->uid == 0) {
                            it->len += nlen;
                        } else {
                            ls.insert(it, {nlen, 0});
                        }
                        break;
                    }
                }
            } else {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else {
            int y = 0;
            for (auto it = ls.begin(); it != ls.end();) {
                if (it->uid == 0)
                    y += it->len, it = ls.erase(it);
                else
                    ++it;
            }
            ls.push_back({y, 0});
        }
    }
    return 0;
}
