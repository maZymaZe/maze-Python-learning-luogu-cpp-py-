#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int NMAX = 2e4 + 10;
struct state {
    int len, link;
    map<char, int> nxt;
} st[NMAX << 1];
int sz, last;
void sam_init() {
    st[0].len = 0, st[0].link = -1;
    st[0].nxt.clear();
    sz = 1;
    last = 0;
}
void sam_clear(int x) {
    st[x].len = 0, st[x].link = 0, st[x].nxt.clear();
}
void sam_extend(char c) {
    int cur = sz++;
    sam_clear(cur);

    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].nxt.count(c)) {
        st[p].nxt[c] = cur;
        p = st[p].link;
    }
    if (p == -1)
        st[cur].link = 0;  // case 1
    else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;  // case 2
        else {
            int clone = sz++;
            sam_clear(clone);
            st[clone].len = st[p].len + 1;
            st[clone].nxt = st[q].nxt;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].nxt[c] == q) {
                st[p].nxt[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
            // case 3
        }
    }
    last = cur;
}
bool CheckSubstring(const string& x) {
    int p = 0, l = x.size();
    for (int i = 0; i < l; i++) {
        if (st[p].nxt.count(x[i])) {
            p = st[p].nxt[x[i]];
        } else
            return false;
    }
    return true;
}
string s;
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int l = s.size();
        sam_init();
        for (int i = 0; i < l; i++) {
            sam_extend(s[i]);
        }
        for (int i = 0; i < l; i++) {
            sam_extend(s[i]);
        }
        int p = 0;
        for (int i = 0; i < l; i++) {
            p = st[p].nxt.begin()->second;
        }
        printf("%d\n", st[p].len - l + 1);
    }
    return 0;
}
