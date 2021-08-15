#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;
const int NMAX = 1e6 + 10;
long long ans = 0;
struct state {
    int len, link;
    map<int, int> nxt;
} st[NMAX << 1];
int sz, last;
void sam_init() {
    st[0].len = 0, st[0].link = -1;
    sz = 1;
    last = 0;
}
void sam_extend(int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].nxt.count(c)) {
        st[p].nxt[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;  // case 1
        ans += st[cur].len;
    } else {
        int q = st[p].nxt[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;  // case 2
            ans += st[cur].len - st[q].len;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].nxt = st[q].nxt;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].nxt[c] == q) {
                st[p].nxt[c] = clone;
                p = st[p].link;
            }

            st[q].link = st[cur].link = clone;
            ans += st[cur].len - st[clone].len;
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
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    int n, x;
    cin >> n;

    sam_init();
    for (int i = 0; i < n; i++) {
        cin >> x;
        sam_extend(x);
        cout << ans << endl;
    }

    return 0;
}
