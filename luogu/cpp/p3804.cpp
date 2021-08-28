#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int NMAX = 1e6 + 10;
struct state {
    int len, link, sz;
    map<char, int> nxt;
} st[NMAX << 1];
int sz, last;
void sam_init() {
    st[0].len = 0, st[0].link = -1;
    st[0].sz = 0;
    sz = 1;
    last = 0;
}
void sam_extend(char c) {
    int cur = sz++;
    st[cur].sz = 1;
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
int a[NMAX << 1], c[NMAX << 1];
void sam_sort() {
    for (int i = 1; i < sz; i++)
        c[st[i].len]++;
    for (int i = 1; i < sz; i++)
        c[i] += c[i - 1];
    for (int i = 1; i < sz; i++)
        a[c[st[i].len]--] = i;
}
long long ans = 0;
void sam_calsz() {
    sam_sort();
    for (int i = sz - 1; i >= 1; i--) {
        int now = a[i];
        st[st[now].link].sz += st[now].sz;

        if (st[now].sz > 1)
            ans = max(ans, 1ll * st[now].len * st[now].sz);
    }
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
    cin >> s;
    int l = s.size();
    sam_init();
    for (int i = 0; i < l; i++) {
        sam_extend(s[i]);
    }
    sam_calsz();
    cout << ans << endl;
    return 0;
}
