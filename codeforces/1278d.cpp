#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}
const int NMAX = 5e5 + 10;
struct NODE {
    int l, r;
    bool operator<(const NODE& x) const{
        if (l == x.l)
            return r < x.r;
        else
            return l < x.l;
    }
} node[NMAX];
set<NODE> s;
set<NODE>::iterator it;
int n, f[NMAX], cnt = 0;
int ff(int x) {
    return f[x] == x ? x : f[x] = ff(f[x]);
}
int main() {
    n = Read();
    for (int i = 1; i <= n; i++)
        node[i].l = Read(), node[i].r = Read(), f[i] = i;
    sort(node + 1, node + 1 + n);

    NODE t;
    t.l = node[1].r, t.r = 1;
    s.insert(t);

    for (int i = 2; i <= n; i++) {
        while (1) {
            if (!s.size())
                break;
            t = *s.begin();
            if (t.l <= node[i].l)
                s.erase(s.begin());
            else
                break;
        }
        for (it = s.begin(); it != s.end(); ++it) {
            t = *it;
            if (t.l > node[i].r)
                break;
            if (t.l < node[i].r) {
                int a = ff(t.r), b = ff(i);
                if (a == b) {
                    printf("NO\n");
                    return 0;
                }
                f[a] = b;
            }
        }
        t.l = node[i].r, t.r = i;
        s.insert(t);
    }
    for (int i = 1; i <= n; i++)
        if (f[i] == i)
            cnt++;

    if (cnt == 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
