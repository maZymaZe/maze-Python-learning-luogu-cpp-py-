#include <cstdio>
#include <map>
using namespace std;
const int NMAX = 6e5 + 10;
struct state {
    int len, link;
    map<int, int> nxt;
} st[NMAX << 1];
int sz, last;
void sam_init() {
    st[0].len = 0, st[0].link = -1;
    sz = 1, last = 0;
}
void sam_extend(int x) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p = last;
    while (p != -1 && !st[p].nxt.count(x)) {
        st[p].nxt[x] = cur;
        p = st[p].link;
    }
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].nxt[x];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].nxt = st[q].nxt;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].nxt[x] == q) {
                st[p].nxt[x] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}
int a[NMAX], n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sam_init();
    for (int i = 0; i < n; i++)
        sam_extend(a[i]);
    for (int i = 0; i < n; i++)
        sam_extend(a[i]);
    int p = 0;
    for (int i = 0; i < n; i++) {
        printf("%d ", st[p].nxt.begin()->first);
        p = st[p].nxt.begin()->second;
    }
    return 0;
}
